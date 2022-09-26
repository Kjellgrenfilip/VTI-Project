#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include <QJsonObject>
#include <QJsonValue>

namespace VTI_DMI
{
    QString const BUTTON_1 = "button_1";
    QString const BUTTON_2 = "button_2";
    QString const VELOCITY = "velocity";
    QString const VOLTAGE = "voltage";


    QJsonObject const JSON_TEMPLATE
    {
        {BUTTON_1, QJsonValue::Bool},
        {BUTTON_2, QJsonValue::Bool},
        {VELOCITY, QJsonValue::Double},
        {VOLTAGE, QJsonValue::Double}
    };
};

#endif // NETWORK_INTERFACE_H
