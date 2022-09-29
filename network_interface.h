#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include <QJsonObject>
#include <QJsonValue>
#include <QString>

namespace STATE
{
    QString const DEFAULT   = "";
    QString const ACTIVE    = "active";
    QString const INACTIVE  = "inactive";
    QString const WARNING   = "warning";
}

namespace VTI_DMI
{
    QString const PONTOGRAPH_UP     = "pontograph_up";
    QString const VELOCITY          = "velocity";
    QString const VOLTAGE           = "voltage";
    QString const EMERGENCY_BRAKE   = "emergency_brake";
    QString const FIRE              = "fire";

    QJsonObject const JSON_TEMPLATE
    {
        { PONTOGRAPH_UP,    STATE::DEFAULT },
        { VELOCITY,         QJsonValue::Double },
        { VOLTAGE,          QJsonValue::Double },
        { EMERGENCY_BRAKE,  STATE::DEFAULT },
        { FIRE,             STATE::DEFAULT }
    };
};

#endif // NETWORK_INTERFACE_H
