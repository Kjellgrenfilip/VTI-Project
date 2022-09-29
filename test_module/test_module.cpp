#include "test_module.h"

Test_Module::Test_Module()
    : QObject(), m_networkServer{new Network_Server{}}, m_jsonState{VTI_DMI::JSON_TEMPLATE}
{
    connect(m_networkServer, SIGNAL(updateReceived()), this, SLOT(receiveUpdate()));
    m_jsonState.insert(VTI_DMI::VELOCITY, 2.0);
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
        else if(key == VTI_DMI::PARK_BRAKE)
        {
            qDebug() << "PARKING-BRAKE update" << m_jsonState.value(VTI_DMI::PARK_BRAKE);

            if((m_jsonState.value(VTI_DMI::VELOCITY) == 0) && (m_jsonState.value(VTI_DMI::PARK_BRAKE) == "off"))
                m_jsonState.insert(VTI_DMI::PARK_BRAKE, "on");
            else if((m_jsonState.value(VTI_DMI::PARK_BRAKE) == "on"))




            qDebug() << "PARKING-BRAKE update" << m_jsonState.value(VTI_DMI::PARK_BRAKE);

        }
    }

    m_networkServer->sendUpdate(m_jsonState);
}
