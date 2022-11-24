#include "speedometer.h"

Speedometer::Speedometer(QObject *obj)
    :   m_rootObject{obj}
{
}

void Speedometer::updateSpeedometer(QJsonObject update)
{
    QObject *obj = m_rootObject->findChild<QObject*>("speedometer");
    //m_values.insert(key, update.value(key));
    if(update.value(VTI_DMI::SUPERVISION_STATUS) == "CSM")
    {
        obj->setProperty("supervisionMode", "CSM");
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "NoS")
        {
            obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENT_SPEED));
            obj->setProperty("csgBottomLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            obj->setProperty("csgBottomLayerHook", true);
        }
    }
}
