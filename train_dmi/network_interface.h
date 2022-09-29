#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include <QString>

namespace VTI_DMI
{
    QString const PONTOGRAPH_UP = "pontograph up";
    QString const BUTTON_2 = "button_2";
    QString const VELOCITY = "velocity";
    QString const VOLTAGE = "voltage";
    QString const NBO = "emergency_brake";
    QString const FIRE = "fire";
};

#endif // NETWORK_INTERFACE_H

//onClicked: network.sendupdate(VTI_DMI::VOLTAGE, True)
