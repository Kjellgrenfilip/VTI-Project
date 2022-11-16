#ifndef TEST_MODULE_H
#define TEST_MODULE_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include "network_server.h"
#include "../network_interface.h"
#include <QQueue>

class Test_Module : public QObject
{
    Q_OBJECT
public:
    explicit Test_Module(bool connection = true);
    ~Test_Module();

private:
    Network_Server *m_networkServer;

    QJsonObject m_jsonBrakes;
    QJsonObject m_jsonDoors;
    QJsonObject m_jsonVoltage;
    QJsonObject m_jsonAlarm;
    QJsonObject m_jsonExtras;
    QJsonObject m_jsonActivation;
    QJsonObject m_jsonETCS_A;

    //QTimer *m_doorTimer;
    //QTimer *m_pantUpTimer;

    // test variable for distance bar
    double x{};
    QJsonObject m_jsonETCSB;

    QTimer *m_testTimer;



    void updatePantographUp(QJsonValue const & value);
    void updatePantographDown(QJsonValue const & value);
    void resetPantographUp();
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
    void updateLight(QJsonValue const & value);
    void checkVoltage(QString const& key);
    void resetDoors();
    int testDistance();

public:
    void resetStates();
    void removeImage(QString const & key);

    void updateETCSB(QJsonValue const & value);
    QQueue<QJsonValue> etcsBImageQueue;

    void updateDistance(double newValue);
    void updateDistanceBar(double newValue);
    //void updateTimeToIndication();
    void updateSpeedLimit(double newValue);

signals:

public slots:
    void receiveUpdate();
    //void doorHandler();
    //void pantHandler();
};

#endif // TEST_MODULE_H
