#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include <QJsonObject>
#include <QJsonValue>

namespace VTI_DMI
{
    extern QString const PONTOGRAPH_UP = "pontograph up";
    extern QString const BUTTON_2 = "button_2";
    extern QString const VELOCITY = "velocity";
    extern QString const VOLTAGE = "voltage";

    extern QJsonObject const JSON_TEMPLATE
    {
        {PONTOGRAPH_UP, QJsonValue::Bool},
        {BUTTON_2, QJsonValue::Bool},
        {VELOCITY, QJsonValue::Double},
        {VOLTAGE, QJsonValue::Double}
    };
};

#endif // NETWORK_INTERFACE_H
