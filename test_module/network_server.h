#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTime>
#include <QCoreApplication>

class Network_Server : public QObject
{
    Q_OBJECT
public:
    explicit Network_Server();
    ~Network_Server();

    QJsonObject getUpdate();
    bool sendUpdate(QJsonObject const& obj);

private:
    void delay(int time_to_wait);

    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
    QJsonObject m_jsonUpdate;

signals:
    void updateReceived();

public slots:
    void newConnection();
    void readyRead();
};

#endif // NETWORK_SERVER_H
