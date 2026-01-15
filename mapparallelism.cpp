#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QThread>
#include <QVector>
/*
// Function applied to each element (runs in thread pool)
void squareNumber(int &value)
{
    // Slow down to visualize parallelism
    QThread::msleep(50);
    qDebug() << "VAlue processed" << value << QThread::currentThread();
    value = value * value;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QtConcurrent::map Demo");

    QPushButton *startButton = new QPushButton("Start Processing");
    QProgressBar *progressBar = new QProgressBar;
    QLabel *statusLabel = new QLabel("Status: Idle");

    progressBar->setRange(0, 100);
    progressBar->setValue(0);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(startButton);
    layout->addWidget(progressBar);
    layout->addWidget(statusLabel);
    window.setLayout(layout);

    // Data container
    QVector<int> numbers;
    for (int i = 1; i <= 100; ++i)
        numbers.append(i);

    QFutureWatcher<void> *watcher =
        new QFutureWatcher<void>(&window);

    // Progress updates
    QObject::connect(watcher, &QFutureWatcher<void>::progressValueChanged,
                     [&](int value)
                     {
                         progressBar->setValue(value);
                         statusLabel->setText(
                             "Status: Processed " + QString::number(value) + " items");
                     });

    // Finished
    QObject::connect(watcher, &QFutureWatcher<void>::finished, [&]()
                     {
                         statusLabel->setText("Status: Completed");
                         startButton->setEnabled(true);
                     });

    // Start button
    QObject::connect(startButton, &QPushButton::clicked, [&]()
                     {
                         startButton->setEnabled(false);
                         progressBar->setValue(0);
                         statusLabel->setText("Status: Processing...");

                         QFuture<void> future =
                             QtConcurrent::map(numbers, squareNumber);

                         watcher->setFuture(future);
                     });

    window.resize(350, 180);
    window.show();

    return app.exec();
}
*/
