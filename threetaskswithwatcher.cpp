#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QStringList>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QDebug>
/*
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
    for (int i = 1; i <= 100; ++i) numbers << i;

    QStringList names = {"alice", "bob", "carol", "dave", "eve", "frank", "grace", "heidi", "ivan", "judy"};

    // Watchers
    QFutureWatcher<int> watcherSum; //observer that looks for changes happening in an asynchronous task that is returning a future
    QFutureWatcher<QString> watcherNames;
    QFutureWatcher<int> watcherOddSum;

    // Connect finished signals to lambdas
    QObject::connect(&watcherSum, &QFutureWatcher<int>::finished, [&]() {
        qDebug() << "Sum of numbers:" << watcherSum.result();
    });
    QObject::connect(&watcherNames, &QFutureWatcher<QString>::finished, [&]() {
        qDebug() << "Uppercase names:" << watcherNames.result();
    });
    QObject::connect(&watcherOddSum, &QFutureWatcher<int>::finished, [&]() {
        qDebug() << "Sum of odd numbers:" << watcherOddSum.result();
        // Quit after all tasks (assuming this is the last to finish)
        a.quit();
    });

    // Start concurrent tasks
    watcherSum.setFuture(QtConcurrent::run(sumWithSleep, numbers));
    watcherNames.setFuture(QtConcurrent::run(upperNamesWithSleep, names));
    watcherOddSum.setFuture(QtConcurrent::run(sumOddWithSleep, numbers));

    return a.exec();
}
*/
