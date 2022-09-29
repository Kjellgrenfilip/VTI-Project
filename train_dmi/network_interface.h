#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include <QString>

namespace VTI_DMI
{
    QString const PONTOGRAPH_UP = "pontograph_up";
    QString const VELOCITY = "velocity";
    QString const VOLTAGE = "voltage";
    QString const PARK_BRAKE = "park brake";
};

#endif // NETWORK_INTERFACE_H

//onClicked: network.sendupdate(VTI_DMI::VOLTAGE, True)
