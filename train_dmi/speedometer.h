#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QObject>

#include "../network_interface.h"

class Speedometer : public QObject
{
    Q_OBJECT
public:
    explicit Speedometer(QObject *obj);

    void updateSpeedometer(QJsonObject update);

private:
    double m_currentSpeed;
    double m_releaseSpeed;
    double m_targetSpeed;
    double m_interventionSpeed;
    double m_permittedSpeed;
    double m_cruiseSpeed;
    double m_advisorySpeed;
    double m_previousSpeed;

    bool autoBreak = false;

    QObject *m_rootObject;

    QString m_speedometerMode;
    QJsonObject m_values{VTI_DMI::JSON_SPEEDOMETER};

    void updateCSM(QJsonObject update);
    void updateCSM_NV(QJsonObject update);
    void updateTSM(QJsonObject update);
    void updateRSM(QJsonObject update);

signals:

};

#endif // SPEEDOMETER_H
