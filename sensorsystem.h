#ifndef SENSORSYSTEM_H
#define SENSORSYSTEM_H

#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QThread>

/* ---------- Sensor (Sender) ---------- */
class Sensor : public QObject {
    Q_OBJECT
public:
    void readValue() {
        qDebug() << "[Sensor] Reading value";
        emit valueReady(42); //in direct connection immediatly the execution is blocked here are redirected to slot
        qDebug() << "[Sensor] Continuing after emit";
    }
signals:
    void valueReady(int value);
};

/* ---------- Controller (Receiver) ---------- */
class Receiver : public QObject {
    Q_OBJECT
public slots:
    void processValue(int value) {
        qDebug() << "[Controller] Processing value:" << value;
        QThread::sleep(2);   // simulate heavy processing
        qDebug() << "[Controller] Processing done";
    }
};

#endif // SENSORSYSTEM_H
