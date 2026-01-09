#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "workers.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "Main thread:" << QThread::currentThread();

    QThread workerThread; //just creating object for Qthread
    Worker worker; //just creating object for worker - it is not a thread

    // Move worker to another thread
    worker.moveToThread(&workerThread); // Worker is converted as QThread by adding it to QThread

    // Start work when thread starts
    QObject::connect(&workerThread, &QThread::started,
                     &worker, &Worker::doWork); // if qthread is started  ,do work is the logic for the thread

    // Stop thread when work is done
    QObject::connect(&worker, &Worker::finished,
                     &workerThread, &QThread::quit); //you are calling inbuilt slot called quite

    QObject::connect(&workerThread, &QThread::finished,
                     &app, &QCoreApplication::quit); // you are quiting the application itself

    workerThread.start(); // a signal call QThread:started will occure

    return app.exec();
}
