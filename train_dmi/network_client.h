#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Network_Client : public QObject
{
    Q_OBJECT
public:
    explicit Network_Client();
    ~Network_Client();

    void connectToServer();
    void sendMessage(char const*data);

private:
    QTcpSocket *m_tcpSocket;

signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();


};

#endif // NETWORK_CLIENT_H
