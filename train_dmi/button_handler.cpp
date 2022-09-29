#include "button_handler.h"

Button_Handler::Button_Handler() : QObject()
{}

void Button_Handler::pontUpClicked()
{
    qDebug() << "Pontograph Up!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_UP, true);
<<<<<<< HEAD
    QObject *obj = rootObject->findChild<QObject*>(VTI_DMI::PONTOGRAPH_UP);
    if(obj->property("state")=="on")
    {
        obj->setProperty("state","off");
    }
    else
    {
        obj->setProperty("state","on");
    }

=======
>>>>>>> 5fdf118bb576aa33b91dbd3db41ae2799dd131d2
    emit sendUpdate(json);
}
