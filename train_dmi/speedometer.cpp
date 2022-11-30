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
        obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENT_SPEED));
        obj->setProperty("permittedSpeed", update.value(VTI_DMI::PERMITTED_SPEED));
        obj->setProperty("bottomCSG", true);
        obj->setProperty("csgBottomLayerValue", 0);

        obj->setProperty("topCSG", true);
        obj->setProperty("csgTopLayerHook", true);
        obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));

        obj->setProperty("topColor", "#555555");

        if(update.value(VTI_DMI::STATUS_INFORMATION) == "OvS" || update.value(VTI_DMI::STATUS_INFORMATION) == "WaS")
        {
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() > update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
            {
                obj->setProperty("thicCSG", true);
                obj->setProperty("thicColor", "#EA9100");
                //obj->setProperty("csgThicLayerValue", (update.value(VTI_DMI::CURRENT_SPEED).toDouble())-(update.value(VTI_DMI::PERMITTED_SPEED).toDouble()));
                obj->setProperty("csgThicLayerValue", 50.0);
            }
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
                    obj->setProperty("thicCSG", false);
        }

        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() > update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
            {
                obj->setProperty("thicCSG", true);
                obj->setProperty("thicColor", "#BF0002");
                obj->setProperty("csgThicLayerValue", (update.value(VTI_DMI::CURRENT_SPEED).toDouble())-(update.value(VTI_DMI::PERMITTED_SPEED).toDouble()));
            }
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
                    obj->setProperty("thicCSG", false);
        }


    }
    if(update.value(VTI_DMI::SUPERVISION_STATUS) == "TSM")
    {
        obj->setProperty("supervisionMode", "TSM");
        obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENT_SPEED));
        if(update.value(VTI_DMI::RELEASE_SPEED) != "-1")
        {
            if(0.0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::RELEASE_SPEED).toDouble())
            {
                obj->setProperty("topColor", "#969696");
                obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
                obj->setProperty("csgTopLayerHook", false);
            }
        }

        if(update.value(VTI_DMI::STATUS_INFORMATION) == "OvS")
        {

        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "WaS")
        {

        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IndS")
        {
            obj->setProperty("permittedSpeed", update.value(VTI_DMI::PERMITTED_SPEED));
            obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENT_SPEED));
            obj->setProperty("releaseSpeed", update.value(VTI_DMI::RELEASE_SPEED));
            //obj->setProperty("advisorySpeed", update.value(VTI_DMI::ADVISORY_SPEED));
            if(update.value(VTI_DMI::RELEASE_SPEED) != -1)
            {
                obj->setProperty("middleCSG", true);
                obj->setProperty("csgMiddleLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
                obj->setProperty("outerColor", "#969696");
                obj->setProperty("middleColor", "#031122");
                obj->setProperty("innerColor", "#DFDF00");
            }
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() < update.value(VTI_DMI::TARGET_SPEED).toDouble()
                    && 0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() )
            {
                obj->setProperty("csgTopLayerHook", true);
                obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            }
            if(update.value(VTI_DMI::TARGET_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble()
                    && update.value(VTI_DMI::PERMITTED_SPEED).toDouble() >= update.value(VTI_DMI::CURRENT_SPEED).toDouble() )
            {
                obj->setProperty("csgTopLayerHook", true);
                obj->setProperty("topColor", "#DFDF00");
                obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            }



        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {

        }
    }
}
