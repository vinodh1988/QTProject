#include <QCoreApplication>
#include "temperaturesensor.h"
#include "objectprocess.h"
#include "car.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QObject *obj = new TemperatureSensor(); // returned as QObject*

    processQObject(obj); //this processes temperatureSensor  (since tempsensor is subclass of QObject it reads props of both Qobject & T senso

    obj = new Car();
    processQObject(obj);

    delete obj;
    return 0;
}

