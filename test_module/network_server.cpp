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

QJsonObject const& Network_Server::getUpdate()
{
    return m_JSON;
}

void Network_Server::sendUpdate(const QJsonObject &obj)
{
    QByteArray data = QJsonDocument{obj}.toJson();
    m_tcpSocket->write(data, qstrlen(data));
    m_tcpSocket->flush();
}

void Network_Server::toJSON(QByteArray const& data)
{
    QJsonDocument doc{QJsonDocument::fromJson(data)};
    if(doc.isObject())
        m_JSON = doc.object();
    else
        qDebug() << "weird json format";

    foreach(const QString& key, m_JSON.keys()) {
        QJsonValue value = m_JSON.value(key);
        qDebug() << "Key = " << key << ", Value = " << value;
    }
}

void Network_Server::newConnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();

    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    m_tcpSocket->waitForBytesWritten(3000);
}

void Network_Server::readyRead()
{
    qDebug() << "Reading ... ";
    QByteArray data{m_tcpSocket->readAll()};
    toJSON(data);
    emit updateReceived();
}

