#include <QtCore>
#include <QtConcurrent/QtConcurrent>
#include <functional>
/*
// The map function must take a single argument (const reference to an item in the input sequence)
// and return the new result type. It should be a free function, static member function,
// or a lambda function without captures for direct use with QtConcurrent::mapped().
int stringLength(const QString &str) {
    return str.length();
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // 1. Define the input sequence (container)
    QStringList inputs;
    inputs << "apple" << "banana" << "cherry" << "date";

    qDebug() << "Input list:" << inputs;

    // 2. Call QtConcurrent::mapped() with the sequence and the map function
    // This returns a QFuture object, which manages the asynchronous computation.
    QFuture<int> future = QtConcurrent::mapped(inputs, stringLength);

    // 3. (Optional) Use blockingMapped if you need the results immediately in the current thread
    // QList<int> results = QtConcurrent::blockingMapped(inputs, stringLength);

    // 4. Retrieve the results when they are ready
    // You can wait for the computation to finish and then access the results.
    future.waitForFinished();
    QList<int> results = future.results();

    qDebug() << "Mapped results (string lengths):" << results;

    // Example output:
    // Input list: ("apple", "banana", "cherry", "date")
    // Mapped results (string lengths): (5, 6, 6, 4)

    return 0;
}
*/
