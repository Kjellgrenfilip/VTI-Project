#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QGuiApplication>
#include <QTime>

#include "../network_interface.h"

class Network_Client : public QObject
{
    Q_OBJECT
public:
    explicit Network_Client();
    ~Network_Client();

    QJsonObject getUpdate();
    void connectToServer();

private:
    void delay(int time_to_wait);

    QTcpSocket *m_tcpSocket;
    QJsonObject m_jsonUpdate;
signals:
    void updateReceived();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

    void sendUpdate(const QJsonObject &obj);
};

#endif // NETWORK_CLIENT_H
