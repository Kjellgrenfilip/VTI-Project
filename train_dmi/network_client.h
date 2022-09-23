#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QGuiApplication>
#include <QTime>

class Network_Client : public QObject
{
    Q_OBJECT
public:
    explicit Network_Client();
    ~Network_Client();

    void connectToServer();
    bool sendUpdate(const QJsonObject &obj);

private:
    void delay(int time_to_wait);

    QTcpSocket *m_tcpSocket;
    QJsonObject m_jsonState;
signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
};

#endif // NETWORK_CLIENT_H
