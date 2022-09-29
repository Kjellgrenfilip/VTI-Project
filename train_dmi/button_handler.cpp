#include "button_handler.h"

Button_Handler::Button_Handler(QObject *obj) : QObject(), rootObject{obj}
{

}

void Button_Handler::pontUpClicked()
{
    qDebug() << "Pontograph Up!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_UP, true);
    QObject *obj = rootObject->findChild<QObject*>(VTI_DMI::PONTOGRAPH_UP);
    emit sendUpdate(json);
}
