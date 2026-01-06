#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include "device.h"

/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Device device; // Qobject subclass meta object system enabled

    // 1️⃣ Runtime introspection
    qDebug() << "Class name:"
             << device.metaObject()->className();

    // 2️⃣ Runtime method invocation by name
    QMetaObject::invokeMethod(&device, "start");

    return 0;
}
*/
