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

void Button_Handler::pontUpClicked()
{
    qDebug() << "Pontograph Up!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_UP, true);    
    emit sendUpdate(json);
}

void Button_Handler::parkBrakeClicked()
{
    qDebug() << "Park brake pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::PARK_BRAKE, true);
    emit sendUpdate(json);
}

void Button_Handler::electricityBrakeClicked()
{
    qDebug() << "Electicity brake button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::ELECTRICITY_BRAKE, true);
    emit sendUpdate(json);
}

void Button_Handler::magneticBrakeClicked()
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

void Button_Handler::fireClicked()
{
    qDebug() << "Fire button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::FIRE, true);
    emit sendUpdate(json);
}

void Button_Handler::pontDownClicked()
{
    qDebug() << "Pontograph Down!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_DOWN, true);
    emit sendUpdate(json);
}

void Button_Handler::mainBreakerClicked()
{
    qDebug() << "Hbryt pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::MAIN_BREAKER, true);
    emit sendUpdate(json);
}

void Button_Handler::heatingClicked()
{
    qDebug() << "TAGV pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::HEATING, true);
    emit sendUpdate(json);
}

void Button_Handler::nboClicked()
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

void Button_Handler::leftDoorClicked()
{
    qDebug() << "leftdoor button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::DOOR_LEFT, true);
    emit sendUpdate(json);
}

void Button_Handler::rightDoorClicked()
{
    qDebug() << "rightdoor button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::DOOR_RIGHT, true);
    emit sendUpdate(json);
}

void Button_Handler::departureButtonClicked()
{
    qDebug() << "departure button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::DEPARTURE, true);
    emit sendUpdate(json);
}

void Button_Handler::closeDoorClicked()
{
    qDebug() << "close door button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::DOOR_CLOSE, true);
    emit sendUpdate(json);
}

void Button_Handler::receiptClicked()
{
    qDebug() << "receipt button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::RECEIPT, true);
    emit sendUpdate(json);
}
void Button_Handler::lightPressed()
{
    QJsonObject json{};
    json.insert(VTI_DMI::LIGHT, true);
    emit sendUpdate(json);
}
