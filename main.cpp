#include <QCoreApplication>
#include<QDebug>
#include<QTimer>
/*
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.
    qDebug() << "First QT Program";
    qDebug() << "Second QT Program";

    QTimer::singleShot(2000,[](){
        qDebug()<<"Timer Fired";
        QCoreApplication::quit();
    });// the block of code will only execute after two seconds and it moves line 27 even before 2 seconds

    return a.exec(); // starts the event loop
}*/
