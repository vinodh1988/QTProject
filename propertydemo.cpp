#include <QCoreApplication>
#include <QDebug>
#include "car.h"
#include <QVariant>

/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Car car;

    QObject::connect(&car, &Car::speedChanged,
                     [](int value) {
                         qDebug() << "NOTIFY speedChanged received:" << value;
                     });


    qDebug() << "Property value:" << car.property("speed").toInt(); //speed() function will be called
    car.setProperty("speed", 80); // calls setspeed because write is connected to setsppeed

    qDebug() << "Property value:" << car.property("speed").toInt(); //speed() function will be called

    car.setSpeed(100);
    qDebug() << "Property value:" << car.property("speed").toInt(); //speed() function will be called



    return 0;
}
*/
