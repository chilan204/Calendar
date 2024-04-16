#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controller.h"
#include "appenum.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterUncreatableType<AppEnum>("AppEnum", 1, 0, "AppEnum", "Not creatable as it is an enum type");
    engine.rootContext()->setContextProperty("CTRL", Controller::getInstance());
    engine.rootContext()->setContextProperty("SV_MODEL", Controller::getInstance()->svModel());
    engine.rootContext()->setContextProperty("DAY_MODEL", Controller::getInstance()->dayModel());

    const QUrl url(QStringLiteral("qrc:/ui/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
