#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include <QJsonObject>
#include <QJsonValue>
#include <QString>

namespace STATE
{
    QString const DEFAULT       = "default";
    QString const ACTIVE        = "active";
    QString const INACTIVE      = "inactive";
    QString const WARNING       = "warning";
    QString const BLINKING      = "blinking";
}

namespace VTI_DMI
{
    QString const ACTIVATE          = "activate";
    QString const PROTECTION        = "protection";
    QString const CART              = "cart";
    QString const PONTOGRAPH_UP     = "pontographUp";
    QString const PONTOGRAPH_DOWN   = "pontographDown";
    QString const VELOCITY          = "velocity";
    QString const VOLTAGE           = "voltage";
    QString const EMERGENCY_BRAKE   = "emergencyBrake";
    QString const FIRE              = "fire";
    QString const REVERSE           = "reverse";
    QString const HORN              = "horn";
    QString const PARK_BRAKE        = "parkingBrake";
    QString const ELECTRICITY_BRAKE = "electricityBrake";
    QString const MAGNETIC_BRAKE    = "magneticBrake";
    QString const BRAKE_INDICATOR   = "brakeIndicator";
    QString const MAIN_BREAKER      = "mainBreaker";
    QString const VOLTAGE_WARNING   = "voltageWarning";
    QString const HEATING           = "heating";
    QString const RECEIPT           = "receipt";
    QString const BRAKING           = "braking";
    QString const DOOR_LEFT         = "doorLeft";
    QString const DOOR_RIGHT        = "doorRight";
    QString const DOOR_CLOSE        = "doorClose";
    QString const DEPARTURE         = "departure";

    QJsonObject const JSON_TEMPLATE
    {
        { ACTIVATE,             STATE::DEFAULT },
        { PROTECTION,           STATE::BLINKING },
        { CART,                 STATE::INACTIVE },
        { PONTOGRAPH_UP,        STATE::DEFAULT },
        { VELOCITY,             QJsonValue::Double },
        { VOLTAGE,              STATE::DEFAULT },
        { EMERGENCY_BRAKE,      STATE::DEFAULT },
        { FIRE,                 STATE::DEFAULT },
        { PARK_BRAKE,           STATE::DEFAULT },
        { ELECTRICITY_BRAKE,    STATE::DEFAULT },
        { MAGNETIC_BRAKE,       STATE::DEFAULT },
        { BRAKE_INDICATOR,      STATE::DEFAULT },
        { BRAKING,              QJsonValue::Bool },
        { PONTOGRAPH_DOWN,      STATE::DEFAULT },
        { MAIN_BREAKER,         STATE::DEFAULT },
        { VOLTAGE_WARNING,      STATE::WARNING },
        { HEATING,              STATE::DEFAULT },
        { DOOR_LEFT,            STATE::DEFAULT },
        { DOOR_RIGHT,           STATE::DEFAULT },
        { DOOR_CLOSE,           STATE::DEFAULT },
        { DEPARTURE,            STATE::DEFAULT },
        { REVERSE,              STATE::DEFAULT },
        { HORN,                 STATE::DEFAULT },
        { RECEIPT,              STATE::DEFAULT }
    };
};

#endif // NETWORK_INTERFACE_H
