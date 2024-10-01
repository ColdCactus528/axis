#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick3D/qquick3d.h>
#include "axis.h"
#include "handlerQVector3D.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QSurfaceFormat::setDefaultFormat(QQuick3D::idealSurfaceFormat());

    qmlRegisterType<Line>("linesExample", 1, 0, "Line");
    qmlRegisterType<Axis>("linesExample", 1, 0, "Axis");
    qmlRegisterType<HandlerQVector3D>("linesExample", 1, 0, "HandlerQVector3D");


    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);
    engine.loadFromModule("linesExample", "Main");

    return app.exec();
}
