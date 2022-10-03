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
    QString const PONTOGRAPH_DOWN = "pontograph_down";
    QString const VELOCITY          = "velocity";
    QString const VOLTAGE           = "voltage";
    QString const EMERGENCY_BRAKE   = "emergency_brake";
    QString const FIRE              = "fire";
    QString const PARK_BRAKE        = "parking_brake";
    QString const ELECTRICITY_BRAKE = "electricity_brake";
    QString const MAGNETIC_BRAKE = "magnetic_brake";
    QString const BRAKE_INDICATOR = "brake_indicator";
    QString const HBRYT = "h-bryt";
    QString const SP = "sp";
    QString const HEATING = "heating";
    QString const BREAKING = "breaking";
    QString const DOOR_LEFT = "door_left_button";

    QJsonObject const JSON_TEMPLATE
    {
        { PONTOGRAPH_UP,        STATE::DEFAULT },
        { VELOCITY,             QJsonValue::Double },
        { VOLTAGE,              QJsonValue::Double },
        { EMERGENCY_BRAKE,      STATE::DEFAULT },
        { FIRE,                 STATE::DEFAULT },
        { PARK_BRAKE,           STATE::DEFAULT },
        { ELECTRICITY_BRAKE,    STATE::DEFAULT },
        { MAGNETIC_BRAKE,       STATE::DEFAULT },
        { BRAKE_INDICATOR,      STATE::DEFAULT },
        { BREAKING,             QJsonValue::Bool},
        { PONTOGRAPH_DOWN,""},
        { HBRYT,""},
        { SP,""},
        { HEATING,""},
        { DOOR_LEFT,            STATE::DEFAULT }

    };
};

#endif // NETWORK_INTERFACE_H
