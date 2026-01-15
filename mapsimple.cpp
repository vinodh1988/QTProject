#include <QtConcurrent/QtConcurrent>
#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QThread>

// Function to be applied to each element
void square(int &x) {
    qDebug() << "Executed by" << QThread::currentThread() << " number processed is " << x;
    x = x * x;
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QVector<int> numbers = {1, 2, 3, 4, 5,34,5,5,7,8,4};

    // Use QtConcurrent::map to apply 'square' to each element
    // Note: map modifies in-place, but for demonstration, let's use mapped for a new container
    QFuture<void> future = QtConcurrent::map(numbers, square);

    future.waitForFinished();

    qDebug() << "After process" << numbers;
    return 0;
}
