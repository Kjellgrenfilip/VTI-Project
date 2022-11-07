#ifndef DMI_HANDLER_H
#define DMI_HANDLER_H

#include <QObject>
#include <QQmlContext>

#include <QTimer>

#include "network_client.h"
#include "button_handler.h"

class DMI_Handler : public QObject
{
    Q_OBJECT
public:
    explicit DMI_Handler(QQmlContext *rootContext, QObject *obj);
    DMI_Handler(bool testStart = true);
    ~DMI_Handler();

public:
    Network_Client *m_client;
    Button_Handler *m_buttonHandler;
    QObject *m_rootObject;
    QTimer *m_animationTimer;

    QJsonObject m_jsonState;
    QJsonObject m_latestUpdate{};

    bool testStart = false;

signals:

public slots:
    void receiveUpdate();
    void animationHandler();
};

#endif // DMI_HANDLER_H
