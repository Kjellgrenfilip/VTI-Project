#include "dmi_handler.h"

#include <QJsonObject>

DMI_Handler::DMI_Handler(QQmlContext *rootContext, QObject *obj) : QObject(), m_client{new Network_Client{}},
    m_buttonHandler{new Button_Handler{}}, m_rootObject{obj}, m_jsonState{}
{
    rootContext->setContextProperty("buttonHandler", m_buttonHandler);
    connect(m_buttonHandler, SIGNAL(sendUpdate(QJsonObject)), m_client, SLOT(sendUpdate(QJsonObject)));
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

    foreach(const QString& key, m_jsonState.keys())
    {
        //Update GUI
    }
}


// QObject *obj = rootObject->findChild<QObject*>(VTI_DMI::PONTOGRAPH_UP);
