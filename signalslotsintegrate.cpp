#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QThread>
#include "sensorsystem.h"
/*
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Sensor sensor;
    Receiver controller;

    QObject::connect(&sensor, &Sensor::valueReady,
                     &controller, &Receiver::processValue,
                     Qt::DirectConnection); //connects signal & Slot - direct connection does not need event loop

    sensor.readValue();

    return 0;
}

*/
