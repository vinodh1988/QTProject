#ifndef SPEEDCONTROLLER_H
#define SPEEDCONTROLLER_H

#include <QObject>

class SpeedController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)

public:
    explicit SpeedController(QObject *parent = nullptr)
        : QObject(parent)
    {
    }

    int speed() const
    {
        return m_speed;
    }

public slots:
    void setSpeed(int s)
    {
        if (m_speed == s)
            return;

        m_speed = s;
        emit speedChanged(m_speed);
    }

signals:
    void speedChanged(int newSpeed);

private:
    int m_speed = 0;
};

#endif // SPEEDCONTROLLER_H
