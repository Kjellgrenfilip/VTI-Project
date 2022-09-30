#include "dmi_handler.h"

#include <QJsonObject>

DMI_Handler::DMI_Handler(QQmlContext *rootContext, QObject *obj) : QObject(), m_client{new Network_Client{}},
    m_buttonHandler{new Button_Handler{}}, m_rootObject{obj}, m_jsonState{}
{
    rootContext->setContextProperty("buttonHandler", m_buttonHandler);
    connect(m_buttonHandler, SIGNAL(sendUpdate(QJsonObject)), m_client, SLOT(sendUpdate(QJsonObject)));
    connect(m_client, SIGNAL(updateReceived()),this, SLOT(receiveUpdate()));

    m_client->connectToServer();

}

DMI_Handler::~DMI_Handler()
{
    delete m_client;
    delete m_buttonHandler;
}

void DMI_Handler::receiveUpdate()
{
    m_jsonState = m_client->getUpdate();
    qDebug() << "Kommer in i funktionern";

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
            double newState = m_jsonState.value(key).toDouble();
            obj->setProperty("text", newState);
            qDebug() << newState;
        }
        else
        {
            QString newState = m_jsonState.value(key).toString();
            obj->setProperty("state", newState);
            qDebug() << newState;

        }
    }
}



