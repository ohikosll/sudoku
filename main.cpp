#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Helper.h"
#include <QQmlContext>
//Qt 5.15.2 (GCC 7.3.1 20180303 (Red Hat 7.3.1-5), 64 бита)
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
    Helper helper;
    engine.rootContext()->setContextProperty("helper", &helper);
    engine.load(url);
    return app.exec();
}
