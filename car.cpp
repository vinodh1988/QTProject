#include "car.h"

Car::Car(QObject *parent)
    : QObject(parent), m_speed(0)
{
    qDebug() << "Car constructed";
}

int Car::speed() const
{
    qDebug() << "READ speed() called";
    return m_speed;
}

void Car::setSpeed(int value)
{
    qDebug() << "WRITE setSpeed() called with:" << value;

    if (m_speed == value)
        return;

    m_speed = value;
    emit speedChanged(m_speed);
}
