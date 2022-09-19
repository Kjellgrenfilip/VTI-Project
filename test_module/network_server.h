#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Network_Server : public QObject
{
    Q_OBJECT
public:
    explicit Network_Server();
    ~Network_Server();

private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;

public slots:
    void newConnection();
    void readyRead();
};

#endif // NETWORK_SERVER_H
