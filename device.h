#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QDebug>

class Device : public QObject
{
    Q_OBJECT

public:
    explicit Device(QObject* parent = nullptr)
        : QObject(parent)
    {
    }

    Q_INVOKABLE void start()
    {
        qDebug() << "Device started via meta-object system";
    }
};

#endif // DEVICE_H
