#include "button_handler.h"

Button_Handler::Button_Handler() : QObject()
{}

// Used by all button functions to send an update to the server.
void Button_Handler::sendSignal(QString const& object, bool const value)
{
    QJsonObject json{};
    json.insert(object, value);
    emit sendUpdate(json);
}

//void Button_Handler::sendSignalMaxDistance(int x)
//{

//}

void Button_Handler::activatePressed()
{
    qDebug() << "Activate";
    sendSignal(VTI_DMI::ACTIVATE, true);
}

void Button_Handler::protectionPressed()
{
    sendSignal(VTI_DMI::PROTECTION, true);
}

void Button_Handler::pantUpPressed()
{
    qDebug() << "Pantograph Up!";
    sendSignal(VTI_DMI::PANTOGRAPH_UP, true);
}

void Button_Handler::parkBrakePressed()
{
    qDebug() << "Park brake pressed!";
    sendSignal(VTI_DMI::PARK_BRAKE, true);
}

void Button_Handler::electricityBrakePressed()
{
    qDebug() << "Electicity brake button pressed!";
    sendSignal(VTI_DMI::ELECTRICITY_BRAKE, true);
}

void Button_Handler::magneticBrakePressed()
{
    qDebug() << "Magnetic brake button pressed!";
    sendSignal(VTI_DMI::MAGNETIC_BRAKE, true);
}

void Button_Handler::magneticBrakeReleased()
{
    qDebug() << "Magnetic brake button released!";
    sendSignal(VTI_DMI::MAGNETIC_BRAKE, false);
}

void Button_Handler::firePressed()
{
    qDebug() << "Fire button pressed!";
    sendSignal(VTI_DMI::FIRE, true);
}

void Button_Handler::pantDownPressed()
{
    qDebug() << "Pantograph Down!";
    sendSignal(VTI_DMI::PANTOGRAPH_DOWN, true);
}

void Button_Handler::mainBreakerPressed()
{
    qDebug() << "Hbryt pressed!";
    sendSignal(VTI_DMI::MAIN_BREAKER, true);
}

void Button_Handler::heatingPressed()
{
    qDebug() << "TAGV pressed!";
    sendSignal(VTI_DMI::HEATING, true);
}

void Button_Handler::emergencyBrakePressed()
{
    qDebug() << "NBO button pressed!";
    sendSignal(VTI_DMI::EMERGENCY_BRAKE, true);
}

void Button_Handler::reversePressed()
{
    qDebug() << "Reverse button pressed!";
    sendSignal(VTI_DMI::REVERSE, true);
}

void Button_Handler::hornPressed()
{
    qDebug() << "HORN button pressed!";
    sendSignal(VTI_DMI::HORN, true);
}

void Button_Handler::leftDoorPressed()
{
    qDebug() << "leftdoor button pressed!";
    sendSignal(VTI_DMI::DOOR_LEFT, true);
}

void Button_Handler::rightDoorPressed()
{
    qDebug() << "rightdoor button pressed!";
    sendSignal(VTI_DMI::DOOR_RIGHT, true);
}

void Button_Handler::departureButtonPressed()
{
    qDebug() << "departure button pressed!";
    sendSignal(VTI_DMI::DEPARTURE, true);
}

void Button_Handler::closeDoorPressed()
{
    qDebug() << "close door button pressed!";
    sendSignal(VTI_DMI::DOOR_CLOSE, true);
}

void Button_Handler::receiptPressed()
{
    qDebug() << "receipt button pressed!";
    sendSignal(VTI_DMI::RECEIPT, true);
}
void Button_Handler::lightPressed()
{
    QJsonObject json{};
    json.insert(VTI_DMI::LIGHT, true);
    emit sendUpdate(json);
}
void Button_Handler::emergencyPressed()
{
    qDebug() << "emergency button pressed!";
}

void Button_Handler::etcsC1Pressed()
{
    qDebug()  << "etcs C1 clicked";
}
void Button_Handler::scaleDownPressed(int x)
{
    if(x>1000)
    {
        emit sendSignalMaxDistance(x/2);
    }
}
void Button_Handler::scaleUpPressed(int x)
{
    if(x<32000)
    {
        emit sendSignalMaxDistance(x*2);
    }
}
