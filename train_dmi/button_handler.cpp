#include "button_handler.h"

Button_Handler::Button_Handler() : QObject()
{}

void Button_Handler::activatePressed()
{
    qDebug() << "Activate";
    QJsonObject json{};
    json.insert(VTI_DMI::ACTIVATE, true);
    emit sendUpdate(json);
}

void Button_Handler::pontUpPressed()
{
    qDebug() << "Pontograph Up!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_UP, true);    
    emit sendUpdate(json);
}

void Button_Handler::parkBrakePressed()
{
    qDebug() << "Park brake pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::PARK_BRAKE, true);
    emit sendUpdate(json);
}

void Button_Handler::electricityBrakePressed()
{
    qDebug() << "Electicity brake button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::ELECTRICITY_BRAKE, true);
    emit sendUpdate(json);
}

void Button_Handler::magneticBrakePressed()
{
    qDebug() << "Magnetic brake button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::MAGNETIC_BRAKE, true);
    emit sendUpdate(json);
}

void Button_Handler::magneticBrakeReleased()
{
    qDebug() << "Magnetic brake button released!";
    QJsonObject json{};
    json.insert(VTI_DMI::MAGNETIC_BRAKE, false);
    emit sendUpdate(json);
}

void Button_Handler::firePressed()
{
    qDebug() << "Fire button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::FIRE, true);
    emit sendUpdate(json);
}

void Button_Handler::pontDownPressed()
{
    qDebug() << "Pontograph Down!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_DOWN, true);
    emit sendUpdate(json);
}

void Button_Handler::mainBreakerPressed()
{
    qDebug() << "Hbryt pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::MAIN_BREAKER, true);
    emit sendUpdate(json);
}

void Button_Handler::heatingPressed()
{
    qDebug() << "TAGV pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::HEATING, true);
    emit sendUpdate(json);
}

void Button_Handler::nboPressed()
{
    qDebug() << "NBO button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::EMERGENCY_BRAKE, true);
    emit sendUpdate(json);
}

void Button_Handler::reversePressed()
{
    qDebug() << "Reverse button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::REVERSE, true);
    emit sendUpdate(json);
}

void Button_Handler::hornPressed()
{
    qDebug() << "HORN button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::HORN, true);
    emit sendUpdate(json);
}

void Button_Handler::leftDoorPressed()
{
    qDebug() << "leftdoor button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::DOOR_LEFT, true);
    emit sendUpdate(json);
}

void Button_Handler::rightDoorPressed()
{
    qDebug() << "rightdoor button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::DOOR_RIGHT, true);
    emit sendUpdate(json);
}

void Button_Handler::departureButtonPressed()
{
    qDebug() << "departure button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::DEPARTURE, true);
    emit sendUpdate(json);
}

void Button_Handler::closeDoorPressed()
{
    qDebug() << "close door button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::DOOR_CLOSE, true);
    emit sendUpdate(json);
}

void Button_Handler::receiptPressed()
{
    qDebug() << "receipt button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::RECEIPT, true);
    emit sendUpdate(json);
}

