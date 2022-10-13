#ifndef TEST_MODULE_H
#define TEST_MODULE_H

#include <QObject>
#include <QDebug>

#include <network_server.h>
#include "../network_interface.h"

class Test_Module : public QObject
{
    Q_OBJECT
public:
    explicit Test_Module();
    ~Test_Module();

private:
    Network_Server *m_networkServer;
    QJsonObject m_jsonState;

    void updatePontographUp(QJsonValue const & value);
    void updatePontographDown(QJsonValue const & value);
    void updateMainBreaker(QJsonValue const & value);
    void updateHeating(QJsonValue const & value);
    void updateVelocity(QJsonValue const & value);
    void updateVoltage(QJsonValue const & value);
    void updateParkBrake(QJsonValue const & value);
    void updateElectrictyBrake(QJsonValue const & value);
    void updateMagneticBrake(QJsonValue const & value);
    void updateEmergencyBrake(QJsonValue const & value);
    void updateFire(QJsonValue const & value);
    void updateReceipt(QJsonValue const & value);
    void updateReverse(QJsonValue const & value);
    void updateDoorLeft(QJsonValue const & value);
    void updateDoorRight(QJsonValue const & value);
    void updateDeparture(QJsonValue const & value);
    void updateDoorClose(QJsonValue const & value);

signals:

public slots:
    void receiveUpdate();
};

#endif // TEST_MODULE_H
