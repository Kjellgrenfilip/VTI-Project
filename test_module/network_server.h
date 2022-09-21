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

    QJsonObject const& getUpdate();
    void sendUpdate(QJsonObject const& obj);

private:
    void toJSON(QByteArray const& bytes);

    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
    QJsonObject m_JSON;

signals:
    void updateReceived();



public slots:
    void newConnection();
    void readyRead();
};

#endif // NETWORK_SERVER_H
