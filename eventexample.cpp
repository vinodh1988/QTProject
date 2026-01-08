#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QEvent>
#include <QTimer>
#include<events.h>

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    EventProcessor processor;

    // Create a local event loop
    QEventLoop loop; // manually creating event loop context

    // Post a custom event after 1 second
    QTimer::singleShot(1000, [&](){
        qDebug() << "[Main] Posting custom event";
        QCoreApplication::postEvent(&processor, new MyEvent(42,&loop));

        // Quit local event loop after posting
        //loop.quit();
    });

    // Run local event loop (blocks here until loop.quit())
    qDebug() << "[Main] Starting local event loop";
    loop.exec();
    qDebug() << "[Main] Local event loop finished";

    return 0;
}

