#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>

// Task 1 function
void task1() {
    for (int i = 0; i < 5; ++i) {
        qDebug() << "Task 1 running, iteration:" << i;
        QThread::sleep(1); // Simulate work
    }
}

// Task 2 function
void task2() {
    for (int i = 0; i < 5; ++i) {
        qDebug() << "Task 2 running, iteration:" << i;
        QThread::sleep(1); // Simulate work
    }
}


// Main function
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Run task1 and task2 asynchronously
    QFuture<void> future1 = QtConcurrent::run(task1); // it runs this fun asynchronously in the background
    QFuture<void> future2 = QtConcurrent::run(task2);

    // Wait for both tasks to finish
    future1.waitForFinished(); // since there is no return value
    future2.waitForFinished(); // since there is no return value

    return 0;
}
