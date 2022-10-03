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
    QString const PONTOGRAPH_UP     = "pontograph_up";
    QString const PONTOGRAPH_DOWN = "pontograph_down";
    QString const VELOCITY          = "velocity";
    QString const VOLTAGE           = "voltage";
    QString const EMERGENCY_BRAKE   = "emergency_brake";
    QString const FIRE              = "fire";
    QString const PARK_BRAKE        = "parking_brake";
    QString const ELECTRICITY_BRAKE = "electricity_brake";
    QString const HBRYT = "h-bryt";
    QString const SP = "sp";
    QString const HEATING = "heating";


    QJsonObject const JSON_TEMPLATE
    {
        { PONTOGRAPH_UP,        "" },
        { VELOCITY,             QJsonValue::Double },
        { VOLTAGE,              QJsonValue::Double }, // should be a double
        { EMERGENCY_BRAKE,      STATE::DEFAULT },
        { FIRE,                 STATE::DEFAULT },
        { PARK_BRAKE,           STATE::DEFAULT },
        { ELECTRICITY_BRAKE,    STATE::DEFAULT },
        {PONTOGRAPH_DOWN,""},
        {HBRYT,""},
        {SP,STATE::WARNING},
        {HEATING,""}

    };
};

#endif // NETWORK_INTERFACE_H
