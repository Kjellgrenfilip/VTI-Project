#include "button_handler.h"

Button_Handler::Button_Handler() : QObject()
{}

void Button_Handler::pontUpClicked()
{
    qDebug() << "Pontograph Up!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_UP, true);    
    emit sendUpdate(json);
}

void Button_Handler::fireClicked()
{
    qDebug() << "Fire button pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::FIRE, true);
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

}

//QObject *obj = rootObject->findChild<QObject*>(VTI_DMI::PONTOGRAPH_UP);
