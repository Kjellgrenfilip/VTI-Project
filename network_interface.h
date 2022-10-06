#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include <QJsonObject>
#include <QJsonValue>
#include <QString>

namespace STATE
{
    QString const DEFAULT   = "default";
    QString const ACTIVE    = "active";
    QString const INACTIVE  = "inactive";
    QString const WARNING   = "warning";
}

namespace VTI_DMI
{
    QString const ACTIVATE          = "activate";
    QString const PONTOGRAPH_UP     = "pontograph_up";
    QString const PONTOGRAPH_DOWN   = "pontograph_down";
    QString const VELOCITY          = "velocity";
    QString const VOLTAGE           = "voltage";
    QString const EMERGENCY_BRAKE   = "emergency_brake";
    QString const FIRE              = "fire";
    QString const REVERSE           = "reverse";
    QString const HORN              = "horn";
    QString const PARK_BRAKE        = "parking_brake";
    QString const ELECTRICITY_BRAKE = "electricity_brake";
    QString const MAGNETIC_BRAKE    = "magnetic_brake";
    QString const BRAKE_INDICATOR   = "brake_indicator";
    QString const HBRYT             = "h-bryt";
    QString const SP                = "sp";
    QString const HEATING           = "heating";
    QString const RECEIPT           = "receipt";
    QString const BREAKING          = "breaking";
    QString const DOOR_LEFT         = "door_left_button";
    QString const DOOR_RIGHT        = "door_right_button";
    QString const DOOR_CLOSE        = "door_close_button";
    QString const DEPARTURE         = "departure_button";

    QJsonObject const JSON_TEMPLATE
    {
        { ACTIVATE,             ""},
        { PONTOGRAPH_UP,        "" },
        { VELOCITY,             QJsonValue::Double },
        { VOLTAGE,              QJsonValue::Double }, // should be a double
        { EMERGENCY_BRAKE,      STATE::DEFAULT },
        { FIRE,                 STATE::DEFAULT },
        { PARK_BRAKE,           STATE::DEFAULT },
        { ELECTRICITY_BRAKE,    STATE::DEFAULT },
        { MAGNETIC_BRAKE,       STATE::DEFAULT },
        { BRAKE_INDICATOR,      STATE::DEFAULT },
        { BREAKING,             QJsonValue::Bool },
        { PONTOGRAPH_DOWN,      "" },
        { HBRYT,                "" },
        { SP,                   STATE::WARNING },
        { HEATING,              "" },
        { DOOR_LEFT,            STATE::DEFAULT },
        { DOOR_RIGHT,           STATE::DEFAULT },
        { DOOR_CLOSE,           STATE::DEFAULT },
        { DEPARTURE,            STATE::DEFAULT },
        { REVERSE,              STATE::DEFAULT },
        { HORN,                 STATE::DEFAULT },
        { RECEIPT,              STATE::DEFAULT}
    };
};

#endif // NETWORK_INTERFACE_H
