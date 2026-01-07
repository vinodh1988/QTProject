#ifndef BROADCAST_H
#define BROADCAST_H

#include <QCoreApplication>
#include <QObject>
#include <QDebug>

/* ---------- Broadcaster ---------- */
class SystemController : public QObject {
    Q_OBJECT
public:
    void startSystem() {
        qDebug() << "[SystemController] Starting system";
        emit systemStarted();
        qDebug() << "[SystemController] Start sequence finished";
    }
signals:
    void systemStarted();
};

/* ---------- Listener 1 ---------- */
class Logger : public QObject {
    Q_OBJECT
public slots:
    void onSystemStarted() {
        qDebug() << "[Logger] System start logged";
    }
};

/* ---------- Listener 2 ---------- */
class Metrics : public QObject {
    Q_OBJECT
public slots:
    void onSystemStarted() {
        qDebug() << "[Metrics] Metrics initialized";
    }
};

/* ---------- Listener 3 ---------- */
class UIUpdater : public QObject {
    Q_OBJECT
public slots:
    void onSystemStarted() {
        qDebug() << "[UIUpdater] UI updated";
    }
};



#endif // BROADCAST_H
