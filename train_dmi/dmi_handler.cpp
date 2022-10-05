#include "dmi_handler.h"

#include <QJsonObject>

DMI_Handler::DMI_Handler(QQmlContext *rootContext, QObject *obj) : QObject(), m_client{new Network_Client{}},
    m_buttonHandler{new Button_Handler{}}, m_rootObject{obj}, m_animationTimer{new QTimer{this}}, m_jsonState{}
{
    rootContext->setContextProperty("buttonHandler", m_buttonHandler);

    connect(m_buttonHandler, SIGNAL(sendUpdate(QJsonObject)), m_client, SLOT(sendUpdate(QJsonObject)));
    connect(m_client, SIGNAL(updateReceived()),this, SLOT(receiveUpdate()));

    m_client->connectToServer();


    connect(m_client, SIGNAL(updateReceived()), this, SLOT(receiveUpdate()));
    connect(m_animationTimer, SIGNAL(timeout()), this, SLOT(animationHandler()));

    m_client->connectToServer();

    m_animationTimer->setInterval(1000);
    m_animationTimer->start();
}

DMI_Handler::~DMI_Handler()
{
    delete m_client;
    delete m_buttonHandler;
    delete m_animationTimer;
}

void DMI_Handler::receiveUpdate()
{
    m_jsonState = m_client->getUpdate();


    foreach(const QString& key, m_jsonState.keys())
    {

        //Update GUI
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
        else if ( key == VTI_DMI::VOLTAGE )
        {
            // Special case example
        }
        else if (key == VTI_DMI::BRAKE_INDICATOR)
        {
            qDebug() << "BRAKE_INDICATOR dmi handler";
            if(m_jsonState.value(VTI_DMI::BREAKING) == true)
            {
                obj->setProperty("state", "on");
                qDebug() << "BREAKING = true";
            }
            else
                obj->setProperty("state", "off");

        }
        else
        {
            QString newState = m_jsonState.value(key).toString();
            qDebug() << key << " : " << newState;
            obj->setProperty("state", newState);
            qDebug() << newState;

        }
    }
}



void DMI_Handler::animationHandler()
{
    foreach(const QString& key, m_jsonState.keys())
    {
        QObject *obj = m_rootObject->findChild<QObject*>(key+"_animation");
        if ( obj == nullptr )
            continue;

        QString currentState = m_jsonState.value(key).toString();
        if ( currentState == STATE::WARNING )
        {
            obj->setProperty("running", false);
            obj->setProperty("running", true);
        }
    }
}
