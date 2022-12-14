#include "dmi_handler.h"
#include <QJsonObject>
#include <QQmlComponent>
#include <QQuickItem>

// Creates a DMI_handler with graphics.
DMI_Handler::DMI_Handler(QQmlContext *rootContext, QObject *obj) : QObject(), m_client{new Network_Client{}},
    m_buttonHandler{new Button_Handler{}}, m_rootObject{obj}, m_animationTimer{new QTimer{this}}, m_jsonState{},
    m_speedometer{new Speedometer{obj}}
{
    rootContext->setContextProperty("buttonHandler", m_buttonHandler);

    connect(m_buttonHandler, SIGNAL(sendUpdate(QJsonObject)), m_client, SLOT(sendUpdate(QJsonObject)));
    connect(m_client, SIGNAL(updateReceived()),this, SLOT(receiveUpdate()));
    connect(m_animationTimer, SIGNAL(timeout()), this, SLOT(animationHandler()));
    connect(m_buttonHandler,SIGNAL(sendSignalMaxDistance(int)),this,SLOT(recieveMaxDistance(int)));
    m_client->connectToServer();

    m_animationTimer->setInterval(500);
    m_animationTimer->start();
}

// Creates a DMI_handler which only has the logical functions initilized, no graphics.
DMI_Handler::DMI_Handler(bool testStart) : QObject(), m_testStart(testStart),
    m_client{new Network_Client{}}, m_buttonHandler{new Button_Handler{}}, m_rootObject{},
    m_animationTimer{new QTimer{this}}, m_jsonState{}
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
    delete m_speedometer;
}

// Is called upon when a update is received by the network handler.
// Processes the update information.
void DMI_Handler::receiveUpdate()
{
    m_latestUpdate = m_client->getUpdate();
    foreach(const QString& key, m_latestUpdate.keys())
    {
        if(key == VTI_DMI::SUPERVISION_STATUS)
        {
            m_speedometer->updateSpeedometer(m_latestUpdate);
            return;
        }
        m_jsonState.insert(key, m_latestUpdate.value(key));

        //Update GUI
        if(!m_testStart)
        {
            QObject *obj = m_rootObject->findChild<QObject*>(key);
            updateGUI(key, obj);
        }
    }
}

// Updates a GUI object determined by key and the value stored in latest_update.
void DMI_Handler::updateGUI(QString const& key, QObject *obj)
{
    if(key == VTI_DMI::TRAIN_POSITION)
    {
        m_trainPos = m_latestUpdate.value(key).toDouble();
        d5loghandler();

        QObject *d7 = m_rootObject->findChild<QObject*>("d7");
        for(int i{4}; i >= 0; --i)
        {
            QString key2 = "PASP";
            obj = m_rootObject->findChild<QObject*>(key2 + QString::number(i));
            QVariant k = obj->property("y");
            double j = 0.3;
            obj->setProperty("y", k.toDouble()+j);

            QString key3 = "d7Collumn" + QString::number(4-i);
            QObject *obj2 = m_rootObject->findChild<QObject*>(key3);
            if(obj2)
            {

                obj2->setProperty("height", obj2->property("height").toDouble()-j);
                if(obj2->property("height").toInt() <= 0.1)
                {
                    obj->setProperty("visible", "false");
                   //  obj2->setProperty("height", d7->property("height"));
                    QString key4 = "d7Collumn" + QString::number(4-i-1);
                    qDebug() << key4;
                    QObject *obj3 = m_rootObject->findChild<QObject*>(key4);
                    if(obj3)
                        obj2->setProperty("height", obj3->property("height"));
                    else
                        obj2->setProperty("height", 0);
                }

            }


        }

        return;
    }

    if(!obj)
    {
        qDebug() << "Unknown object: " << key;
        return;
    }

    if ( key == VTI_DMI::VELOCITY )
    {
        // Special case example
    }

    else if ( key == VTI_DMI::SPEEDLIMIT || key == VTI_DMI::DISTANCE || key == VTI_DMI::ETCSC3Text)
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

    else if ( key == VTI_DMI::ETCSB3Image || key == VTI_DMI::ETCSB4Image
              || key == VTI_DMI::ETCSB5Image  ||  key == VTI_DMI::ETCSB7Image
              || key == VTI_DMI::ETCSC1Image)
    {
        QString value = m_latestUpdate.value(key).toString();
        QString s;
        if(key == VTI_DMI::ETCSB7Image)
            s = "symbols/Track Conditions/MO_";
        else if(key == VTI_DMI::ETCSC1Image)
        {
            s = "symbols/Level/LE_";
        }
        else
            s = "symbols/Track Conditions/TC_";
        s = s + value + ".bmp";
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

// Function that is triggered by a timer, which fires every .5 seconds.
// The animation is done by switching which image in the buttons that is visible.
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

            image->setProperty("visible", m_animationState);
            imageBlinking->setProperty("visible", !m_animationState);
            if(key == VTI_DMI::DOOR_CLOSE && !m_animationState)
            {
                m_doorCounter++;
                if(m_doorCounter>3)
                {
                    m_doorCounter = 0;
                    QJsonObject json{};
                    json.insert(VTI_DMI::RESET_DOORS, true);
                    m_client->sendUpdate(json);
                }
            }
            if ( key == VTI_DMI::PANTOGRAPH_UP && !m_animationState)
            {
                m_pantCounter++;
                if(m_pantCounter>3)
                {
                    m_pantCounter = 0;
                    QJsonObject json{};
                    json.insert(VTI_DMI::RESET_PANTOGRAPH_UP, true);
                    m_client->sendUpdate(json);
                }
            }
        }
    }

    m_animationState = !m_animationState;
}

// Updating the gradient in square D5.
void DMI_Handler::d5loghandler()
{
    double totalPixelHeight = 0;
    double lin = 0;
    double linv = 0;
    double v = 0;
    int it = 1;

    for ( size_t i = 0; i < m_gradientProfile.size(); i++ )
    {
        double logv = 0;
        double log = 0;
        double y = m_gradientProfile[i].second - m_trainPos;

        if ( y < 0 )
        {
            continue;
        }

        if(it > 4)
        {
            break;
        }
        if ( y <= m_maxDistance / 8 )
        {
            log = y;
            v = toLogScale(log);
        }

        else
        {
            log = m_maxDistance/8;
            logv = toLogScale(log);
            lin = y;
            linv = toLinScale(lin);
            v = linv + logv;
        }

        v -= totalPixelHeight;
        if ( v < 0 )
            v = 0;

        QString objectName = QString::fromStdString("d5bar" + std::to_string(it++));
        QObject *obj = m_rootObject->findChild<QObject*>(objectName);
        obj->setProperty("barValue", v);
        obj->setProperty("visible",true);

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

    while ( it <= 4 )
    {
        QString objectName = QString::fromStdString("d5bar" + std::to_string(it++));
        QObject *obj = m_rootObject->findChild<QObject*>(objectName);
        obj->setProperty("barValue", 0);
        obj->setProperty("textValue", "");
        obj->setProperty("lowerSign", "");
        obj->setProperty("upperSign", "");
        obj->setProperty("visible",false);
    }
}

// Conversion from real distance to logarithmic pixel height.
double DMI_Handler::toLogScale(double value)
{
    double logValue = 0;
    double lengthOfLinearPart = 131;
    double lengthOfLogPart = 131;
    double maxLinear = m_maxDistance/8;

    if ( value == 0 )
        logValue = 0.0;
    else if ( value > 0.0 && value < 1.0 )
        logValue = 0.0;

    else if ( value >= 1.0 && value <= maxLinear )
    {
        double factor = (log10(value) - log10(maxLinear)) / (log10(m_maxDistance) - log10(maxLinear));
        logValue = factor * lengthOfLogPart + lengthOfLinearPart;
    }

    else if ( maxLinear < value && value <= m_maxDistance )
    {
        double factor = value / maxLinear;
        logValue = factor * lengthOfLinearPart;
    }

    if ( logValue < 0 )
        logValue = 0;

    return logValue;
}

// Conversion from real distance to linear pixel height.
double DMI_Handler::toLinScale(double value)
{
    double lengthOfLinearPart = 41;
    double result = 0;

    if ( value >= m_maxDistance )
    {
        result = 3 * lengthOfLinearPart;
        return result;
    }

    for ( int i = 4; i >= 1; i/=2 )
    {
        if ( value >= m_maxDistance/i )
        {
            result += lengthOfLinearPart;
        }
        else
        {
            result += (value - (m_maxDistance/(i*2))) * (lengthOfLinearPart/(m_maxDistance/(i*2)));
            break;
        }
    }

    return result;
}


// Converts the real distance to pixel height of the distance bar in A3.

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

// Sets the max distance/scale of the D5 profile
void DMI_Handler::recieveMaxDistance(int x)
{
    m_maxDistance = x;
    QObject *obj = m_rootObject->findChild<QObject*>("D1");
    obj->setProperty("scale",x);
    d5loghandler();
}
