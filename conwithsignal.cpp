#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QObject>
#include <QThread>
#include <calculator.h>
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QtConcurrent Progress (Slowed)");

    QPushButton *startButton = new QPushButton("Start Calculation");
    QLabel *statusLabel = new QLabel("Status: Idle");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(startButton);
    layout->addWidget(statusLabel);
    window.setLayout(layout);

    Calculator *calculator = new Calculator;

    QFutureWatcher<long long> *watcher =
        new QFutureWatcher<long long>(&window);

    // Progress updates (runs in UI thread)
    QObject::connect(calculator, &Calculator::progress,
                     [&](long long value)
                     {
                         statusLabel->setText(
                             "Status: Processed " + QString::number(value));
                     });

    // Start computation
    QObject::connect(startButton, &QPushButton::clicked, [&]()
                     {
                         startButton->setEnabled(false);
                         statusLabel->setText("Status: Calculating...");

                         QFuture<long long> future =
                             QtConcurrent::run([calculator]() {
                             qDebug() << "this is calculated";
                                 return calculator->calculate();
                             }); // if you want to call a member function of Qobject sub type use this syntax to call by using qconcurrent


                         watcher->setFuture(future);
                     });

    // Completion
    QObject::connect(watcher, &QFutureWatcher<long long>::finished, [&]()
                     {
                         long long result = watcher->result();
                         statusLabel->setText("Result: " + QString::number(result));
                         startButton->setEnabled(true);
                     });

    window.resize(380, 160);
    window.show();

    return app.exec();
}
*/
