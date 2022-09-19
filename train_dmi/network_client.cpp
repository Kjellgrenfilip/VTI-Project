#include "network_client.h"

#include <QDebug>

Network_Client::Network_Client() : QObject(), m_tcpSocket{new QTcpSocket{this}}
{
    connect(m_tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(m_tcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
}

Network_Client::~Network_Client()
{
    delete m_tcpSocket;
}

void Network_Client::sendMessage(char const*data)
{
    m_tcpSocket->write(data, qstrlen(data));
    m_tcpSocket->flush();
}

void Network_Client::connectToServer()
{
    qDebug() << "Connecting .... ";
    m_tcpSocket->connectToHost("127.0.0.1", 1200);
    m_tcpSocket->waitForConnected(1000);
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
    qDebug() << "We wrote: " << bytes;
}

void Network_Client::readyRead()
{
    qDebug() << "Reading ... ";
    qDebug() << m_tcpSocket->readAll();
}

