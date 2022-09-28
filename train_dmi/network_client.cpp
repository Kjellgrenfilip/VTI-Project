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

bool Network_Client::sendUpdate(const QJsonObject &obj)
{
    QByteArray data = QJsonDocument{obj}.toJson();
    qint64 dataWritten = m_tcpSocket->write(data, qstrlen(data));

    // Less than 10 milliseconds and there is no guarantee all that will be processed correctly.
    delay(10);

    if(data.size() != dataWritten)
        return false;
    return true;
}

void Network_Client::connectToServer()
{
    qDebug() << "Connecting .... ";
    m_tcpSocket->connectToHost("127.0.0.1", 1200);
    m_tcpSocket->waitForConnected(1000);
}

void Network_Client::delay(int time_to_wait)
{
    QTime dieTime= QTime::currentTime().addMSecs(time_to_wait);
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

void Network_Client::bytesWritten(qint64 bytes)
{
    //qDebug() << "We wrote: " << bytes;
}

void Network_Client::readyRead()
{
    qDebug() << "Reading ... ";
    QByteArray data{m_tcpSocket->readAll()};
    m_jsonState = (QJsonDocument(QJsonDocument::fromJson(data)).object());
    qDebug() << m_jsonState;
}

void Network_Client::pontUpClicked()
{
    qDebug() << "Pontograph Up!";
    QJsonObject json{};
    json.insert(VTI_DMI::PONTOGRAPH_UP, true);
    sendUpdate(json);
}

