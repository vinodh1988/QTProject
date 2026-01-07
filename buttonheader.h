#ifndef BUTTONHEADER_H
#define BUTTONHEADER_H

#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QThread>

/* ---------- ButtonLogic ---------- */
class ButtonLogic : public QObject {
    Q_OBJECT
public:
    void onButtonPressed() {
        qDebug() << "[ButtonLogic] Button pressed";
        emit logRequired(); // signal is raised, in blocking mechanism - direct connection - the control directly goes to handler
        qDebug() << "[ButtonLogic] UI logic continues";
    }
signals:
    void logRequired();
};

/* ---------- DataLogger ---------- */
class DataLogger : public QObject {
    Q_OBJECT
public slots:
    void writeLog() {
        qDebug() << "[DataLogger] Writing log...";
        QThread::sleep(2);          // heavy / blocking I/O
        qDebug() << "[DataLogger] Log written";
    }
};

#endif // BUTTONHEADER_H
