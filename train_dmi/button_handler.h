#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>

#include "network_interface.h"

class Button_Handler : public QObject
{
    Q_OBJECT
public:
    explicit Button_Handler();

private:

signals:
    void sendUpdate(QJsonObject);

public slots:
    void pontUpClicked();
    void pontDownClicked();
    void hBrytClicked();
};

#endif // BUTTON_HANDLER_H
