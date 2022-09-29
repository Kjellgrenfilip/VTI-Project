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
    explicit Button_Handler(QObject *obj);

private:
    QObject *rootObject;

signals:
    void sendUpdate(QJsonObject);

public slots:
    void pontUpClicked();
    void parkBrakeClicked();

};

#endif // BUTTON_HANDLER_H
