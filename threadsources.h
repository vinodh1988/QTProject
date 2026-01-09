#ifndef THREADSOURCES_H
#define THREADSOURCES_H

#include <QObject>
#include <QThread>
#include <QDebug>

/* ---------- Printer Thread ---------- */
class Printer : public QObject
{
    Q_OBJECT
public slots:
    void print()
    {
        for (int i = 1; i <= 100; ++i) {
            qDebug() << "Printer printing paper" << i
                     << "Thread:" << QThread::currentThread();
            QThread::msleep(30);
        }
        emit finished();
    }
signals:
    void finished();
};

/* ---------- Tester Thread ---------- */
class Tester : public QObject
{
    Q_OBJECT
public slots:
    void test()
    {
        for (int i = 1; i <= 50; ++i) {
            qDebug() << "Tester testing function" << i
                     << "Thread:" << QThread::currentThread();
            QThread::msleep(50);
        }
        emit finished();
    }
signals:
    void finished();
};

/* ---------- Reviewer Thread ---------- */
class Reviewer : public QObject
{
    Q_OBJECT
public slots:
    void review()
    {
        for (int i = 1; i <= 40; ++i) {
            qDebug() << "Reviewer reviewing file" << i
                     << "Thread:" << QThread::currentThread();
            QThread::msleep(70);
        }
        emit finished();
    }
signals:
    void finished();
};

#endif // THREADSOURCES_H
