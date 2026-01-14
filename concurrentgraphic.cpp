#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>

// Heavy computation function
long long heavyCalculation()
{
    long long sum = 0;
    for (long long i = 1; i <= 100000000; ++i)
    {
        sum += i;
    }
    return sum;
} // in case of signal and slot mechanism normal function cannot be run asynchronously it has to qobject subclass member function

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QtConcurrent::run Demo");

    QPushButton *startButton = new QPushButton("Start Calculation");
    QLabel *statusLabel = new QLabel("Status: Idle");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(startButton);
    layout->addWidget(statusLabel);
    window.setLayout(layout);

    // Future watcher
    QFutureWatcher<long long> *watcher = new QFutureWatcher<long long>(&window);

    // Button click → start background task
    QObject::connect(startButton, &QPushButton::clicked, [&]()
                     {
                         statusLabel->setText("Status: Calculating...");
                         startButton->setEnabled(false);

                         QFuture<long long> future = QtConcurrent::run(heavyCalculation);
                         watcher->setFuture(future);
                     });

    // When calculation finishes
    QObject::connect(watcher, &QFutureWatcher<long long>::finished, [&]()
                     {
                         long long result = watcher->result();
                         statusLabel->setText("Result: " + QString::number(result));
                         startButton->setEnabled(true);
                     });

    window.resize(300, 150);
    window.show();

    return app.exec();
}

