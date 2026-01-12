#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "threadsources.h"
/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "Main thread:" << QThread::currentThread();

    QThread printerThread; //Qthread1
    QThread testerThread; //QThread2
    QThread reviewerThread; //QThread3

    Printer printer;
    Tester tester;
    Reviewer reviewer;

    printer.moveToThread(&printerThread); //printer is added Qthread1
    tester.moveToThread(&testerThread); //tester is added ot Qthread2
    reviewer.moveToThread(&reviewerThread); //reveiwer is added to qthread3

    QObject::connect(&printerThread, &QThread::started,
                     &printer, &Printer::print);

    QObject::connect(&testerThread, &QThread::started,
                     &tester, &Tester::test);

    QObject::connect(&reviewerThread, &QThread::started,
                     &reviewer, &Reviewer::review);

    QObject::connect(&printer, &Printer::finished,
                     &printerThread, &QThread::quit);

    QObject::connect(&tester, &Tester::finished,
                     &testerThread, &QThread::quit);

    QObject::connect(&reviewer, &Reviewer::finished,
                     &reviewerThread, &QThread::quit);

    int finishedCount = 0;

    auto onThreadFinished = [&]() {
        finishedCount++;
        qDebug() << "Tasks completed:" << finishedCount;

        if (finishedCount == 3) {
            qDebug() << "All tasks done. Exiting application.";
            QCoreApplication::quit();
        }
    };

    QObject::connect(&printerThread, &QThread::finished, &app, onThreadFinished);
    QObject::connect(&testerThread, &QThread::finished, &app, onThreadFinished);
    QObject::connect(&reviewerThread, &QThread::finished, &app, onThreadFinished);

    printerThread.start();
    testerThread.start();
    reviewerThread.start();

    return app.exec();
}*/
