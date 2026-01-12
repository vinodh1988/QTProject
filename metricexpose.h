#ifndef METRICEXPOSE_H
#define METRICEXPOSE_H


#include <QObject>
#include <QThread>
#include <QRandomGenerator>

/* -------- CPU Monitor -------- */
class CpuWorker : public QObject
{
    Q_OBJECT
public slots:
    void run()
    {
        while (true) {
            int value = QRandomGenerator::global()->bounded(0, 101);
            emit valueChanged(value);
            QThread::sleep(1);
        }
    }
signals:
    void valueChanged(int);
};

/* -------- Memory Monitor -------- */
class MemoryWorker : public QObject
{
    Q_OBJECT
public slots:
    void run()
    {
        while (true) {
            int value = QRandomGenerator::global()->bounded(20, 90);
            emit valueChanged(value);
            QThread::sleep(2);
        }
    }
signals:
    void valueChanged(int);
};

/* -------- Network Monitor -------- */
class NetworkWorker : public QObject
{
    Q_OBJECT
public slots:
    void run()
    {
        while (true) {
            int value = QRandomGenerator::global()->bounded(100, 1000);
            emit valueChanged(value);
            QThread::sleep(1);
        }
    }
signals:
    void valueChanged(int);
};



#endif // METRICEXPOSE_H
