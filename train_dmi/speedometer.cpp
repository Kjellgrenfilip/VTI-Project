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
            obj->setProperty("bottomCSG", true);
            obj->setProperty("csgBottomLayerValue", 0);

            obj->setProperty("topCSG", true);
            obj->setProperty("csgTopLayerHook", true);
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));

            obj->setProperty("topColor", "#555555");
        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "OvS")
        {
            obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENT_SPEED));
            obj->setProperty("bottomCSG", true);
            obj->setProperty("csgBottomLayerValue", 0);

            obj->setProperty("topCSG", true);
            obj->setProperty("csgTopLayerHook", true);
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));

            obj->setProperty("topColor", "#555555");

            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() > update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
                obj->setProperty("topColor", "#EA9100");
        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "WaS")
        {

        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {

        }
    }
}
