#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include "messagecontroller.h"
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Signal-Slot Timer Demo");

    QLabel *label = new QLabel("Starting...");
    label->setAlignment(Qt::AlignCenter);
    label->setMinimumSize(300, 100);

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(label);

    MessageController controller;

    QObject::connect(&controller, &MessageController::messageChanged,
                     label, &QLabel::setText);

    controller.start(); //start the timer

    window.show();
    return app.exec();
}

*/
