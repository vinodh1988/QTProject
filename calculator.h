#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QObject>
#include <QThread>
#include <QDebug>

// Worker object
class Calculator : public QObject
{
    Q_OBJECT

public:
    long long calculate()
    {
        long long sum = 0;

        for (long long i = 1; i <= 100000; ++i)
        {
            sum += i;


            // Emit progress every 5000 numbers
            if (i % 5000 == 0)
            {
                qDebug() << "notified";
                QThread::msleep(100);
                emit progress(i); //it signals
            }
        }
        return sum; //it returns
    }

signals:
    void progress(long long value);
};

#endif // CALCULATOR_H
