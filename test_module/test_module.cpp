#include "test_module.h"

Test_Module::Test_Module()
    : QObject(), m_networkServer{new Network_Server{}}, m_jsonState{VTI_DMI::JSON_TEMPLATE}, m_doorTimer{new QTimer{this}}
{
    connect(m_networkServer, SIGNAL(updateReceived()), this, SLOT(receiveUpdate()));
    connect(m_doorTimer, SIGNAL(timeout()), this, SLOT(doorHandler()));

   // m_doorTimer->setInterval(3000);
    m_doorTimer->setSingleShot(true);
}

Test_Module::~Test_Module()
{
    delete m_networkServer;
    delete m_doorTimer;
}
void Test_Module::doorHandler()
{
    qDebug() << "TIMER PÅ TRE SEKUNDER KLAR";
    m_jsonState.insert(VTI_DMI::DEPARTURE, STATE::INACTIVE);
    m_jsonState.insert(VTI_DMI::DOOR_RIGHT, STATE::INACTIVE);
    m_jsonState.insert(VTI_DMI::DOOR_LEFT, STATE::INACTIVE);
    m_jsonState.insert(VTI_DMI::DOOR_CLOSE, STATE::ACTIVE);
    m_networkServer->sendUpdate(m_jsonState);

}

void Test_Module::receiveUpdate()
{
    QJsonObject update = m_networkServer->getUpdate();
    if ( m_jsonState.value(VTI_DMI::ACTIVATE).toString() == STATE::DEFAULT )
    {
        if ( update.value(VTI_DMI::ACTIVATE).toBool() )
            m_jsonState.insert(VTI_DMI::ACTIVATE, STATE::ACTIVE);
        else
            return;
    }

    foreach(const QString& key, update.keys())
    {
        QJsonValue value = update.value(key);

        if(key == VTI_DMI::PONTOGRAPH_UP)
        {
             qDebug() << "PONTOGRAPH_UP update" << value;

             if(m_jsonState.value(VTI_DMI::PONTOGRAPH_UP) == STATE::ACTIVE)
             {
                 m_jsonState.insert(VTI_DMI::PONTOGRAPH_UP, STATE::INACTIVE);
                 m_jsonState.insert(VTI_DMI::VOLTAGE, STATE::DEFAULT);
                 m_jsonState.insert(VTI_DMI::HEATING, STATE::INACTIVE);
             }
             else
             {
                 m_jsonState.insert(VTI_DMI::PONTOGRAPH_UP, STATE::ACTIVE);
                 m_jsonState.insert(VTI_DMI::PONTOGRAPH_DOWN, STATE::INACTIVE);
                 if(m_jsonState.value(VTI_DMI::MAIN_BREAKER) == STATE::ACTIVE)
                 {
                     m_jsonState.insert(VTI_DMI::VOLTAGE, STATE::ACTIVE);
                 }
             }
        }

        else if(key == VTI_DMI::PONTOGRAPH_DOWN)
        {
            if(m_jsonState.value(VTI_DMI::PONTOGRAPH_DOWN) == STATE::ACTIVE)
            {
                m_jsonState.insert(VTI_DMI::PONTOGRAPH_DOWN, STATE::INACTIVE);
            }
            else
            {
                m_jsonState.insert(VTI_DMI::PONTOGRAPH_DOWN, STATE::ACTIVE);
                m_jsonState.insert(VTI_DMI::PONTOGRAPH_UP, STATE::INACTIVE);
                m_jsonState.insert(VTI_DMI::VOLTAGE, STATE::DEFAULT);
                m_jsonState.insert(VTI_DMI::HEATING, STATE::INACTIVE);
            }
        }

        else if(key == VTI_DMI::MAIN_BREAKER)
        {
            qDebug() << "Main breaker update" << value;
            if(m_jsonState.value(VTI_DMI::MAIN_BREAKER) == STATE::ACTIVE)
            {
                m_jsonState.insert(VTI_DMI::MAIN_BREAKER, STATE::INACTIVE);
                m_jsonState.insert(VTI_DMI::VOLTAGE, STATE::DEFAULT);
                m_jsonState.insert(VTI_DMI::VOLTAGE_WARNING, STATE::WARNING);
            }
            else
            {
                m_jsonState.insert(VTI_DMI::MAIN_BREAKER, STATE::ACTIVE);
                m_jsonState.insert(VTI_DMI::VOLTAGE_WARNING, STATE::INACTIVE);
                if(m_jsonState.value(VTI_DMI::PONTOGRAPH_UP) == STATE::ACTIVE)
                {
                    qDebug() << "should turn on";
                    m_jsonState.insert(VTI_DMI::VOLTAGE, STATE::ACTIVE);
                }
            }
        }

        else if(key == VTI_DMI::HEATING)
        {
            if(m_jsonState.value(VTI_DMI::HEATING) == STATE::ACTIVE)
            {
                m_jsonState.insert(VTI_DMI::HEATING, STATE::INACTIVE);
            }
            else
            {
                if(m_jsonState.value(VTI_DMI::PONTOGRAPH_UP) == STATE::ACTIVE)
                {
                    m_jsonState.insert(VTI_DMI::HEATING, STATE::ACTIVE);
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

            if(m_jsonState.value(VTI_DMI::PARK_BRAKE) == STATE::DEFAULT  || m_jsonState.value(VTI_DMI::PARK_BRAKE) == STATE::ACTIVE)
                m_jsonState.insert(VTI_DMI::PARK_BRAKE, STATE::INACTIVE);
            else if((m_jsonState.value(VTI_DMI::VELOCITY).toDouble() == 0.0) && (m_jsonState.value(VTI_DMI::PARK_BRAKE) == STATE::INACTIVE))
                m_jsonState.insert(VTI_DMI::PARK_BRAKE, STATE::ACTIVE);

            qDebug() << "PARKING-BRAKE update" << m_jsonState.value(VTI_DMI::VELOCITY).toDouble();

        }
        else if(key == VTI_DMI::ELECTRICITY_BRAKE)
        {
            QString currentState = m_jsonState.value(key).toString();

            if(currentState == STATE::DEFAULT || currentState == STATE::INACTIVE)
                m_jsonState.insert(VTI_DMI::ELECTRICITY_BRAKE, STATE::ACTIVE);
            else
                m_jsonState.insert(VTI_DMI::ELECTRICITY_BRAKE, STATE::INACTIVE);
        }

        else if(key == VTI_DMI::MAGNETIC_BRAKE)
        {
            QString currentState = m_jsonState.value(key).toString();
            bool updateValue = value.toBool();

            if(updateValue == true)
                m_jsonState.insert(VTI_DMI::MAGNETIC_BRAKE, STATE::ACTIVE);
            else
                m_jsonState.insert(VTI_DMI::MAGNETIC_BRAKE, STATE::INACTIVE);
        }

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

        else if(key == VTI_DMI::RECEIPT)
        {
            QString currentState = m_jsonState.value(key).toString();
        }

        else if ( key == VTI_DMI::REVERSE )
        {
            QString currentState = m_jsonState.value(key).toString();
            double currentVelocity = m_jsonState.value(VTI_DMI::VELOCITY).toDouble();

            if ( currentVelocity <= 0.0)
            {
                if ( currentState == STATE::DEFAULT )
                    m_jsonState.insert(VTI_DMI::REVERSE, STATE::WARNING);

                else if ( currentState == STATE::WARNING )
                    m_jsonState.insert(VTI_DMI::REVERSE, STATE::DEFAULT);
            }
        }

        else if (key == VTI_DMI::DOOR_LEFT)
        {
            QString currentState = m_jsonState.value(key).toString();

            if ( currentState == STATE::DEFAULT || currentState == STATE::INACTIVE )
            {
                m_jsonState.insert(VTI_DMI::DOOR_LEFT, STATE::WARNING);
                m_jsonState.insert(VTI_DMI::DOOR_CLOSE, STATE::INACTIVE);
            }
        }

        else if (key == VTI_DMI::DOOR_RIGHT)
        {
           QString currentState = m_jsonState.value(key).toString();

           if ( currentState == STATE::DEFAULT || currentState == STATE::INACTIVE )

           {
               m_jsonState.insert(VTI_DMI::DOOR_RIGHT, STATE::WARNING);
               m_jsonState.insert(VTI_DMI::DOOR_CLOSE, STATE::INACTIVE);
           }
       }

       else if (key == VTI_DMI::DEPARTURE)
       {
           QString currentState = m_jsonState.value(key).toString();
           QString leftdoorState = m_jsonState.value(VTI_DMI::DOOR_LEFT).toString();
           QString rightdoorState = m_jsonState.value(VTI_DMI::DOOR_RIGHT).toString();

           if ( currentState == STATE::DEFAULT || currentState == STATE::INACTIVE )
           {
                if( leftdoorState == STATE::WARNING  || rightdoorState == STATE::WARNING )
                {
                     m_jsonState.insert(VTI_DMI::DEPARTURE, STATE::WARNING);
                }
            }
       }

       else if( key== VTI_DMI::DOOR_CLOSE)
       {
            QString currentState = m_jsonState.value(key).toString();
            QString departureState = m_jsonState.value(VTI_DMI::DEPARTURE).toString();
            QString leftdoorState = m_jsonState.value(VTI_DMI::DOOR_LEFT).toString();
            QString rightdoorState = m_jsonState.value(VTI_DMI::DOOR_RIGHT).toString();

            if (departureState == STATE::WARNING)
            {
                m_jsonState.insert(VTI_DMI::DOOR_CLOSE, STATE::WARNING);
                m_doorTimer->start(3000);
            }
        }
    }
    m_networkServer->sendUpdate(m_jsonState);
}

