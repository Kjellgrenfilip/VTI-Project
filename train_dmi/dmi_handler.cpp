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

    m_animationTimer->setInterval(1000);
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

            else if ( key == VTI_DMI::SPEEDLIMIT || key == VTI_DMI::DISTANCE || key == VTI_DMI::ETCSC3Text)
            {
                QString newValue = m_latestUpdate.value(key).toString();
                obj->setProperty("text", newValue);
            }

            else if ( key == VTI_DMI::DISTANCE_BAR )
            {
                int newValue = m_latestUpdate.value(key).toDouble();
                qDebug() << "DISTANCE: " << newValue;
                obj->setProperty("barValue", newValue);
            }

            else if( key == VTI_DMI::TEXTINFO)
            {
                QString newText = m_latestUpdate.value(key).toString();
                obj->setProperty("text", newText);
            }

            else if ( key == VTI_DMI::ETCSB3Image || key == VTI_DMI::ETCSB4Image
                      || key == VTI_DMI::ETCSB5Image  ||  key == VTI_DMI::ETCSB7Image )
            {
                QString value = m_latestUpdate.value(key).toString();
                QString s;
                if(key == VTI_DMI::ETCSB7Image)
                    s = "symbols/Track Conditions/MO_";
                else
                    s = "symbols/Track Conditions/TC_";
                s = s + value + ".bmp";
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
}

void DMI_Handler::animationHandler()
{
    foreach(const QString& key, m_jsonState.keys())
    {
        QObject *obj = m_rootObject->findChild<QObject*>(key + "Animation");
        if ( obj == nullptr )
            continue;

        QString currentState = m_jsonState.value(key).toString();
        if ( currentState == STATE::WARNING || currentState == STATE::BLINKING )
        {
            obj->setProperty("running", true);
        }
    }
}
