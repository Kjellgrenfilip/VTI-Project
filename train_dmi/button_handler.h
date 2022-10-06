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

    void pontUpClicked();

    void parkBrakeClicked();
    void electricityBrakeClicked();
    void magneticBrakeClicked();
    void magneticBrakeReleased();

    void pontDownClicked();
    void hBrytClicked();
    void heatingClicked();

    void nboClicked();
    void fireClicked();

    void reversePressed();
    void hornPressed();

    void leftDoorClicked();
    void rightDoorClicked();
    void departureButtonClicked();
    void closeDoorClicked();

    void receiptClicked();
};

#endif // BUTTON_HANDLER_H
