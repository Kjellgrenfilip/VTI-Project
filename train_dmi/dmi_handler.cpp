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
void DMI_Handler::d5loghandler(std::vector<Grad_Pos> input,int scale)
{
    double totallength{0};
    double currentlength{0};
    int iterator = 1;
    double scaleLength = 270;
    double linearLength = 135;
    double logLength = scaleLength - linearLength;
    double log100 = 2;
    double log1000 = 3;

    for(Grad_Pos & x : input)
    {
        if(x.second > 0.0)
        {
            totallength += x.second;
        }
    }

    std::vector<double> lengths;
    double prevPos = 0;
    for(int i = 0; i < 3; i++)
    {
        double currentPos = (input[i].second < 0) ? 0 : input[i].second;
        double nextPos = input[i+1].second;
        double length = nextPos - currentPos;

        if(length > 0.0)
        {
            if ( prevPos < scale/8 && currentPos > scale/8 )
            {
                double log = scale/8 - prevPos;
                length -= log;
                double t = 0;

                t += (log10(log) - log100) / (log1000 - log100) * logLength;
                t += length * (linearLength/(scale - scale/8));
                lengths.push_back(t);

            }

            else
            {
                if ( length + currentlength <= scale/8 )
                    lengths.push_back((log10(length) - log100) / (log1000 - log100) * logLength);
                else if ( length + currentlength <= scale )
                    lengths.push_back(length * (linearLength/(scale - scale/8)));
                else
                    lengths.push_back(scaleLength);
                currentlength += length;
            }
        }
        prevPos = currentPos;
    }

    for(int i = 0; i < lengths.size(); i++)
    {
        qDebug() << lengths[i];
        if(lengths[i] > 0.0)
        {
            QString objectName = QString::fromStdString("d5bar" + std::to_string(i+1));

            QObject *obj = m_rootObject->findChild<QObject*>(objectName);
            obj->setProperty("barValue",lengths[i]);

            if ( lengths[i] > 20 )
                obj->setProperty("textValue", input[i].first);
        }
    }
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
