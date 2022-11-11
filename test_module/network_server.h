#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>

class Network_Server : public QObject
{
    Q_OBJECT
public:
    explicit Network_Server();
    ~Network_Server();

    QJsonObject getUpdate();
    void setUpdate(QJsonObject update);

    bool sendUpdate(QJsonObject const& obj);
     void delay(int timeToWait);
private:


    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
    QJsonObject m_jsonUpdate;

signals:
    void updateReceived();

public slots:
    void newConnection();
    void readyRead();
    void disconnected();
};

#endif // NETWORK_SERVER_H
