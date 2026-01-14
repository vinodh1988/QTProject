#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QStringList>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QDebug>

// Function 1: Sum numbers, sleep every 10 iterations
int sumWithSleep(const QList<int>& numbers) {
    int sum = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
        if ((i + 1) % 10 == 0) {
            QThread::msleep(5);
        }
    }
    return sum;
}

// Function 2: Uppercase names, sleep for each, return comma-separated string
QString upperNamesWithSleep(const QStringList& names) {
    QStringList upperNames;
    for (const QString& name : names) {
        upperNames << name.toUpper();
        QThread::msleep(10);
    }
    return upperNames.join(",");
}

// Function 3: Filter odd numbers, sum, sleep for each odd
int sumOddWithSleep(const QList<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        if (num % 2 != 0) {
            sum += num;
            QThread::msleep(10);
        }
    }
    return sum;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Prepare data
    QList<int> numbers;
    for (int i = 1; i <= 100; ++i) numbers << i; //1 to 100 numbers to list numbers

    QStringList names = {"alice", "bob", "carol", "dave", "eve", "frank", "grace", "heidi", "ivan", "judy"};

    // Run functions concurrently
    QFuture<int> futureSum = QtConcurrent::run(sumWithSleep, numbers);
    QFuture<QString> futureNames = QtConcurrent::run(upperNamesWithSleep, names);
    QFuture<int> futureOddSum = QtConcurrent::run(sumOddWithSleep, numbers);

    // Wait for results
    futureSum.waitForFinished(); // blocking the flow
    futureNames.waitForFinished();
    futureOddSum.waitForFinished();

    // Get results
    qDebug() << "Sum of numbers:" << futureSum.result();
    qDebug() << "Uppercase names:" << futureNames.result();
    qDebug() << "Sum of odd numbers:" << futureOddSum.result();

    return 0;
}
