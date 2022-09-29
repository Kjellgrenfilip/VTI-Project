#include "test_module.h"

Test_Module::Test_Module()
    : QObject(), m_networkServer{new Network_Server{}}, m_jsonState{VTI_DMI::JSON_TEMPLATE}
{
    connect(m_networkServer, SIGNAL(updateReceived()), this, SLOT(receiveUpdate()));
}

Test_Module::~Test_Module()
{
    delete m_networkServer;
}

void Test_Module::receiveUpdate()
{
    QJsonObject tmp = m_networkServer->getUpdate();

    foreach(const QString& key, tmp.keys())
    {
        QJsonValue value = tmp.value(key);
        if(key == VTI_DMI::PONTOGRAPH_UP)
        {
             qDebug() << "PONTOGRAPH_UP update" << value;
             m_jsonState.insert(key, value);
        }
        else if(key == VTI_DMI::VELOCITY)
        {
             qDebug() << "VELOCITY update: " << value;
             m_jsonState.insert(key, value);
        }
        else if(key == VTI_DMI::VOLTAGE)
        {
            qDebug() << "VOLTAGE update" << value;
            m_jsonState.insert(key, value);
        }
        else if (key == VTI_DMI::FIRE)
        {
            qDebug() << "FIRE update" << value;
            m_jsonState.insert(key, "active");
        }
    }

    m_networkServer->sendUpdate(m_jsonState);
}
