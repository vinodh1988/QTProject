#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <QObject>

class TemperatureSensor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double temperature
                   READ temperature
                       WRITE setTemperature
                           NOTIFY temperatureChanged)

public:
    explicit TemperatureSensor(QObject *parent = nullptr)
        : QObject(parent) {}

    double temperature() const {
        return m_temperature;
    }

    void setTemperature(double t) {
        if (qFuzzyCompare(m_temperature, t))
            return;
        m_temperature = t;
        emit temperatureChanged();
    }

signals:
    void temperatureChanged();

private:
    double m_temperature = 25.0;
};


#endif // TEMPERATURESENSOR_H
