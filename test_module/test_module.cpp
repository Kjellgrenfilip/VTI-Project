#include "test_module.h"

Test_Module::Test_Module()
    : QObject(), m_networkServer{new Network_Server{}}, m_jsonState{VTI_DMI::JSON_TEMPLATE}, m_doorTimer{new QTimer{this}}
{
    connect(m_networkServer, SIGNAL(updateReceived()), this, SLOT(receiveUpdate()));
    connect(m_doorTimer, SIGNAL(timeout()), this, SLOT(doorHandler()));

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

void Test_Module::updatePontographUp(QJsonValue const & value)
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

void Test_Module::updatePontographDown(QJsonValue const & value)
{
    qDebug() << "Pontograph down update " << value;

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

void Test_Module::updateMainBreaker(QJsonValue const & value)
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

void Test_Module::updateHeating(QJsonValue const & value)
{
    qDebug() << "Heating update" << value;

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

void Test_Module::updateVelocity(QJsonValue const & value)
{
    qDebug() << "VELOCITY update: " << value;
    m_jsonState.insert(VTI_DMI::VELOCITY, value);
}

void Test_Module::updateVoltage(QJsonValue const & value)
{
    qDebug() << "VOLTAGE update" << value;
    m_jsonState.insert(VTI_DMI::VOLTAGE, value);
}

void Test_Module::updateParkBrake(QJsonValue const & value)
{
    qDebug() << "PARKING-BRAKE update" << m_jsonState.value(VTI_DMI::VELOCITY).toDouble();

    if(m_jsonState.value(VTI_DMI::PARK_BRAKE) == STATE::DEFAULT  || m_jsonState.value(VTI_DMI::PARK_BRAKE) == STATE::ACTIVE)
        m_jsonState.insert(VTI_DMI::PARK_BRAKE, STATE::INACTIVE);
    else if((m_jsonState.value(VTI_DMI::VELOCITY).toDouble() == 0.0) && (m_jsonState.value(VTI_DMI::PARK_BRAKE) == STATE::INACTIVE))
        m_jsonState.insert(VTI_DMI::PARK_BRAKE, STATE::ACTIVE);
}


void Test_Module::updateElectrictyBrake(QJsonValue const & value)
{
    qDebug() << "Electricity brake update" << value;

    QString currentState = m_jsonState.value(VTI_DMI::ELECTRICITY_BRAKE).toString();

    if(currentState == STATE::DEFAULT || currentState == STATE::INACTIVE)
        m_jsonState.insert(VTI_DMI::ELECTRICITY_BRAKE, STATE::ACTIVE);
    else
        m_jsonState.insert(VTI_DMI::ELECTRICITY_BRAKE, STATE::INACTIVE);
}

void Test_Module::updateMagneticBrake(QJsonValue const & value)
{
    qDebug() << "Magnetic brake update" << value;

    bool updateValue = value.toBool();

    if(updateValue == true)
        m_jsonState.insert(VTI_DMI::MAGNETIC_BRAKE, STATE::ACTIVE);
    else
        m_jsonState.insert(VTI_DMI::MAGNETIC_BRAKE, STATE::INACTIVE);
}

void Test_Module::updateEmergencyBrake(QJsonValue const & value)
{
    qDebug() << "Emergency brake update" << value;

    QString currentState = m_jsonState.value(VTI_DMI::EMERGENCY_BRAKE).toString();

    if ( currentState == STATE::DEFAULT )
    {
        m_jsonState.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::WARNING);
        if(m_jsonState.value(VTI_DMI::FIRE) != STATE::WARNING)
        {
            m_jsonState.insert(VTI_DMI::TEXTINFO,"Nödbroms aktiverad");
        }
    }
    else if ( currentState == STATE::WARNING )
        m_jsonState.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::ACTIVE);

    else if ( currentState == STATE::ACTIVE )
        m_jsonState.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::DEFAULT);
}

void Test_Module::updateFire(QJsonValue const & value)
{
    qDebug() << "Fire update" << value;

    QString currentState = m_jsonState.value(VTI_DMI::FIRE).toString();

    if ( currentState == STATE::DEFAULT )
    {
        m_jsonState.insert(VTI_DMI::FIRE, STATE::WARNING);
        m_jsonState.insert(VTI_DMI::TEXTINFO,"Brand i tågsätt");
    }

    else if ( currentState == STATE::WARNING )
        m_jsonState.insert(VTI_DMI::FIRE, STATE::ACTIVE);

    else if ( currentState == STATE::ACTIVE )
        m_jsonState.insert(VTI_DMI::FIRE, STATE::DEFAULT);
}

void Test_Module::updateReceipt(QJsonValue const & value)
{
    qDebug() << "Receipt update" << value;
    m_jsonState.insert(VTI_DMI::TEXTINFO,"");
    if(m_jsonState.value(VTI_DMI::FIRE) == STATE::WARNING || m_jsonState.value(VTI_DMI::FIRE) == STATE::ACTIVE )
    {
        m_jsonState.insert(VTI_DMI::FIRE, STATE::DEFAULT);
    }
    if(m_jsonState.value(VTI_DMI::EMERGENCY_BRAKE) == STATE::WARNING ||m_jsonState.value(VTI_DMI::EMERGENCY_BRAKE) == STATE::ACTIVE)
    {
        m_jsonState.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::DEFAULT);
    }
}

void Test_Module::updateReverse(QJsonValue const & value)
{
    qDebug() << "Reverse update" << value;

    QString currentState = m_jsonState.value(VTI_DMI::REVERSE).toString();
    double currentVelocity = m_jsonState.value(VTI_DMI::VELOCITY).toDouble();

    if ( currentVelocity <= 0.0)
    {
        if ( currentState == STATE::DEFAULT )
            m_jsonState.insert(VTI_DMI::REVERSE, STATE::WARNING);

        else if ( currentState == STATE::WARNING )
            m_jsonState.insert(VTI_DMI::REVERSE, STATE::DEFAULT);
    }
}

void Test_Module::updateDoorLeft(QJsonValue const & value)
{
    qDebug() << "Door left update" << value;

    QString currentState = m_jsonState.value(VTI_DMI::DOOR_LEFT).toString();

    if ( currentState == STATE::DEFAULT || currentState == STATE::INACTIVE )
    {
        m_jsonState.insert(VTI_DMI::DOOR_LEFT, STATE::WARNING);
        m_jsonState.insert(VTI_DMI::DOOR_CLOSE, STATE::INACTIVE);
    }
}

void Test_Module::updateDoorRight(QJsonValue const & value)
{
    qDebug() << "Door right update" << value;

    QString currentState = m_jsonState.value(VTI_DMI::DOOR_RIGHT).toString();

    if ( currentState == STATE::DEFAULT || currentState == STATE::INACTIVE )
    {
        m_jsonState.insert(VTI_DMI::DOOR_RIGHT, STATE::WARNING);
        m_jsonState.insert(VTI_DMI::DOOR_CLOSE, STATE::INACTIVE);
    }
}

void Test_Module::updateDeparture(QJsonValue const & value)
{
    qDebug() << "Departure update" << value;

    QString currentState = m_jsonState.value(VTI_DMI::DEPARTURE).toString();
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

void Test_Module::updateDoorClose(QJsonValue const & value)
{
    qDebug() << "Door close update" << value;

     QString departureState = m_jsonState.value(VTI_DMI::DEPARTURE).toString();

     if (departureState == STATE::WARNING)
     {
         m_jsonState.insert(VTI_DMI::DOOR_CLOSE, STATE::WARNING);
         m_doorTimer->start(3000);
     }
}

void Test_Module::updateLight(QJsonValue const & value)
{
    QString currentState = m_jsonState.value(VTI_DMI::LIGHT).toString();
    if (currentState == STATE::DEFAULT)
    {
        m_jsonState.insert(VTI_DMI::LIGHT, STATE::WARNING);
    }
    else if (currentState == STATE::WARNING)
    {
        m_jsonState.insert(VTI_DMI::LIGHT, STATE::DEFAULT);
    }
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
             updatePontographUp(value);

        else if(key == VTI_DMI::PONTOGRAPH_DOWN)
            updatePontographDown(value);

        else if(key == VTI_DMI::MAIN_BREAKER)
            updateMainBreaker(value);

        else if(key == VTI_DMI::HEATING)
            updateHeating(value);

        else if(key == VTI_DMI::VELOCITY)
            updateVelocity(value);

        else if(key == VTI_DMI::VOLTAGE)
            updateVoltage(value);

        else if(key == VTI_DMI::PARK_BRAKE)
            updateParkBrake(value);

        else if(key == VTI_DMI::ELECTRICITY_BRAKE)
            updateElectrictyBrake(value);

        else if(key == VTI_DMI::MAGNETIC_BRAKE)
            updateMagneticBrake(value);

        else if (key == VTI_DMI::EMERGENCY_BRAKE)
            updateEmergencyBrake(value);

        else if (key == VTI_DMI::FIRE)
            updateFire(value);

        else if(key == VTI_DMI::RECEIPT)
            updateReceipt(value);

        else if ( key == VTI_DMI::REVERSE )
            updateReverse(value);

        else if (key == VTI_DMI::DOOR_LEFT)
            updateDoorLeft(value);

        else if (key == VTI_DMI::DOOR_RIGHT)
            updateDoorRight(value);

       else if (key == VTI_DMI::DEPARTURE)
            updateDeparture(value);

       else if( key== VTI_DMI::DOOR_CLOSE)
            updateDoorClose(value);

        else if ( key == VTI_DMI::LIGHT)
            updateLight(value);
    }
    m_networkServer->sendUpdate(m_jsonState);
}

