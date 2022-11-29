#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTime>
#include <QQmlContext>
#include "network_client.h"
#include "dmi_handler.h"


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

    DMI_Handler dmiHandler{engine.rootContext(), engine.rootObjects().at(0), &engine};

  /*  QSizePolicy p = app.devicePixelRatio();
    p.setHeightForWidth(true);
    this->setSizePolicy(p);*/

    return app.exec();
}
