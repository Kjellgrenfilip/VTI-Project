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

//QObject *obj = rootObject->findChild<QObject*>(VTI_DMI::PONTOGRAPH_UP);
