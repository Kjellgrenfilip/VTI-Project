#ifndef DMI_HANDLER_H
#define DMI_HANDLER_H

#include <QObject>
#include <QQmlContext>

#include "network_client.h"
#include "button_handler.h"

class DMI_Handler : public QObject
{
    Q_OBJECT
public:
    explicit DMI_Handler(QQmlContext *rootContext, QObject *obj);
    ~DMI_Handler();

private:
    Network_Client *m_client;
    Button_Handler *m_buttonHandler;
<<<<<<< HEAD
    QObject *rootObject;
=======
    QObject *m_rootObject;
>>>>>>> 5fdf118bb576aa33b91dbd3db41ae2799dd131d2

    QJsonObject m_jsonState;

signals:

public slots:
    void receiveUpdate();

};

#endif // DMI_HANDLER_H
