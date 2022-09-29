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

signals:

public slots:
    void receiveUpdate();
};

#endif // TEST_MODULE_H
