#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTime>
#include <QQmlContext>

#include "network_client.h"
#include "network_interface.h"

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

    json.insert(VTI_DMI::PONTOGRAPH_UP, false);
    json.insert(VTI_DMI::BUTTON_2, false);
    json.insert(VTI_DMI::VELOCITY, 0);
    json.insert(VTI_DMI::VOLTAGE, 10.0);

    Network_Client n_Client{};
    n_Client.connectToServer();

    QQmlContext *rootContext = engine.rootContext();
    rootContext->setContextProperty("network", &n_Client);

//    for(int i{1}; i < 1000; i++)
//    {
//        json.insert(VTI_DMI::VELOCITY, i);
//        n_Client.sendUpdate(json);
//    }
    return app.exec();
}
