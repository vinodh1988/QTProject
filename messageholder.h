#ifndef MESSAGEHOLDER_H
#define MESSAGEHOLDER_H

#include <QObject>
#include <QQueue>
#include <QTimer>
#include <QDateTime>
#include <QRandomGenerator>
#include <QString>
// message holder continously produces message and holds in the queue

//whenever somebody read the them message message it deques and returns the message
class MessageHolder : public QObject
{
    Q_OBJECT

public:
    explicit MessageHolder(QObject *parent = nullptr)
        : QObject(parent)
    {
        connect(&m_timer, &QTimer::timeout, this, &MessageHolder::messageProducer); //event binding
        scheduleNextProduction();
    }

    // Returns and removes the next message from the queue, or empty string if none
    QString read()
    {
        if (m_queue.isEmpty())
            return "Queue is empty";
        return m_queue.dequeue(); //removes the front message and returns
    } // read is going to be used state machine for processing

    int qsize() {
        return m_queue.size(); // it returns size of the queue
    } // to print queue size this is used

signals:
    void messagecreated(const QString &message); // this is used to update queuesize

private slots:
    void messageProducer()
    {
        // Generate a random message
        QString message = QString("Message at %1")
                              .arg(QDateTime::currentDateTime().toString(Qt::ISODate));
        m_queue.enqueue(message);
        emit messagecreated(message);
        scheduleNextProduction();
    }

private:
    QQueue<QString> m_queue; // queue to hold messages
    QTimer m_timer; //timer to control message production

    void scheduleNextProduction()
    {
        int interval = QRandomGenerator::global()->bounded(1000, 3000); // 1-3 seconds
        m_timer.start(interval);
    }

};

#endif // MESSAGEHOLDER_H
