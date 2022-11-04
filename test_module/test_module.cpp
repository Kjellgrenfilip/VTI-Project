#include "test_module.h"

Test_Module::Test_Module(bool connection)
    : QObject(), m_networkServer{},
      m_jsonBrakes{VTI_DMI::JSON_BRAKES},
      m_jsonDoors{VTI_DMI::JSON_DOORS},
      m_jsonVoltage{VTI_DMI::JSON_VOLTAGE},
      m_jsonAlarm{VTI_DMI::JSON_ALARM},
      m_jsonExtras{VTI_DMI::JSON_EXTRAS},
      m_jsonActivation{VTI_DMI::JSON_ACTIVATION},
      m_doorTimer{new QTimer{this}},
      m_pontUpTimer{new QTimer{this}}
{
    if(connection)
    {
        m_networkServer = new Network_Server();
        connect(m_networkServer, SIGNAL(updateReceived()), this, SLOT(receiveUpdate()));
        connect(m_doorTimer, SIGNAL(timeout()), this, SLOT(doorHandler()));

        m_doorTimer->setSingleShot(true);

        connect(m_pontUpTimer, SIGNAL(timeout()), this, SLOT(pontHandler()));

        m_pontUpTimer->setSingleShot(true);
    }
}

Test_Module::~Test_Module()
{
    delete m_networkServer;
    delete m_doorTimer;
}

void Test_Module::doorHandler()
{
    qDebug() << "TIMER PÅ TRE SEKUNDER KLAR";
    m_jsonDoors.insert(VTI_DMI::DEPARTURE, STATE::INACTIVE);
    m_jsonDoors.insert(VTI_DMI::DOOR_RIGHT, STATE::INACTIVE);
    m_jsonDoors.insert(VTI_DMI::DOOR_LEFT, STATE::INACTIVE);
    m_jsonDoors.insert(VTI_DMI::DOOR_CLOSE, STATE::ACTIVE);

    m_networkServer->sendUpdate(m_jsonDoors);
}

void Test_Module::pontHandler()
{
    if (m_jsonVoltage.value(VTI_DMI::PONTOGRAPH_UP) == STATE::WARNING)
    {
        m_jsonVoltage.insert(VTI_DMI::PONTOGRAPH_UP, STATE::ACTIVE);
        checkVoltage(VTI_DMI::MAIN_BREAKER);
        m_networkServer->sendUpdate(m_jsonVoltage);
    }
}

void Test_Module::checkVoltage(QString const& key)
{
    if(m_jsonVoltage.value(key) == STATE::ACTIVE)
    {
        m_jsonVoltage.insert(VTI_DMI::VOLTAGE_WARNING, STATE::INACTIVE);
        m_jsonVoltage.insert(VTI_DMI::VOLTAGE, STATE::ACTIVE);
    }
}

void Test_Module::updatePontographUp(QJsonValue const & value)
{
    qDebug() << "PONTOGRAPH_UP update" << value;

    if(m_jsonVoltage.value(VTI_DMI::PONTOGRAPH_UP) == STATE::ACTIVE)
    {
        m_jsonVoltage.insert(VTI_DMI::PONTOGRAPH_UP, STATE::WARNING);
        m_pontUpTimer->start(3000); // ACTIVE
    }
    else
    {
        m_jsonVoltage.insert(VTI_DMI::PONTOGRAPH_UP, STATE::WARNING);
        m_pontUpTimer->start(3000); // ACTIVE
        m_jsonVoltage.insert(VTI_DMI::PONTOGRAPH_DOWN, STATE::INACTIVE);
        //checkVoltage(VTI_DMI::MAIN_BREAKER);
    }

     m_networkServer->sendUpdate(m_jsonVoltage);
}

void Test_Module::updatePontographDown(QJsonValue const & value)
{
    qDebug() << "Pontograph down update " << value;

    if(m_jsonVoltage.value(VTI_DMI::PONTOGRAPH_DOWN) == STATE::ACTIVE)
    {
        m_jsonVoltage.insert(VTI_DMI::PONTOGRAPH_DOWN, STATE::INACTIVE);
    }
    else
    {
        m_jsonVoltage.insert(VTI_DMI::PONTOGRAPH_DOWN, STATE::ACTIVE);
        m_jsonVoltage.insert(VTI_DMI::PONTOGRAPH_UP, STATE::INACTIVE);
        m_jsonVoltage.insert(VTI_DMI::VOLTAGE, STATE::DEFAULT);
        m_jsonVoltage.insert(VTI_DMI::VOLTAGE_WARNING, STATE::WARNING);
        m_jsonVoltage.insert(VTI_DMI::HEATING, STATE::INACTIVE);
    }

     m_networkServer->sendUpdate(m_jsonVoltage);
}

void Test_Module::updateMainBreaker(QJsonValue const & value)
{
    qDebug() << "Main breaker update" << value;
    if(m_jsonVoltage.value(VTI_DMI::MAIN_BREAKER) == STATE::ACTIVE)
    {
        m_jsonVoltage.insert(VTI_DMI::MAIN_BREAKER, STATE::INACTIVE);
        m_jsonVoltage.insert(VTI_DMI::VOLTAGE, STATE::DEFAULT);
        m_jsonVoltage.insert(VTI_DMI::VOLTAGE_WARNING, STATE::WARNING);
    }
    else
    {
        m_jsonVoltage.insert(VTI_DMI::MAIN_BREAKER, STATE::ACTIVE);
        checkVoltage(VTI_DMI::PONTOGRAPH_UP);
    }

    m_networkServer->sendUpdate(m_jsonVoltage);
}

void Test_Module::updateHeating(QJsonValue const & value)
{
    qDebug() << "Heating update" << value;

    if(m_jsonVoltage.value(VTI_DMI::HEATING) == STATE::ACTIVE)
    {
        m_jsonVoltage.insert(VTI_DMI::HEATING, STATE::INACTIVE);
    }
    else
    {
        if(m_jsonVoltage.value(VTI_DMI::PONTOGRAPH_UP) == STATE::ACTIVE)
        {
            m_jsonVoltage.insert(VTI_DMI::HEATING, STATE::ACTIVE);
        }
    }

    m_networkServer->sendUpdate(m_jsonVoltage);
}

void Test_Module::updateVelocity(QJsonValue const & value)
{
    qDebug() << "VELOCITY update: " << value;
    m_jsonExtras.insert(VTI_DMI::VELOCITY, value);

    m_networkServer->sendUpdate(m_jsonExtras);
}

void Test_Module::updateVoltage(QJsonValue const & value)
{
    qDebug() << "VOLTAGE update" << value;
    m_jsonVoltage.insert(VTI_DMI::VOLTAGE, value);

    m_networkServer->sendUpdate(m_jsonVoltage);
}

void Test_Module::updateParkBrake(QJsonValue const & value)
{
    qDebug() << "PARKING-BRAKE update" << m_jsonExtras.value(VTI_DMI::VELOCITY).toDouble();

    if(m_jsonBrakes.value(VTI_DMI::PARK_BRAKE) == STATE::DEFAULT  || m_jsonBrakes.value(VTI_DMI::PARK_BRAKE) == STATE::ACTIVE)
        m_jsonBrakes.insert(VTI_DMI::PARK_BRAKE, STATE::INACTIVE);
    else if((m_jsonExtras.value(VTI_DMI::VELOCITY).toDouble() == 0.0) && (m_jsonBrakes.value(VTI_DMI::PARK_BRAKE) == STATE::INACTIVE))
        m_jsonBrakes.insert(VTI_DMI::PARK_BRAKE, STATE::ACTIVE);

    m_networkServer->sendUpdate(m_jsonBrakes);
}


void Test_Module::updateElectrictyBrake(QJsonValue const & value)
{
    qDebug() << "Electricity brake update" << value;

    QString currentState = m_jsonBrakes.value(VTI_DMI::ELECTRICITY_BRAKE).toString();

    if(currentState == STATE::DEFAULT || currentState == STATE::INACTIVE)
        m_jsonBrakes.insert(VTI_DMI::ELECTRICITY_BRAKE, STATE::ACTIVE);
    else
        m_jsonBrakes.insert(VTI_DMI::ELECTRICITY_BRAKE, STATE::INACTIVE);

    m_networkServer->sendUpdate(m_jsonBrakes);
}

void Test_Module::updateMagneticBrake(QJsonValue const & value)
{
    qDebug() << "Magnetic brake update" << value;

    bool updateValue = value.toBool();

    if(updateValue == true)
        m_jsonBrakes.insert(VTI_DMI::MAGNETIC_BRAKE, STATE::ACTIVE);
    else
        m_jsonBrakes.insert(VTI_DMI::MAGNETIC_BRAKE, STATE::INACTIVE);

    m_networkServer->sendUpdate(m_jsonBrakes);
}

void Test_Module::updateEmergencyBrake(QJsonValue const & value)
{
    qDebug() << "Emergency brake update" << value;

    QString currentState = m_jsonAlarm.value(VTI_DMI::EMERGENCY_BRAKE).toString();

    if ( currentState == STATE::DEFAULT )
    {
        m_jsonAlarm.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::WARNING);
        if(m_jsonAlarm.value(VTI_DMI::FIRE) != STATE::WARNING)
        {
            m_jsonAlarm.insert(VTI_DMI::TEXTINFO,"Nödbroms aktiverad");
        }
    }
    else if ( currentState == STATE::WARNING )
        m_jsonAlarm.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::ACTIVE);

    else if ( currentState == STATE::ACTIVE )
        m_jsonAlarm.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::DEFAULT);

    m_networkServer->sendUpdate(m_jsonAlarm);
}

void Test_Module::updateFire(QJsonValue const & value)
{
    qDebug() << "Fire update" << value;

    QString currentState = m_jsonAlarm.value(VTI_DMI::FIRE).toString();

    if ( currentState == STATE::DEFAULT )
    {
        m_jsonAlarm.insert(VTI_DMI::FIRE, STATE::WARNING);
        m_jsonAlarm.insert(VTI_DMI::TEXTINFO,"Brand i tågsätt");
    }

    else if ( currentState == STATE::WARNING )
        m_jsonAlarm.insert(VTI_DMI::FIRE, STATE::ACTIVE);

    else if ( currentState == STATE::ACTIVE )
        m_jsonAlarm.insert(VTI_DMI::FIRE, STATE::DEFAULT);

    m_networkServer->sendUpdate(m_jsonAlarm);
}

void Test_Module::updateReceipt(QJsonValue const & value)
{
    qDebug() << "Receipt update" << value;
    m_jsonAlarm.insert(VTI_DMI::TEXTINFO,"");
    if(m_jsonAlarm.value(VTI_DMI::FIRE) == STATE::WARNING || m_jsonAlarm.value(VTI_DMI::FIRE) == STATE::ACTIVE )
    {
        m_jsonAlarm.insert(VTI_DMI::FIRE, STATE::DEFAULT);
    }
    if(m_jsonAlarm.value(VTI_DMI::EMERGENCY_BRAKE) == STATE::WARNING || m_jsonAlarm.value(VTI_DMI::EMERGENCY_BRAKE) == STATE::ACTIVE)
    {
        m_jsonAlarm.insert(VTI_DMI::EMERGENCY_BRAKE, STATE::DEFAULT);
    }
    m_networkServer->sendUpdate(m_jsonAlarm);
}

void Test_Module::updateReverse(QJsonValue const & value)
{
    qDebug() << "Reverse update" << value;

    QString currentState = m_jsonExtras.value(VTI_DMI::REVERSE).toString();
    double currentVelocity = m_jsonExtras.value(VTI_DMI::VELOCITY).toDouble();

    if ( currentVelocity <= 0.0)
    {
        if ( currentState == STATE::DEFAULT )
            m_jsonExtras.insert(VTI_DMI::REVERSE, STATE::WARNING);

        else if ( currentState == STATE::WARNING )
            m_jsonExtras.insert(VTI_DMI::REVERSE, STATE::DEFAULT);
    }
    m_networkServer->sendUpdate(m_jsonExtras);
}

void Test_Module::updateDoorLeft(QJsonValue const & value)
{
    qDebug() << "Door left update" << value;

    QString currentState = m_jsonDoors.value(VTI_DMI::DOOR_LEFT).toString();

    if ( currentState == STATE::DEFAULT || currentState == STATE::INACTIVE )
    {
        m_jsonDoors.insert(VTI_DMI::DOOR_LEFT, STATE::WARNING);
        m_jsonDoors.insert(VTI_DMI::DOOR_CLOSE, STATE::INACTIVE);
    }
    m_networkServer->sendUpdate(m_jsonDoors);
}

void Test_Module::updateDoorRight(QJsonValue const & value)
{
    qDebug() << "Door right update" << value;

    QString currentState = m_jsonDoors.value(VTI_DMI::DOOR_RIGHT).toString();

    if ( currentState == STATE::DEFAULT || currentState == STATE::INACTIVE )
    {
        m_jsonDoors.insert(VTI_DMI::DOOR_RIGHT, STATE::WARNING);
        m_jsonDoors.insert(VTI_DMI::DOOR_CLOSE, STATE::INACTIVE);
    }
    m_networkServer->sendUpdate(m_jsonDoors);
}

void Test_Module::updateDeparture(QJsonValue const & value)
{
    qDebug() << "Departure update" << value;

    QString currentState = m_jsonDoors.value(VTI_DMI::DEPARTURE).toString();
    QString leftdoorState = m_jsonDoors.value(VTI_DMI::DOOR_LEFT).toString();
    QString rightdoorState = m_jsonDoors.value(VTI_DMI::DOOR_RIGHT).toString();

    if ( currentState == STATE::DEFAULT || currentState == STATE::INACTIVE )
    {
         if( leftdoorState == STATE::WARNING  || rightdoorState == STATE::WARNING )
         {
              m_jsonDoors.insert(VTI_DMI::DEPARTURE, STATE::WARNING);
         }
    }
    m_networkServer->sendUpdate(m_jsonDoors);
}

void Test_Module::updateDoorClose(QJsonValue const & value)
{
    qDebug() << "Door close update" << value;

     QString departureState = m_jsonDoors.value(VTI_DMI::DEPARTURE).toString();

     if (departureState == STATE::WARNING)
     {
         m_jsonDoors.insert(VTI_DMI::DOOR_CLOSE, STATE::WARNING);
         m_doorTimer->start(3000);
     }
     m_networkServer->sendUpdate(m_jsonDoors);
}

void Test_Module::updateLight(QJsonValue const & value)
{
    QString currentState = m_jsonExtras.value(VTI_DMI::LIGHT).toString();
    if (currentState == STATE::DEFAULT)
    {
        m_jsonExtras.insert(VTI_DMI::LIGHT, STATE::WARNING);
    }
    else if (currentState == STATE::WARNING)
    {
        m_jsonExtras.insert(VTI_DMI::LIGHT, STATE::DEFAULT);
    }
    m_networkServer->sendUpdate(m_jsonExtras);
}

void Test_Module::receiveUpdate()
{
    qDebug() << "TESTING";
    QJsonObject update = m_networkServer->getUpdate();
    if ( m_jsonActivation.value(VTI_DMI::ACTIVATE).toString() == STATE::DEFAULT )
    {
        if ( update.value(VTI_DMI::ACTIVATE).toBool() )
        {
            qDebug() << "Activation";
            m_jsonActivation.insert(VTI_DMI::ACTIVATE, STATE::ACTIVE);
            m_networkServer->sendUpdate(m_jsonBrakes);
            m_networkServer->sendUpdate(m_jsonDoors);
            m_networkServer->sendUpdate(m_jsonVoltage);
            m_networkServer->sendUpdate(m_jsonAlarm);
            m_networkServer->sendUpdate(m_jsonExtras);
            m_networkServer->sendUpdate(m_jsonActivation);
        }
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
}

 void Test_Module::resetStates()
 {
     m_jsonBrakes = VTI_DMI::JSON_BRAKES;
     m_jsonDoors = VTI_DMI::JSON_DOORS;
     m_jsonVoltage = VTI_DMI::JSON_VOLTAGE;
     m_jsonAlarm = VTI_DMI::JSON_ALARM;
     m_jsonExtras = VTI_DMI::JSON_EXTRAS;
 }

