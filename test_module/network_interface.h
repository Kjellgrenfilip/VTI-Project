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

    QString const PARK_BRAKE = "park_button";
    QString const ELECTRICITY_BRAKE = "electricity_brake";

    QString const NBO = "emergency_brake";
    QString const FIRE = "fire";
    QString const HBRYT = "h-bryt";
    QString const SP = "sp";
    QString const HEATING = "heating";




    QJsonObject const JSON_TEMPLATE
    {
        {PONTOGRAPH_UP,""},
        {VELOCITY, QJsonValue::Double},
        {VOLTAGE, QJsonValue::Double},
        {PARK_BRAKE, ""},
        {NBO, QJsonValue::Bool},
        {FIRE, QJsonValue::Bool},
<<<<<<< HEAD
        {ELECTRICITY_BRAKE, ""}

=======
        {PONTOGRAPH_DOWN,""},
        {HBRYT,""},
        {SP,""},
        {HEATING,""}
>>>>>>> power_implementation
    };
};

#endif // NETWORK_INTERFACE_H
