#include "dmi_handler.h"
#include <QJsonObject>

DMI_Handler::DMI_Handler(QQmlContext *rootContext, QObject *obj) : QObject(), m_client{new Network_Client{}},
    m_buttonHandler{new Button_Handler{}}, m_rootObject{obj}, m_animationTimer{new QTimer{this}}, m_jsonState{}
{
    rootContext->setContextProperty("buttonHandler", m_buttonHandler);

    connect(m_buttonHandler, SIGNAL(sendUpdate(QJsonObject)), m_client, SLOT(sendUpdate(QJsonObject)));
    connect(m_client, SIGNAL(updateReceived()),this, SLOT(receiveUpdate()));
    connect(m_animationTimer, SIGNAL(timeout()), this, SLOT(animationHandler()));

    m_client->connectToServer();

    m_animationTimer->setInterval(500);
    m_animationTimer->start();
}

DMI_Handler::DMI_Handler(bool testStart) : QObject(), m_client{new Network_Client{}},
    m_buttonHandler{new Button_Handler{}}, m_rootObject{}, m_animationTimer{new QTimer{this}},
    m_jsonState{}, testStart(testStart)
{
    connect(m_buttonHandler, SIGNAL(sendUpdate(QJsonObject)), m_client, SLOT(sendUpdate(QJsonObject)));
    connect(m_client, SIGNAL(updateReceived()),this, SLOT(receiveUpdate()));

    m_client->connectToServer();
}

DMI_Handler::~DMI_Handler()
{
    delete m_client;
    delete m_buttonHandler;
    delete m_animationTimer;
}
void DMI_Handler::d5loghandler(int maxDistance)
{
    double totalPixelHeight = 0;
    double totalDistance = 0;
    double lin = 0;
    double linv = 0;
    double v = 0;
    int it = 1;

    qDebug() << trainPos;

    for ( size_t i = 0; i < m_gradientProfile.size(); i++ )
    {
        double logv = 0;
        double log = 0;
        double y = m_gradientProfile[i].second - trainPos;
        //qDebug() << "distance: " <<  m_gradientProfile[i].second << "-" << trainPos << "=" << y;

        if ( y < 0 )
        {
            continue;
        }

        if(it > 4)
        {
            break;
        }
        if ( y <= maxDistance / 8 )
        {
            log = y;
            v = toLogScale(log, maxDistance);
        }

        else
        {
            log = maxDistance/8;
            logv = toLogScale(log, maxDistance);
            lin = y; //- log;
            linv = toLinScale(lin, maxDistance);
            v = linv + logv;
        }

        //qDebug() << v << " - " << totalPixelHeight << " = " << v - totalPixelHeight;
        //qDebug() << "pixelheight" <<  v - totalPixelHeight;
        //qDebug() << "totalHeight" << totalPixelHeight;
        v -= totalPixelHeight;
        if ( v < 0 )
            v = 0;


        QString objectName = QString::fromStdString("d5bar" + std::to_string(it++));
        QObject *obj = m_rootObject->findChild<QObject*>(objectName); 
        obj->setProperty("barValue", v);
        qDebug() << it-1 << ": " << v;

        if(m_gradientProfile.at(i).first <0)
        {
            obj->setProperty("color", "#555555");
            for ( int j = 1; j < 4; j++ )
            {
                QString textObjectName = objectName + "text" + QString::fromStdString(std::to_string(j));
                QObject *textObj = m_rootObject->findChild<QObject*>(textObjectName);
                textObj->setProperty("color", "#FFFFFF");
            }
        }
        else
        {
            obj->setProperty("color", "#C3C3C3");
            for ( int j = 1; j < 4; j++ )
            {
                QString textObjectName = objectName + "text" + QString::fromStdString(std::to_string(j));
                QObject *textObj = m_rootObject->findChild<QObject*>(textObjectName);
                textObj->setProperty("color", "#000000");
            }

        }

        if(v>20)
        {
            if(m_gradientProfile.at(i).first <0)
                obj->setProperty("upperSign", "-");
            else
                obj->setProperty("upperSign", "+");
        }
        else
            obj->setProperty("upperSign", "");

        if(v>40)
        {
            obj->setProperty("textValue",abs(m_gradientProfile.at(i).first));
        }
        else
            obj->setProperty("textValue", "");


        if(v>60)
        {
            if(m_gradientProfile.at(i).first <0)
                obj->setProperty("lowerSign", "-");
            else
                obj->setProperty("lowerSign", "+");
        }
        else
            obj->setProperty("lowerSign", "");


        totalPixelHeight += v;
    }
    getchar();
    //qDebug() << "it: " << it;

    while ( it <= 4 )
    {
        QString objectName = QString::fromStdString("d5bar" + std::to_string(it++));
        QObject *obj = m_rootObject->findChild<QObject*>(objectName);
        obj->setProperty("barValue", 0);
        obj->setProperty("textValue", "");
        obj->setProperty("lowerSign", "");
        obj->setProperty("upperSign", "");
    }

}

double DMI_Handler::toLogScale(double value, double maxDistance)
{
    double logValue = 0;
    double lengthOfLinearPart = 131;
    double lengthOfLogPart = 131;
    double maxLinear = maxDistance/8;

    if ( value == 0 )
        logValue = 0.0;
    else if ( value > 0.0 && value < 1.0 )
        logValue = 0.0;

    else if ( value >= 1.0 && value <= maxLinear )
    {
        double factor = (log10(value) - log10(maxLinear)) / (log10(maxDistance) - log10(maxLinear));
        logValue = factor * lengthOfLogPart + lengthOfLinearPart;
    }

    else if ( maxLinear < value && value <= maxDistance )
    {
        double factor = value / maxLinear;
        logValue = factor * lengthOfLinearPart;
    }

    if ( logValue < 0 )
        logValue = 0;


    return logValue;
}

double DMI_Handler::toLinScale(double value, double maxDistance)
{
    double lengthOfLinearPart = 41;
    double result = 0;

    if ( value >= maxDistance )
    {
        result = 3 * lengthOfLinearPart;
        return result;
    }

    for ( int i = 4; i >= 1; i/=2 )
    {
        if ( value >= maxDistance/i )
        {
            result += lengthOfLinearPart;
        }
        else
        {
            result += (value - (maxDistance/(i*2))) * (lengthOfLinearPart/(maxDistance/(i*2)));
            break;
        }
    }

    return result;
}


void DMI_Handler::receiveUpdate()
{
    m_latestUpdate = m_client->getUpdate();
    foreach(const QString& key, m_latestUpdate.keys())
    {
        m_jsonState.insert(key, m_latestUpdate.value(key));
        qDebug() << key;
        //Update GUI
        if(!testStart)
        {
            if(key == VTI_DMI::TRAIN_POSITION)
            {
                trainPos = m_latestUpdate.value(key).toDouble();
                d5loghandler(4000);
                continue;
            }

            QObject *obj = m_rootObject->findChild<QObject*>(key);

            if(!obj)
            {
                qDebug() << "Unknown object: " << key;
                continue;
            }

            if ( key == VTI_DMI::VELOCITY )
            {
                // Special case example
            }

            else if ( key == VTI_DMI::SPEEDLIMIT )
            {
                QString newValue = m_latestUpdate.value(key).toString();
                obj->setProperty("text", newValue);
            }

            else if ( key == VTI_DMI::DISTANCE )
            {
                QString distanceStr = m_latestUpdate.value(key).toString();
                obj->setProperty("text", distanceStr);

                obj = m_rootObject->findChild<QObject*>(VTI_DMI::DISTANCE_BAR);
                double distance = distanceStr.toDouble();
                obj->setProperty("barValue", distanceToPixelHeight(distance));
            }

            else if( key == VTI_DMI::TEXTINFO)
            {
                QString newText = m_latestUpdate.value(key).toString();
                obj->setProperty("text", newText);
            }

            if ( key == VTI_DMI::ETCSB3Image || key == VTI_DMI::ETCSB4Image || key == VTI_DMI::ETCSB5Image )
            {
                QString value = m_latestUpdate.value(key).toString();

                QString s = "symbols/Track Conditions/TC_" + value + ".bmp";
                qDebug() << s;
                obj->setProperty("source", s);
            }
            else if (key == VTI_DMI::GRADIENT_PROFILE)
            {
                // Receive gradient profile here :)
            }
            else
            {
                QString newState = m_latestUpdate.value(key).toString();
                qDebug() << key << " : " << newState;
                obj->setProperty("state", newState);
            }
        }
    }
}

void DMI_Handler::animationHandler()
{
    foreach(const QString& key, m_jsonState.keys())
    {
        QString currentState = m_jsonState.value(key).toString();
        if ( currentState == STATE::WARNING || currentState == STATE::BLINKING )
        {
            QObject *image = m_rootObject->findChild<QObject*>(key + "Image");
            if ( image == nullptr )
                continue;

            QObject *imageBlinking = m_rootObject->findChild<QObject*>(key + "ImageBlinking");
            if ( imageBlinking == nullptr )
                continue;

            image->setProperty("visible", animationState);
            imageBlinking->setProperty("visible", !animationState);
            if(key == VTI_DMI::DOOR_CLOSE && !animationState)
            {
                doorCounter++;
                if(doorCounter>3)
                {
                    doorCounter = 0;
                    QJsonObject json{};
                    json.insert(VTI_DMI::RESET_DOORS, true);
                    m_client->sendUpdate(json);
                }
            }
            if ( key == VTI_DMI::PANTOGRAPH_UP && !animationState)
            {
                pantCounter++;
                if(pantCounter>3)
                {
                    pantCounter = 0;
                    QJsonObject json{};
                    json.insert(VTI_DMI::RESET_PANTOGRAPH_UP, true);
                    m_client->sendUpdate(json);
                }
            }
        }
    }

    animationState = !animationState;
}

int DMI_Handler::distanceToPixelHeight(double distance)
{
    double scaleLength{186};
    double linearLength{33};
    double logLength{scaleLength - linearLength};
    double log100{2};
    double log1000{3};
    int pixelHeight{0};

    if ( distance <= 100 )
        pixelHeight = distance * (linearLength/100);
    else if ( distance <= 1000 )
        pixelHeight = linearLength + (log10(distance) - log100) / (log1000 - log100) * logLength;
    else
        pixelHeight = 186;

    return pixelHeight;
}
