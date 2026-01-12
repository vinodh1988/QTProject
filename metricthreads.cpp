#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QThread>
#include <QFont>

#include "metricexpose.h"
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    QWidget window;
    window.setWindowTitle("System Health Dashboard");

    QLabel cpuLabel("CPU Load: -- %");
    QLabel memLabel("Memory Usage: -- %");
    QLabel netLabel("Network Traffic: -- kbps");

    QFont font;
    font.setPointSize(14);
    font.setBold(true);

    cpuLabel.setFont(font);
    memLabel.setFont(font);
    netLabel.setFont(font);

    QVBoxLayout layout;
    layout.addWidget(&cpuLabel);
    layout.addWidget(&memLabel);
    layout.addWidget(&netLabel);

    window.setLayout(&layout);
    window.resize(300, 150);
    window.show();


    QThread cpuThread, memThread, netThread;
    CpuWorker cpuWorker;
    MemoryWorker memWorker;
    NetworkWorker netWorker;

    cpuWorker.moveToThread(&cpuThread);
    memWorker.moveToThread(&memThread);
    netWorker.moveToThread(&netThread);

    QObject::connect(&cpuThread, &QThread::started,
                     &cpuWorker, &CpuWorker::run);
    QObject::connect(&memThread, &QThread::started,
                     &memWorker, &MemoryWorker::run);
    QObject::connect(&netThread, &QThread::started,
                     &netWorker, &NetworkWorker::run);

    QObject::connect(&cpuWorker, &CpuWorker::valueChanged,
                     [&](int v){ cpuLabel.setText("CPU Load: " + QString::number(v) + " %"); });

    QObject::connect(&memWorker, &MemoryWorker::valueChanged,
                     [&](int v){ memLabel.setText("Memory Usage: " + QString::number(v) + " %"); });

    QObject::connect(&netWorker, &NetworkWorker::valueChanged,
                     [&](int v){ netLabel.setText("Network Traffic: " + QString::number(v) + " kbps"); });

    cpuThread.start();
    memThread.start();
    netThread.start();

    return app.exec();
}
*/
