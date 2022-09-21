#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>

class Network_Client : public QObject
{
    Q_OBJECT
public:
    explicit Network_Client();
    ~Network_Client();

    void connectToServer();
    void sendUpdate(const QJsonObject &obj);

private:
    void toJSON(QByteArray const& data);

    QTcpSocket *m_tcpSocket;
    QJsonObject m_JSON;
signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();


};

#endif // NETWORK_CLIENT_H
