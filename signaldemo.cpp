#include <QCoreApplication>
#include <QDebug>
#include "sender.h"
/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Sender sender;

    // Connect signal to slot (lambda used as slot)
    QObject::connect(&sender, &Sender::workDone,
                     [](int value) {
                         qDebug() << "Slot: received result =" << value;
                     });

    sender.doWork();   // triggers signal

    return 0;
}
*/

