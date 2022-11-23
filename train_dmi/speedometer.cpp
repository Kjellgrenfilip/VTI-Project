#include "speedometer.h"

Speedometer::Speedometer(QObject *obj)
    :   m_rootObject{obj}
{
}

void Speedometer::updateSpeedometer(QJsonObject update, QString mode, QString status)
{
    QObject *obj = m_rootObject->findChild<QObject*>("speedometer");
    foreach(QString key, update.keys())
    {
        m_values.insert(key, update.value(key));
        if(mode == "CSM")
        {
            obj->setProperty("supervisionMode", "CSM");
            if(status == "NoS")
            {
                if(key == VTI_DMI::CURRENTSPEED)
                    obj->setProperty("currentSpeed", update.value(key));
                if(key == VTI_DMI::PERMITTEDSPEED)
                {
                    obj->setProperty("permittedSpeed", update.value(key));
                    obj->setProperty("speedHook", true);
                }
            }
        }
    }

}
