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
             //m_jsonState.insert(key,value);
             if(m_jsonState.value(VTI_DMI::PONTOGRAPH_UP)=="on")
             {
                 m_jsonState.insert(VTI_DMI::PONTOGRAPH_UP,"off");
                 m_jsonState.insert(VTI_DMI::VOLTAGE,0);
                 m_jsonState.insert(VTI_DMI::HEATING,"off");
             }
             else
             {
                 m_jsonState.insert(VTI_DMI::PONTOGRAPH_UP,"on");
                 m_jsonState.insert(VTI_DMI::PONTOGRAPH_DOWN,"off");
                 if(m_jsonState.value(VTI_DMI::HBRYT) == "on")
                 {
                     m_jsonState.insert(VTI_DMI::VOLTAGE,16);
                 }

             }

        }
        else if(key == VTI_DMI::PONTOGRAPH_DOWN)
        {
            if(m_jsonState.value(VTI_DMI::PONTOGRAPH_DOWN)=="on")
            {
                m_jsonState.insert(VTI_DMI::PONTOGRAPH_DOWN,"off");
            }
            else
            {
                m_jsonState.insert(VTI_DMI::PONTOGRAPH_DOWN,"on");
                m_jsonState.insert(VTI_DMI::PONTOGRAPH_UP,"off");
                m_jsonState.insert(VTI_DMI::VOLTAGE,0);
                m_jsonState.insert(VTI_DMI::HEATING,"off");
            }
        }
        else if(key == VTI_DMI::HBRYT)
        {
            qDebug() << "H-bryt update" << value;
            if(m_jsonState.value(VTI_DMI::HBRYT)=="on")
            {
                m_jsonState.insert(VTI_DMI::HBRYT,"off");
                m_jsonState.insert(VTI_DMI::VOLTAGE,0);
                m_jsonState.insert(VTI_DMI::SP,"warning");
            }
            else
            {
                m_jsonState.insert(VTI_DMI::HBRYT,"on");
                m_jsonState.insert(VTI_DMI::SP,"off");
                if(m_jsonState.value(VTI_DMI::PONTOGRAPH_UP)=="on")
                {
                    qDebug() << "should turn on";
                    m_jsonState.insert(VTI_DMI::VOLTAGE,16);
                }
            }
        }
        else if(key == VTI_DMI::HEATING)
        {
            qDebug() << "hello world";
            if(m_jsonState.value(VTI_DMI::HEATING)=="on")
            {
                m_jsonState.insert(VTI_DMI::HEATING,"off");
            }
            else
            {
                if(m_jsonState.value(VTI_DMI::PONTOGRAPH_UP)=="on")
                {
                    qDebug() << "this is great";
                    m_jsonState.insert(VTI_DMI::HEATING,"on");
                }
            }
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

            if(m_jsonState.value(VTI_DMI::PARK_BRAKE) == "" || m_jsonState.value(VTI_DMI::PARK_BRAKE) == "on")
                m_jsonState.insert(VTI_DMI::PARK_BRAKE, "off");
            else if((m_jsonState.value(VTI_DMI::VELOCITY).toDouble() == 0.0) && (m_jsonState.value(VTI_DMI::PARK_BRAKE) == "off"))
                m_jsonState.insert(VTI_DMI::PARK_BRAKE, "on");

            qDebug() << "PARKING-BRAKE update" << m_jsonState.value(VTI_DMI::VELOCITY).toDouble();

        }
        else if(key == VTI_DMI::ELECTRICITY_BRAKE)
        {}


        else if (key == VTI_DMI::FIRE)
        {
            QString currentState = m_jsonState.value(key).toString();

            if ( currentState == STATE::DEFAULT )
                m_jsonState.insert(VTI_DMI::FIRE, STATE::WARNING);

            else if ( currentState == STATE::WARNING )
                m_jsonState.insert(VTI_DMI::FIRE, STATE::ACTIVE);

            else if ( currentState == STATE::ACTIVE )
                m_jsonState.insert(VTI_DMI::FIRE, STATE::DEFAULT);

        }
        else if (key == VTI_DMI::EMERGENCY_BRAKE)
        {
            QString currentState = m_jsonState.value(key).toString();

            if ( currentState == STATE::DEFAULT )
                m_jsonState.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::WARNING);

            else if ( currentState == STATE::WARNING )
                m_jsonState.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::ACTIVE);

            else if ( currentState == STATE::ACTIVE )
                m_jsonState.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::DEFAULT);
        }
    }

    m_networkServer->sendUpdate(m_jsonState);
}
