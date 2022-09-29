#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include <QJsonObject>
#include <QJsonValue>

namespace VTI_DMI
{
    QString const PONTOGRAPH_UP = "pontograph_up";
    QString const PONTOGRAPH_DOWN = "pontograph_down";
    QString const VELOCITY = "velocity";
    QString const VOLTAGE = "voltage";
    QString const NBO = "emergency_brake";
    QString const FIRE = "fire";
    QString const HBRYT = "h-bryt";

    QJsonObject const JSON_TEMPLATE
    {
        {PONTOGRAPH_UP,""},
        {VELOCITY, QJsonValue::Double},
        {VOLTAGE, QJsonValue::Double},
        {NBO, QJsonValue::Bool},
        {FIRE, QJsonValue::Bool},
        {PONTOGRAPH_DOWN,""},
        {HBRYT,""}
    };
};

#endif // NETWORK_INTERFACE_H
