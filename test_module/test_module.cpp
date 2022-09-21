#include "test_module.h"

Test_Module::Test_Module(QObject *parent) : QObject(parent), m_networkServer{new Network_Server{}}, m_JSON{VTI_DMI::JSON_TEMPLATE}
{
    connect(m_networkServer, SIGNAL(updateReceived()), this, SLOT(receiveUpdate()));
}

Test_Module::~Test_Module()
{
    delete m_networkServer;
}

void Test_Module::receiveUpdate()
{
    QJsonObject tmp = m_networkServer->getUpdate();

    foreach(const QString& key, tmp.keys()) {
        if ( m_JSON.contains(key) )
        {
            QJsonValue value = tmp.value(key);
            qDebug() << "Key = " << key << ", Old value = " << m_JSON.value(key) << ", New value = " << value;
            m_JSON.insert(key, value);
        }
    }
}
