#include "network_server.h"

#include <QDebug>

Network_Server::Network_Server() : QObject(), m_tcpServer{new QTcpServer{this}}
{
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!m_tcpServer->listen(QHostAddress::Any, 1200))
        qDebug() << "Server could not start";
    else
        qDebug() << "Server started";
}

Network_Server::~Network_Server()
{
    delete m_tcpServer;
    delete m_tcpSocket;
}

void Network_Server::newConnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();

    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    m_tcpSocket->write("hello client \r\n");
    m_tcpSocket->flush();

    m_tcpSocket->waitForBytesWritten(3000);
}

void Network_Server::readyRead()
{
    qDebug() << "Reading ... ";
    qDebug() << m_tcpSocket->readAll();
}
