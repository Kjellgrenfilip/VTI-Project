#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QJsonObject>
#include <QJsonDocument>

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


    json.insert(VTI_DMI::BUTTON_1, true);
    json.insert(VTI_DMI::BUTTON_2, false);
    json.insert(VTI_DMI::VELOCITY, 100);
    json.insert(VTI_DMI::VOLTAGE, 10.0);

    Network_Client n_Client{};
    n_Client.connectToServer();
    n_Client.sendUpdate(json);

    return app.exec();
}
