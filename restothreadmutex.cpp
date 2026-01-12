// ================= main.cpp =================

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include "restaurant.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt Producer-Consumer (Restaurant)");
    window.resize(600, 400);

    QVBoxLayout *layout = new QVBoxLayout(&window);
    QLabel *countLabel = new QLabel("Cakes in container: 0");
    QTextEdit *logView = new QTextEdit;
    logView->setReadOnly(true);

    layout->addWidget(countLabel);
    layout->addWidget(logView);

    FoodContainer container; //container object is create here

    QObject::connect(&container, &FoodContainer::log,
                     [&](const QString &msg) { logView->append(msg); });

    QObject::connect(&container, &FoodContainer::cakeCountChanged,
                     [&](int count) {
                         countLabel->setText("Cakes in container: " + QString::number(count));
                     });

    Cook cook1("Cook1", &container); //thread1
    Cook cook2("Cook2", &container); //thread2
    Table table1("Table1", &container); //thread3
    Table table2("Table2", &container); //thread4

    cook1.start();
    cook2.start();
    table1.start();
    table2.start();

    window.show();
    return app.exec();
}
