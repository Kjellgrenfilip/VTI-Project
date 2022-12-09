#include "speedometer.h"

Speedometer::Speedometer(QObject *obj)
    :   m_rootObject{obj}
{
}

void Speedometer::updateSpeedometer(QJsonObject update)
{
    QObject *obj = m_rootObject->findChild<QObject*>("speedometer");

    obj->setProperty("topCSG", true);
    obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENT_SPEED));
    obj->setProperty("interventionSpeed", update.value(VTI_DMI::INTERVENTION_SPEED));
    obj->setProperty("supervisionMode", update.value(VTI_DMI::SUPERVISION_STATUS));
    obj->setProperty("targetSpeed", update.value(VTI_DMI::TARGET_SPEED));
    obj->setProperty("permittedSpeed", update.value(VTI_DMI::PERMITTED_SPEED));
    obj->setProperty("releaseSpeed", update.value(VTI_DMI::RELEASE_SPEED));
    obj->setProperty("bottomCSG", true);
    obj->setProperty("csgBottomLayerValue", 0);

    //obj->setProperty("csgTopLayerHook", false);
    obj->setProperty("thicCSG", false);
    obj->setProperty("middleCSG", false);
    obj->setProperty("speedDigitColor", "black");
    obj->setProperty("needleColor", "grey");

    if(update.value(VTI_DMI::SUPERVISION_STATUS) == "CSM")
    {
        updateCSM(update);
    }
    if(update.value(VTI_DMI::SUPERVISION_STATUS) == "CSM_NV")
    {
        updateCSM_NV(update);
    }
    if(update.value(VTI_DMI::SUPERVISION_STATUS) == "TSM")
    {
        updateTSM(update);
    }
    if(update.value(VTI_DMI::SUPERVISION_STATUS) == "RSM")
    {
        updateRSM(update);
    }

}

void Speedometer::updateCSM(QJsonObject update)
{
     QObject *obj = m_rootObject->findChild<QObject*>("speedometer");

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
             obj->setProperty("csgThicLayerValue", update.value(VTI_DMI::INTERVENTION_SPEED).toDouble());
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
             if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() == update.value(VTI_DMI::PERMITTED_SPEED).toDouble() +5.0)
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

void Speedometer::updateCSM_NV(QJsonObject update)
{
    QObject *obj = m_rootObject->findChild<QObject*>("speedometer");

}

//
void Speedometer::updateTSM(QJsonObject update)
{
    qDebug() << update.value(VTI_DMI::STATUS_INFORMATION).toString();
    qDebug() << "INNE I TSM";
    QObject *obj = m_rootObject->findChild<QObject*>("speedometer");
    obj->setProperty("supervisionMode", "TSM");
    obj->setProperty("currentSpeed", update.value(VTI_DMI::CURRENT_SPEED));
    obj->setProperty("permittedSpeed", update.value(VTI_DMI::PERMITTED_SPEED));
    obj->setProperty("releaseSpeed", update.value(VTI_DMI::RELEASE_SPEED));

    if(update.value(VTI_DMI::RELEASE_SPEED) != "-1")
    {
        if(0.0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble()<= update.value(VTI_DMI::RELEASE_SPEED).toDouble())
        {
            obj->setProperty("topColor", csgMediumGrey);
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
            obj->setProperty("csgTopLayerHook", false);

        }

        if(0.0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() < update.value(VTI_DMI::TARGET_SPEED).toDouble())
        {
            obj->setProperty("topColor", csgDarkGrey);
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::TARGET_SPEED));
            obj->setProperty("topCSG", true);
            obj->setProperty("csgTopLayerHook", true);

            obj->setProperty("middleCSG", true);
            obj->setProperty("csgMiddleLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
            obj->setProperty("outerColor", csgDarkGrey);
            obj->setProperty("middleColor", csgDarkGrey);
            obj->setProperty("innerColor", csgDarkGrey);
        }

        if(update.value(VTI_DMI::TARGET_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
        {
            obj->setProperty("topColor", csgYellow);
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            obj->setProperty("csgTopLayerHook", true);
            obj->setProperty("topCSG", true);

            obj->setProperty("middleCSG", true);
            obj->setProperty("csgMiddleLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
            obj->setProperty("outerColor", csgDarkGrey);
            obj->setProperty("middleColor", "transparent");
            obj->setProperty("innerColor", csgYellow);
            obj->setProperty("topCSG", true);

            obj->setProperty("bottomCSG", true);
            obj->setProperty("csgBottomLayerValue", update.value(VTI_DMI::TARGET_SPEED));
        }
    }
    if(update.value(VTI_DMI::PERMITTED_SPEED).toDouble() < update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::INTERVENTION_SPEED).toDouble())
    {
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IndS")
        {
            // Never occurs, does not change anything according to ERTMS-standard.
        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "WaS" || update.value(VTI_DMI::STATUS_INFORMATION) == "OvS")
        {
            obj->setProperty("csgTopLayerHook", true);
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            obj->setProperty("needleColor", "orange");
            obj->setProperty("speedDigitColor", "black");
            obj->setProperty("thicCSG", true);
            obj->setProperty("thicColor", "orange");
            obj->setProperty("csgThicLayerValue", update.value(VTI_DMI::INTERVENTION_SPEED).toDouble() - update.value(VTI_DMI::PERMITTED_SPEED).toDouble());

            obj->setProperty("middleCSG", true);
            obj->setProperty("csgMiddleLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
            obj->setProperty("outerColor", csgMediumGrey);
            obj->setProperty("middleColor", "#031122");
        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {
            obj->setProperty("needleColor", "red");
            obj->setProperty("speedDigitColor", "white");
            obj->setProperty("thicCSG", true);
            obj->setProperty("thicColor", csgRed);
            obj->setProperty("csgThicLayerValue", (update.value(VTI_DMI::CURRENT_SPEED).toDouble() - update.value(VTI_DMI::PERMITTED_SPEED).toDouble()));
            if(update.value(VTI_DMI::RELEASE_SPEED) != -1)
            {
                obj->setProperty("middleCSG", true);
                obj->setProperty("csgMiddleLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
                obj->setProperty("outerColor", "#969696");
                obj->setProperty("middleColor", "#031122");
                obj->setProperty("innerColor", "#DFDF00");
            }
            obj->setProperty("topCSG", true);
            obj->setProperty("csgTopLayerHook", true);
            obj->setProperty("topColor", "#DFDF00");
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            obj->setProperty("bottomCSG", true);
        }
    }


    /*
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
        if(update.value(VTI_DMI::PERMITTED_SPEED).toDouble() < update.value(VTI_DMI::CURRENT_SPEED).toDouble())
        {
            obj->setProperty("needleColor", "orange");
            obj->setProperty("speedDigitColor", "black");
        }
        if(update.value(VTI_DMI::PERMITTED_SPEED).toDouble() < update.value(VTI_DMI::CURRENT_SPEED).toDouble() &&
                update.value(VTI_DMI::INTERVENTION_SPEED).toDouble() > update.value(VTI_DMI::CURRENT_SPEED).toDouble())
        {
            obj->setProperty("csgTopLayerHook", true);
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            obj->setProperty("needleColor", "orange");
            obj->setProperty("speedDigitColor", "black");
            obj->setProperty("thicCSG", true);
            obj->setProperty("thicColor", "orange");
            obj->setProperty("csgThicLayerValue", update.value(VTI_DMI::INTERVENTION_SPEED).toDouble() - update.value(VTI_DMI::PERMITTED_SPEED).toDouble());
        }
    }

    if(update.value(VTI_DMI::STATUS_INFORMATION) == "IndS")
    {

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
            qDebug() << "Kommer in i TSM IndS 2";
            obj->setProperty("needleColor", "yellow");
            obj->setProperty("speedDigitColor", "black");
            obj->setProperty("topCSG", true);
            obj->setProperty("csgTopLayerHook", true);
            obj->setProperty("topColor", "#DFDF00");
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            obj->setProperty("bottomCSG", true);
            obj->setProperty("csgBottomLayerValue", update.value(VTI_DMI::TARGET_SPEED));
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
            obj->setProperty("thicCSG", true);
            obj->setProperty("thicColor", csgRed);
            obj->setProperty("csgThicLayerValue", (update.value(VTI_DMI::CURRENT_SPEED).toDouble() - update.value(VTI_DMI::PERMITTED_SPEED).toDouble()));
            if(update.value(VTI_DMI::RELEASE_SPEED) != -1)
            {
                obj->setProperty("middleCSG", true);
                obj->setProperty("csgMiddleLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
                obj->setProperty("outerColor", "#969696");
                obj->setProperty("middleColor", "#031122");
                obj->setProperty("innerColor", "#DFDF00");
            }
            obj->setProperty("topCSG", true);
            obj->setProperty("csgTopLayerHook", true);
            obj->setProperty("topColor", "#DFDF00");
            obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
            obj->setProperty("bottomCSG", true);
            //obj->setProperty("csgBottomLayerValue", update.value(VTI_DMI::TARGET_SPEED));

        }
    }*/
}

void Speedometer::updateRSM(QJsonObject update)
{
    QObject *obj = m_rootObject->findChild<QObject*>("speedometer");

    obj->setProperty("supervisionMode", update.value(VTI_DMI::SUPERVISION_STATUS));

  if(update.value(VTI_DMI::STATUS_INFORMATION) == "IndS")
  {
      obj->setProperty("needleColor", "yellow");
      obj->setProperty("speedDigitColor", "black");

  }
   if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() > update.value(VTI_DMI::RELEASE_SPEED).toDouble())
            {
                obj->setProperty("needleColor", "red");
                obj->setProperty("speedDigitColor", "white");
            }
        }

   if(0.0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::RELEASE_SPEED).toDouble())
   {
           obj->setProperty("topCSG", true);
           obj->setProperty("csgTopLayerHook", false);
           obj->setProperty("topColor", csgMediumGrey);
           obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
    }
   if(update.value(VTI_DMI::TARGET_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
   {
           obj->setProperty("needleColor", "yellow");
           obj->setProperty("speedDigitColor", "black");

           obj->setProperty("topCSG", true);
           obj->setProperty("csgTopLayerHook", true);
           obj->setProperty("topColor", csgYellow);
           obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));

           obj->setProperty("middleCSG", true);
           obj->setProperty("csgMiddleLayerValue", update.value(VTI_DMI::RELEASE_SPEED));
           obj->setProperty("outerColor", "#969696");
           obj->setProperty("middleColor", "#031122");
           obj->setProperty("innerColor", "#DFDF00");
    }
   if(update.value(VTI_DMI::PERMITTED_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::RELEASE_SPEED).toDouble())
    {
       obj->setProperty("topCSG", true);
       obj->setProperty("csgTopLayerHook", false);
       obj->setProperty("topColor", csgMediumGrey);
       obj->setProperty("csgTopLayerValue", update.value(VTI_DMI::RELEASE_SPEED));

       obj->setProperty("middleCSG", true);
       obj->setProperty("csgMiddleLayerValue", update.value(VTI_DMI::PERMITTED_SPEED));
       obj->setProperty("outerColor", "#969696");
       obj->setProperty("middleColor", "#031122");
       obj->setProperty("innerColor", "#DFDF00");
       obj->setProperty("smallSpeedHook", true);
   }
}

