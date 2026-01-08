#ifndef EVENTS_H
#define EVENTS_H

#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QEvent>
#include <QTimer>

/* ---------- Custom Event ---------- */
class MyEvent : public QEvent {
public:
    static const QEvent::Type MyType = static_cast<QEvent::Type>(QEvent::User + 1);

    MyEvent(int data,QEventLoop* x)
        : QEvent(MyType), data(data) {
        loop=x;
    }
    int data;
    QEventLoop* loop;
}; // your own event?  you have to extend EvenClass

/* ---------- Event Processor ---------- */
class EventProcessor : public QObject {
    Q_OBJECT
protected:
    bool event(QEvent* e) override {
        if (e->type() == MyEvent::MyType) {
            MyEvent* myEvent = static_cast<MyEvent*>(e);
            qDebug() << "[EventProcessor] Received custom event with data:" << myEvent->data;
            myEvent->loop->quit();
            return true; // event handled
        }
        return QObject::event(e);
    }
};





#endif // EVENTS_H
