

#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <broadcast.h>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    SystemController controller;
    Logger logger;
    Metrics metrics;
    UIUpdater uiUpdater;

    QObject::connect(&controller, &SystemController::systemStarted,
                     &logger, &Logger::onSystemStarted,Qt::QueuedConnection);

    QObject::connect(&controller, &SystemController::systemStarted,
                     &metrics, &Metrics::onSystemStarted,Qt::QueuedConnection);

    QObject::connect(&controller, &SystemController::systemStarted,
                     &uiUpdater, &UIUpdater::onSystemStarted,Qt::QueuedConnection);

    controller.startSystem();

    return app.exec();
}



