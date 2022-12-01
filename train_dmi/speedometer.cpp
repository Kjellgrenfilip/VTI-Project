#include "speedometer.h"

Speedometer::Speedometer(QObject *obj)
    :   m_rootObject{obj}
{
}

void Speedometer::updateSpeedometer(QJsonObject update)
{

    QObject *obj = m_rootObject->findChild<QObject*>("speedometer");
    obj->setProperty("topCSG", false);
    obj->setProperty("csgTopLayerHook", false);
     obj->setProperty("thicCSG", false);
     obj->setProperty("middleCSG", false);
      obj->setProperty("speedDigitColor", "black");

      if(autoBreak)
        {
          qDebug() << "AUTOBREAKING";
          if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
              autoBreak = false;
        }

    //m_values.insert(key, update.value(key));
    if(update.value(VTI_DMI::SUPERVISION_STATUS) == "CSM" || update.value(VTI_DMI::SUPERVISION_STATUS) == "CSM_NV")
    {

        obj->setProperty("supervisionMode", update.value(VTI_DMI::SUPERVISION_STATUS));
        obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENT_SPEED));
        obj->setProperty("permittedSpeed", update.value(VTI_DMI::PERMITTED_SPEED));
        obj->setProperty("bottomCSG", true);
        obj->setProperty("csgBottomLayerValue", 0);

        obj->setProperty("topCSG", true);
        obj->setProperty("csgTopLayerHook", true);
        obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
        obj->setProperty("needleColor", "grey");
        obj->setProperty("topColor", "#555555");

        if(update.value(VTI_DMI::STATUS_INFORMATION) == "OvS" || update.value(VTI_DMI::STATUS_INFORMATION) == "WaS")
        {
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() > update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
            {
                obj->setProperty("thicCSG", true);
                obj->setProperty("thicColor", "#EA9100");
                obj->setProperty("needleColor", "orange");
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
                obj->setProperty("needleColor", "red");
                obj->setProperty("speedDigitColor", "white");
                obj->setProperty("thicColor", "#BF0002");
                obj->setProperty("csgThicLayerValue", (update.value(VTI_DMI::CURRENT_SPEED).toDouble())-(update.value(VTI_DMI::PERMITTED_SPEED).toDouble()));
                if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() == update.value(VTI_DMI::PERMITTED_SPEED).toDouble() +10.0)
                    autoBreak = true;
            }
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
                    obj->setProperty("thicCSG", false);
        }
       if((update.value(VTI_DMI::STATUS_INFORMATION) == "NoS" || update.value(VTI_DMI::STATUS_INFORMATION) == "IntS") && update.value(VTI_DMI::SUPERVISION_STATUS) == "CSM_NV")
       {
            if((update.value(VTI_DMI::TARGET_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble()) && (update.value(VTI_DMI::CURRENT_SPEED).toDouble()<= update.value(VTI_DMI::PERMITTED_SPEED).toDouble()))
            {
                obj->setProperty("needleColor", "white");
                obj->setProperty("speedDigitColor", "black");
            }
    }
    }
    if(update.value(VTI_DMI::SUPERVISION_STATUS) == "TSM")
    {
        obj->setProperty("supervisionMode", "TSM");
        obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENT_SPEED));
        if(update.value(VTI_DMI::RELEASE_SPEED) != "-1")
        {
            if(0.0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble()<= update.value(VTI_DMI::RELEASE_SPEED).toDouble())
            {
                obj->setProperty("topColor", "#969696");
                obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
                obj->setProperty("csgTopLayerHook", false);
            }
        }

        if(update.value(VTI_DMI::STATUS_INFORMATION) == "OvS")
        {
            if(update.value(VTI_DMI::PERMITTED_SPEED).toDouble() < update.value(VTI_DMI::CURRENT_SPEED).toDouble())
            {
                obj->setProperty("needleColor", "orange");
                obj->setProperty("speedDigitColor", "black");
            }
        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "WaS")
        {
            if(update.value(VTI_DMI::PERMITTED_SPEED).toDouble() < update.value(VTI_DMI::CURRENT_SPEED).toDouble())
            {
                obj->setProperty("needleColor", "orange");
                obj->setProperty("speedDigitColor", "black");
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
                obj->setProperty("needleColor", "grey");
                obj->setProperty("speedDigitColor", "black");
            }
            if(update.value(VTI_DMI::TARGET_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble()
                    && update.value(VTI_DMI::PERMITTED_SPEED).toDouble() >= update.value(VTI_DMI::CURRENT_SPEED).toDouble() )
            {
                obj->setProperty("needleColor", "yellow");
                obj->setProperty("speedDigitColor", "black");
                obj->setProperty("csgTopLayerHook", true);
                obj->setProperty("topColor", "#DFDF00");
                obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            }



        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {
            if(update.value(VTI_DMI::TARGET_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble()
                    && update.value(VTI_DMI::PERMITTED_SPEED).toDouble() >= update.value(VTI_DMI::CURRENT_SPEED).toDouble() )
            {
                obj->setProperty("needleColor", "yellow");
                obj->setProperty("speedDigitColor", "black");
            }
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() < update.value(VTI_DMI::TARGET_SPEED).toDouble()
                    && 0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() )
            {
                obj->setProperty("needleColor", "grey");
                obj->setProperty("speedDigitColor", "black");
            }
            if(update.value(VTI_DMI::PERMITTED_SPEED).toDouble() < update.value(VTI_DMI::CURRENT_SPEED).toDouble())
            {
                obj->setProperty("needleColor", "red");
                obj->setProperty("speedDigitColor", "white");
            }
        }
    }
}

    if(update.value(VTI_DMI::SUPERVISION_STATUS) == "RSM")
    {
        obj->setProperty("supervisionMode", update.value(VTI_DMI::SUPERVISION_STATUS));
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IndS" || update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {
            if(0.0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::RELEASE_SPEED).toDouble())
            {
                obj->setProperty("needleColor", "yellow");
                obj->setProperty("speedDigitColor", "black");
            }
        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() > update.value(VTI_DMI::RELEASE_SPEED).toDouble())
            {
                obj->setProperty("needleColor", "red");
                obj->setProperty("speedDigitColor", "white");
            }
        }
    }
}
