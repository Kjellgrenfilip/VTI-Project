#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>

#include "../network_interface.h"

class Button_Handler : public QObject
{
    Q_OBJECT
public:
    explicit Button_Handler();

private:
    void sendSignal(QString const& object, bool const value);

signals:
    void sendUpdate(QJsonObject);
    void sendSignalMaxDistance(int x);

public slots:
    void activatePressed();
    void protectionPressed();

    void pantUpPressed();

    void parkBrakePressed();
    void electricityBrakePressed();
    void magneticBrakePressed();
    void magneticBrakeReleased();

    void pantDownPressed();
    void mainBreakerPressed();
    void heatingPressed();

    void emergencyBrakePressed();
    void firePressed();

    void reversePressed();
    void hornPressed();

    void leftDoorPressed();
    void rightDoorPressed();
    void departureButtonPressed();
    void closeDoorPressed();

    void receiptPressed();
    void lightPressed();
    void emergencyPressed();

    void etcsC1Pressed();
    void scaleUpPressed(int x);
    void scaleDownPressed(int x);
};

#endif // BUTTON_HANDLER_H
