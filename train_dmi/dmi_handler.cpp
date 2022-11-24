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
void DMI_Handler::d5loghandler(std::vector<Grad_Pos> input, int maxDistance)
{
    double totalPixelHeight = 0;
    double totalDistance = 0;
    double log = 0;
    double lin = 0;
    double linv = 0;
    double logv = 0;
    double v = 0;
    int it = 1;

    for ( int i = 0; i < input.size(); i++ )
    {
        double logv = 0;
        double log = 0;
        double y = input[i].second;

        if ( y <= 0 )
            continue;

        if ( y <= maxDistance / 8 )
        {
            log = y;
            v = toLogScale(log, maxDistance);
        }

        else
        {
            log = maxDistance/8;
            logv = toLogScale(log, maxDistance);
            lin = y - log;
            linv = toLinScale(lin, maxDistance);
            v = linv + logv;
        }



        v -= totalPixelHeight;

        QString objectName = QString::fromStdString("d5bar" + std::to_string(it++));
        QObject *obj = m_rootObject->findChild<QObject*>(objectName);
        obj->setProperty("barValue", v);
        if(v>10)
        {
            obj->setProperty("textValue",abs(input.at(i).first));
            if(input.at(i).first <0)
            {
                //obj->setProperty("color",MyConst.)
            }
        }
        totalPixelHeight += v;
        totalDistance = y;

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

    return logValue;
}

double DMI_Handler::toLinScale(double value, double maxDistance)
{
    double lengthOfLinearPart = 41;
    double divider = 8;
    double factor = maxDistance/divider;
    double result = 0;

    if ( value >= maxDistance )
    {
        result = 3 * lengthOfLinearPart;
        return result;
    }

    for ( int i = 2; i < 16; i*=2 )
    {
        if ( value >= maxDistance/i )
        {
            result += lengthOfLinearPart;
            value -= maxDistance/i;
        }
    }

    if ( value >= 0 )
    {
        result += value * (lengthOfLinearPart/(maxDistance/8));
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
            else
            {
                QString newState = m_latestUpdate.value(key).toString();
                qDebug() << key << " : " << newState;
                obj->setProperty("state", newState);
            }
        }
    }
    d5loghandler(test_vector, 4000);
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
