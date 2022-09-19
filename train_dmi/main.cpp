#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QJsonObject>
#include <QJsonDocument>

#include "network_client.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QJsonObject json{};

    json.insert("Test0", 10);
    json.insert("Test1", QJsonValue::Null);
    json.insert("Test2", true);
    json.insert("Test3", false);
    json.insert("Test4", "Hejsan");
    json.insert("Test5", 100);
    json.insert("Test6", 10.0);

    Network_Client n_Client{};
    n_Client.connectToServer();
    n_Client.sendMessage(QJsonDocument{json}.toJson());

    return app.exec();
}
