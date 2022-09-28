#include "button_handler.h"

Button_Handler::Button_Handler(QObject *parent) : QObject(parent)
{

}

void Button_Handler::pontUpClicked()
{
    qDebug() << "Pontograph Up!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_UP, true);
    emit sendUpdate(json);
}
