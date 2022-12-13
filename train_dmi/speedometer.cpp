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
     QObject* obj = m_rootObject->findChild<QObject*>("speedometer");

     setTopLayer(obj, "#555555", true, update.value(VTI_DMI::PERMITTED_SPEED).toDouble(), true);
     setNeedle(obj, "grey", "black");

     if(update.value(VTI_DMI::STATUS_INFORMATION) == "OvS" || update.value(VTI_DMI::STATUS_INFORMATION) == "WaS")
     {
         if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() > update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
         {
             setThicLayer(obj, true, csgOrange, update.value(VTI_DMI::INTERVENTION_SPEED).toDouble());
             setNeedle(obj, "orange", "black");
         }
         if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
                 obj->setProperty("thicCSG", false);
     }
     if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
     {
         if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() > update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
         {
             setNeedle(obj, "red", "white");
             setThicLayer(obj, true, csgRed, (update.value(VTI_DMI::CURRENT_SPEED).toDouble())-(update.value(VTI_DMI::PERMITTED_SPEED).toDouble()));
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
             setNeedle(obj, "white", "black");
         }
    }
}
void Speedometer::updateCSM_NV(QJsonObject update)
{
 //   QObject *obj = m_rootObject->findChild<QObject*>("speedometer");
}

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
            setTopLayer(obj, csgMediumGrey, true, update.value(VTI_DMI::RELEASE_SPEED).toDouble(), false);
        }

        if(0.0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() < update.value(VTI_DMI::TARGET_SPEED).toDouble())
        {
            setTopLayer(obj, csgDarkGrey, true, update.value(VTI_DMI::TARGET_SPEED).toDouble(), true);
            setMiddleLayer(obj, csgDarkGrey, csgDarkGrey, csgDarkGrey, true, update.value(VTI_DMI::RELEASE_SPEED).toDouble(), false);
        }

        if(update.value(VTI_DMI::TARGET_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
        {
            setTopLayer(obj, csgYellow, true, update.value(VTI_DMI::PERMITTED_SPEED).toDouble(), true);
            setMiddleLayer(obj, csgYellow, "transparent", csgDarkGrey, true, update.value(VTI_DMI::RELEASE_SPEED).toDouble(), false);
            setBottomLayer(obj, true, update.value(VTI_DMI::TARGET_SPEED).toDouble());
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
            setTopLayer(obj, csgYellow, true, update.value(VTI_DMI::PERMITTED_SPEED).toDouble(), true);
            setNeedle(obj, "orange", "black");
            setThicLayer(obj, true, csgOrange, update.value(VTI_DMI::INTERVENTION_SPEED).toDouble() - update.value(VTI_DMI::PERMITTED_SPEED).toDouble());
            setMiddleLayer(obj, csgYellow, "#031122", csgMediumGrey, true, update.value(VTI_DMI::RELEASE_SPEED).toDouble(), false);
        }
        if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {
            setNeedle(obj, "red", "white");
            setThicLayer(obj, true, csgRed, (update.value(VTI_DMI::CURRENT_SPEED).toDouble() - update.value(VTI_DMI::PERMITTED_SPEED).toDouble()));
            if(update.value(VTI_DMI::RELEASE_SPEED) != -1)
            {
                setMiddleLayer(obj, csgYellow, "#031122", csgMediumGrey, true, update.value(VTI_DMI::RELEASE_SPEED).toDouble(), false);
            }
            setTopLayer(obj, csgYellow, true, update.value(VTI_DMI::PERMITTED_SPEED).toDouble(), true);
            setBottomLayer(obj, true, 0.0);
        }
    }
}

void Speedometer::updateRSM(QJsonObject update)
{
    QObject *obj = m_rootObject->findChild<QObject*>("speedometer");

    obj->setProperty("supervisionMode", update.value(VTI_DMI::SUPERVISION_STATUS));

    if(update.value(VTI_DMI::STATUS_INFORMATION) == "IndS")
    {
        setNeedle(obj, "yellow", "black");
    }
    if(update.value(VTI_DMI::STATUS_INFORMATION) == "IntS")
        {
            if(update.value(VTI_DMI::CURRENT_SPEED).toDouble() > update.value(VTI_DMI::RELEASE_SPEED).toDouble())
            {
                setNeedle(obj, "red", "white");
            }
        }

   if(0.0 <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::RELEASE_SPEED).toDouble())
   {
        setTopLayer(obj, csgMediumGrey, true, update.value(VTI_DMI::RELEASE_SPEED).toDouble(), false);
    }
   if(update.value(VTI_DMI::TARGET_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::PERMITTED_SPEED).toDouble())
   {
           setNeedle(obj, "yellow", "black");
           setTopLayer(obj, csgYellow, true, update.value(VTI_DMI::PERMITTED_SPEED).toDouble(), true);
           setMiddleLayer(obj, csgYellow,"#031122",csgMediumGrey, true, update.value(VTI_DMI::RELEASE_SPEED).toDouble(), false);
    }
   if(update.value(VTI_DMI::PERMITTED_SPEED).toDouble() <= update.value(VTI_DMI::CURRENT_SPEED).toDouble() && update.value(VTI_DMI::CURRENT_SPEED).toDouble() <= update.value(VTI_DMI::RELEASE_SPEED).toDouble())
    {
       setTopLayer(obj, csgMediumGrey, true, update.value(VTI_DMI::RELEASE_SPEED).toDouble(), false);
       setMiddleLayer(obj, csgYellow, "#031122", csgMediumGrey, true, update.value(VTI_DMI::PERMITTED_SPEED).toDouble(), true);
   }
}

//Sets all values for the top CSG layer
void Speedometer::setTopLayer(QObject *obj, QString color, bool status, double dist, bool hook)
{
    obj->setProperty("topColor", color);
    obj->setProperty("csgTopLayerValue", dist);
    obj->setProperty("topCSG", status);
    obj->setProperty("csgTopLayerHook", hook);
}
//Sets all values for the needle
void Speedometer::setNeedle(QObject *obj, QString needleColor, QString textColor)
{
    obj->setProperty("needleColor", needleColor);
    obj->setProperty("speedDigitColor", textColor);
}
//Sets all values for the middle three-way CSG layer
void Speedometer::setMiddleLayer(QObject *obj, QString inner, QString middle, QString outer, bool status, double dist, bool hook)
{
    obj->setProperty("middleCSG", status);
    obj->setProperty("csgMiddleLayerValue", dist);
    obj->setProperty("outerColor", outer);
    obj->setProperty("middleColor", middle);
    obj->setProperty("innerColor", inner);
    obj->setProperty("smallSpeedHook", hook);
}
//Sets all values for the bottom CSG layer
void Speedometer::setBottomLayer(QObject *obj, bool status, double val)
{
    obj->setProperty("bottomCSG", status);
    obj->setProperty("csgBottomLayerValue", val);
}
//Sets all values for the thic CSG layer
void Speedometer::setThicLayer(QObject *obj, bool status, QString color, double val)
{
    obj->setProperty("thicCSG", status);
    obj->setProperty("thicColor", color);
    obj->setProperty("csgThicLayerValue", val);
}


