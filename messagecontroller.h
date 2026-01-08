#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include <QObject>
#include <QStringList>
#include <QTimer>

class MessageController : public QObject
{
    Q_OBJECT

public:
    explicit MessageController(QObject *parent = nullptr)
        : QObject(parent)
    {
        messages = {
            "Welcome to Qt",
            "Signals and Slots",
            "Qt is Event Driven",
            "Timers use Event Loop",
            "QObject is the base",
            "Widgets are UI",
            "QTimer emits signals",
            "Slots receive signals",
            "Loose coupling",
            "Clean architecture",
            "Embedded friendly",
            "Cross platform",
            "Meta object system",
            "Still counting...",
            "Done!"
        };

        connect(&timer, &QTimer::timeout,
                this, &MessageController::onTimeout);
    }

    void start()
    {
        timer.start(1000); // 1 seconds
    }

signals:
    void messageChanged(const QString &text);

private slots:
    void onTimeout()
    {
        if (index >= messages.size()) {
            timer.stop();
            return;
        }

        emit messageChanged(messages[index]);
        index++;
    }

private:
    QTimer timer;
    QStringList messages;
    int index = 0;
};

#endif // MESSAGECONTROLLER_H
