#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QObject>

class Speedometer : public QObject
{
    Q_OBJECT
public:
    explicit Speedometer(QObject *parent = nullptr);

    void updateSpeedometer();

private:
    double m_currentSpeed;
    double m_releaseSpeed;
    double m_targetSpeed;
    double m_interventionSpeed;
    double m_permittedSpeed;
    double m_cruiseSpeed;
    double m_advisorySpeed;
    double m_previousSpeed;

    QString m_speedometerMode;

signals:

};

#endif // SPEEDOMETER_H
