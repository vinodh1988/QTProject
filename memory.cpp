#include <QCoreApplication>
#include "plain.h"
#include "controller.h"
#include "device.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    {

        PlainObject* obj=new PlainObject();
        delete obj;

        QObject* parent=new QObject();
        Controller* child=new Controller(parent);
        Device* child2=new Device(parent);

        delete parent; // In QT memory management if parent object is deleted automatically child object is delelted
    } // controller goes  out of scope here

    return 0;
}

