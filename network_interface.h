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
    QString const PANTOGRAPH_UP     = "pantographUp";
    QString const PANTOGRAPH_DOWN   = "pantographDown";
    QString const RESET_PANTOGRAPH_UP = "resetPantographUp";
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
    QString const TEXTINFO          = "textAreaInfoText";
    QString const LIGHT             = "light";
    QString const EMERGENCY_CALL    = "emergencyCall";
    QString const SPEEDLIMIT        = "LSSMAText";
    QString const SPEEDLIMIT_STATE  = "LSSMA";
    QString const DISTANCE          = "distanceText";
    QString const DISTANCE_STATE    = "distance";
    QString const DISTANCE_BAR      = "distanceBarValue";
    QString const DISTANCE_BAR_STATE= "distanceBar";
    QString const ETCSB3            = "etcsB3";
    QString const ETCSB4            = "etcsB4";
    QString const ETCSB5            = "etcsB5";
    QString const ETCSB6            = "etcsB6";
    QString const ETCSB7            = "etcsB7";
    QString const ETCSB3Image       = "etcsB3Image";
    QString const ETCSB4Image       = "etcsB4Image";
    QString const ETCSB5Image       = "etcsB5Image";
    QString const ETCSB7Image       = "etcsB7Image";
    QString const ETCSC6            = "etcsC6";
    QString const ETCSC1Image       = "etcsC1Image";
    QString const ETCSC3Text        = "etcsC3Text";

    QString const RESET_DOORS       = "resetDoors";

    QJsonObject const JSON_BRAKES
    {
        { PARK_BRAKE,           STATE::DEFAULT },
        { ELECTRICITY_BRAKE,    STATE::DEFAULT },
        { MAGNETIC_BRAKE,       STATE::DEFAULT },
        { BRAKE_INDICATOR,      STATE::DEFAULT },
        { BRAKING,              QJsonValue::Bool }
    };

    QJsonObject const JSON_DOORS
    {
        { DOOR_LEFT,            STATE::DEFAULT },
        { DOOR_RIGHT,           STATE::DEFAULT },
        { DOOR_CLOSE,           STATE::DEFAULT },
        { DEPARTURE,            STATE::DEFAULT }

    };

    QJsonObject const JSON_VOLTAGE
    {
        { VOLTAGE,              STATE::DEFAULT },
        { PANTOGRAPH_UP,        STATE::DEFAULT },
        { PANTOGRAPH_DOWN,      STATE::DEFAULT },
        { MAIN_BREAKER,         STATE::DEFAULT },
        { VOLTAGE_WARNING,      STATE::WARNING },
        { HEATING,              STATE::DEFAULT }
    };

    QJsonObject const JSON_ALARM
    {
        { EMERGENCY_BRAKE,      STATE::DEFAULT },
        { FIRE,                 STATE::DEFAULT },
        { RECEIPT,              STATE::DEFAULT },
        { TEXTINFO,             QJsonValue::String }
    };

    QJsonObject const JSON_EXTRAS
    {
        { REVERSE,              STATE::DEFAULT },
        { HORN,                 STATE::DEFAULT },
        { LIGHT,                STATE::DEFAULT },
        { EMERGENCY_CALL,       STATE::DEFAULT },
        { VELOCITY,             QJsonValue::Double }
    };

    QJsonObject const JSON_ACTIVATION
    {
        { ACTIVATE,             STATE::DEFAULT },
        { PROTECTION,           STATE::BLINKING },
        { CART,                 STATE::INACTIVE }
    };

    QJsonObject const JSON_ETCS_A
    {
        { SPEEDLIMIT,           QJsonValue::String },
        { SPEEDLIMIT_STATE,     STATE::ACTIVE},
        { DISTANCE,             QJsonValue::String },
        { DISTANCE_STATE,       STATE::ACTIVE},
        { DISTANCE_BAR,         QJsonValue::Double},
        { DISTANCE_BAR_STATE,   STATE::ACTIVE}
    };

    QJsonObject const JSON_ETCS_B
    {
        { ETCSB3,               STATE::INACTIVE },
        { ETCSB4,               STATE::INACTIVE },
        { ETCSB5,               STATE::INACTIVE },
        { ETCSB6,               STATE::INACTIVE },
        { ETCSB7,               STATE::INACTIVE },
        { ETCSB3Image,          QJsonValue::String },
        { ETCSB4Image,          QJsonValue::String },
        { ETCSB5Image,          QJsonValue::String },
        { ETCSB7Image,          QJsonValue::String }
    };

    QJsonObject const JSON_ETCS_C
    {
      { ETCSC6,                 STATE::INACTIVE},
      { ETCSC1Image,            QJsonValue::String },
      { ETCSC3Text,             QJsonValue::Double }
    };
};

#endif // NETWORK_INTERFACE_H
