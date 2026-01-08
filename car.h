#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QDebug>

class Car : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)

public:
    explicit Car(QObject *parent = nullptr);

    int speed() const; // returns value of m_speed
    void setSpeed(int value); // sets value of m_speed also emits the signal speedChanged()

signals:
    void speedChanged(int newSpeed);

private:
    int m_speed; //instance variable which will processed with the help of a property called speed
};

#endif
