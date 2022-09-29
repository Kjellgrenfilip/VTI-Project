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
void Button_Handler::pontDownClicked()
{
    qDebug() << "Pontograph Down!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_DOWN, true);
    emit sendUpdate(json);
}
void Button_Handler::hBrytClicked()
{
    qDebug() << "Hbryt pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::HBRYT, true);
    emit sendUpdate(json);
}
void Button_Handler::heatingClicked()
{
    qDebug() << "TAGV pressed!";
    QJsonObject json{};
    json.insert(VTI_DMI::HEATING, true);
    emit sendUpdate(json);
}
//QObject *obj = rootObject->findChild<QObject*>(VTI_DMI::PONTOGRAPH_UP);
