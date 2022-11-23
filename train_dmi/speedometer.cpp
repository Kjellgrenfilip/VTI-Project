#include "speedometer.h"

Speedometer::Speedometer(QObject *obj)
    :   m_rootObject{obj}
{
}

void Speedometer::updateSpeedometer(QJsonObject update)
{
    foreach(QString key, update.keys())
    {
        m_values.insert(key, update.value(key));
        QObject *obj = m_rootObject->findChild<QObject*>("speedometer");
        if(key == VTI_DMI::CURRENTSPEED)
            obj->setProperty("currentSpeed", update.value(key));
    }

}
