#include "test_module.h"

Test_Module::Test_Module()
    : QObject(), m_networkServer{new Network_Server{}}, m_jsonState{VTI_DMI::JSON_TEMPLATE}
{
    connect(m_networkServer, SIGNAL(updateReceived()), this, SLOT(receiveUpdate()));
}

Test_Module::~Test_Module()
{
}

void Test_Module::receiveUpdate()
{
    QJsonObject tmp = m_networkServer->getUpdate();

    foreach(const QString& key, tmp.keys())
    {
        QJsonValue value = tmp.value(key);
        if(key == VTI_DMI::BUTTON_1)
        {
             qDebug() << "BUTTON1 update";
             m_jsonState.insert(key, value);
        }
        if(key == VTI_DMI::BUTTON_2)
        {
             qDebug() << "BUTTON2 update";
             m_jsonState.insert(key, value);
        }
        if(key == VTI_DMI::VELOCITY)
        {
             qDebug() << "VELOCITY update: " << value;
             m_jsonState.insert(key, value);
        }
        if(key == VTI_DMI::VOLTAGE)
        {
            qDebug() << "VOLTAGE update";
            m_jsonState.insert(key, value);
        }
    }

    m_networkServer->sendUpdate(m_jsonState);
}

