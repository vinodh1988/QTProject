#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QThread>
#include <buttonheader.h>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    ButtonLogic buttonLogic; //signal
    DataLogger dataLogger; //slot

    QObject::connect(&buttonLogic, &ButtonLogic::logRequired,
                     &dataLogger, &DataLogger::writeLog,
                    //Qt::DirectConnection
                     Qt::QueuedConnection //uses event loop
                     );

    buttonLogic.onButtonPressed(); //event

    return app.exec();
}


