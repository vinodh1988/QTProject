#ifndef WORKERS_H
#define WORKERS_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT

public slots:
    void doWork()
    {
        for (int i = 1; i <= 5; ++i) {
            qDebug() << "Working in thread:" << QThread::currentThread()
            << "step:" << i;
            QThread::sleep(1);
        }

        emit finished();
    }

signals:
    void finished();
};

#endif // WORKERS_H
