#include "sender.h"
#include <thread>
#include <chrono>

Sender::Sender(QObject *parent)
    : QObject(parent)
{
}

void Sender::doWork()
{
    qDebug() << "Sender: doing work";

    int result = 42;
    while(true) {
         std::this_thread::sleep_for(std::chrono::seconds(2));
    // Emit signal
         emit workDone(result); //invoking the signal
    }
}
