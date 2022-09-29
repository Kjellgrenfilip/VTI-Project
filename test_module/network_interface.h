#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include <QJsonObject>
#include <QJsonValue>

namespace VTI_DMI
{
    QString const PONTOGRAPH_UP = "pontograph_up";
    QString const VELOCITY = "velocity";
    QString const VOLTAGE = "voltage";
    QString const NBO = "emergency_brake";
    QString const FIRE = "fire";

    QJsonObject const JSON_TEMPLATE
    {
        {PONTOGRAPH_UP, QJsonValue::Bool},
        {VELOCITY, QJsonValue::Double},
        {VOLTAGE, QJsonValue::Double},
        {NBO, QJsonValue::Bool},
        {FIRE, QJsonValue::Bool}
    };
};

#endif // NETWORK_INTERFACE_H
