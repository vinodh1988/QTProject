#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "speedcontroller.h"
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt Property + Signal Demo (Header-only)");


    QLabel *label = new QLabel("Speed: 0");
    QPushButton *button = new QPushButton("Increase Speed");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(label);
    layout->addWidget(button);

    SpeedController controller;

    QObject::connect(&controller, &SpeedController::speedChanged,
                     label, [=](int value) {
                         label->setText("Speed: " + QString::number(value));
                     });

    QObject::connect(button, &QPushButton::clicked,
                     [&]() {
                         controller.setSpeed(controller.speed() + 10);
                     });

    window.show();
    return app.exec();
}*/
