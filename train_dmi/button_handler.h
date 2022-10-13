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

signals:
    void sendUpdate(QJsonObject);

public slots:
    void activatePressed();

    void pontUpPressed();

    void parkBrakePressed();
    void electricityBrakePressed();
    void magneticBrakePressed();
    void magneticBrakeReleased();

    void pontDownPressed();
    void mainBreakerPressed();
    void heatingPressed();

    void nboPressed();
    void firePressed();

    void reversePressed();
    void hornPressed();

    void leftDoorPressed();
    void rightDoorPressed();
    void departureButtonPressed();
    void closeDoorPressed();

    void receiptPressed();
};

#endif // BUTTON_HANDLER_H
