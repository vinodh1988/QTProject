#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QDebug>

class Sender : public QObject
{
    Q_OBJECT

public:
    explicit Sender(QObject *parent = nullptr);

    void doWork();   // normal function

signals:
    void workDone(int result);   // signal

};

#endif // SENDER_H
