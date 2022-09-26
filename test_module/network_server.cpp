#include "network_server.h"

#include <QDebug>
#include <QString>

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

QJsonObject Network_Server::getUpdate()
{
    return m_jsonUpdate;
}

//Sends data through socket to client and returns true if all data were sent
bool Network_Server::sendUpdate(const QJsonObject &obj)
{
    QByteArray data = QJsonDocument{obj}.toJson();
    qint64 dataWritten = m_tcpSocket->write(data, qstrlen(data));

    // Less than 10 milliseconds and there is no gurantee all that will be processed correctly.
    delay(10);

    if(data.size() != dataWritten)
        return false;
    return true;
}

void Network_Server::delay(int time_to_wait)
{
    QTime dieTime= QTime::currentTime().addMSecs(time_to_wait);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Network_Server::newConnection()
{
    qDebug() << "Connecting";
    m_tcpSocket = m_tcpServer->nextPendingConnection();
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    m_tcpSocket->waitForBytesWritten(3000);
}

void Network_Server::readyRead()
{
    qDebug() << "Reading ... ";
    QByteArray data{m_tcpSocket->readAll()};
    m_jsonUpdate = (QJsonDocument(QJsonDocument::fromJson(data)).object());
    emit updateReceived();
}

