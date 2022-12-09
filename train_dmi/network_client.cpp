#include "network_client.h"

#include <QDebug>

Network_Client::Network_Client() : QObject(), m_tcpSocket{new QTcpSocket{this}}
{
    // Connects signals for TCP connection handling.
    connect(m_tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(m_tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
}

Network_Client::~Network_Client()
{
    delete m_tcpSocket;
}

QJsonObject Network_Client::getUpdate()
{
    return m_jsonUpdate;
}

// Connects to the server on the localhost adress & port 1200.
void Network_Client::connectToServer()
{
    qDebug() << "Connecting .... ";
    m_tcpSocket->connectToHost("127.0.0.1", 1200);
    m_tcpSocket->waitForConnected(1000);
}

void Network_Client::delay(int timeToWait)
{
    QTime dieTime= QTime::currentTime().addMSecs(timeToWait);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Network_Client::connected()
{
    qDebug() << "Connected";
}

void Network_Client::disconnected()
{
    qDebug() << "Disconnected";
}

// Called automatically when there is data to read on the socket.
void Network_Client::readyRead()
{
    qDebug() << "Reading ... ";
    QByteArray data{m_tcpSocket->readAll()};
    m_jsonUpdate= (QJsonDocument(QJsonDocument::fromJson(data)).object());
    emit updateReceived();
}

// Sends an update out on the socket.
void Network_Client::sendUpdate(const QJsonObject &obj)
{
    QByteArray data = QJsonDocument{obj}.toJson();
    m_tcpSocket->write(data, qstrlen(data));

    // Less than 10 milliseconds and there is no guarantee that all data will be processed correctly.
    delay(10);
}



