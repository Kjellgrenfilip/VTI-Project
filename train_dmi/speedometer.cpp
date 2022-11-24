#include "speedometer.h"

Speedometer::Speedometer(QObject *obj)
    :   m_rootObject{obj}
{
}

void Speedometer::updateSpeedometer(QJsonObject update)
{
    QObject *obj = m_rootObject->findChild<QObject*>("speedometer");
    //m_values.insert(key, update.value(key));
    if(update.value(VTI_DMI::SUPERVISIONSTATUS) == "CSM")
    {
        obj->setProperty("supervisionMode", "CSM");
        if(update.value(VTI_DMI::STATUSINFORMATION) == "NoS")
        {
            obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENTSPEED));
            obj->setProperty("csgBottomLayerValue", update.value(VTI_DMI::PERMITTEDSPEED));
            obj->setProperty("csgBottomLayerHook", true);
        }
    }

}
