#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QStateMachine>
#include <QState>
#include <QTimer>
// Helper function to create a light
QLabel* createLight(const QString& color)
{
    QLabel *label = new QLabel;
    label->setFixedSize(100, 100);
    label->setStyleSheet(
        "border-radius:50px;"
        "background-color:" + color + ";"
                  "border:2px solid black;"
        );
    return label;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // -------- UI --------
    QWidget window;
    window.setWindowTitle("Traffic Signal - State Machine");

    QLabel *redLight    = createLight("darkred");
    QLabel *yellowLight = createLight("darkgoldenrod");
    QLabel *greenLight  = createLight("black");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(redLight);
    layout->addWidget(yellowLight);
    layout->addWidget(greenLight);

    window.setLayout(layout);
    window.show();

    // -------- State Machine --------
    QStateMachine machine;

    QState *redState    = new QState(&machine);
    QState *greenState  = new QState(&machine);
    QState *yellowState = new QState(&machine);

    // -------- Timers --------
    QTimer redTimer;
    QTimer greenTimer;
    QTimer yellowTimer;

    redTimer.setInterval(3000);     // 3 seconds
    greenTimer.setInterval(3000);   // 3 seconds
    yellowTimer.setInterval(1500);  // 1.5 seconds

    // -------- State Behavior --------
    QObject::connect(redState, &QState::entered, [&]() {
        redLight->setStyleSheet("border-radius:50px; background-color:red;");
        yellowLight->setStyleSheet("border-radius:50px; background-color:darkgoldenrod;");
        greenLight->setStyleSheet("border-radius:50px; background-color:black;");
        redTimer.start();
    });

    QObject::connect(greenState, &QState::entered, [&]() {
        redLight->setStyleSheet("border-radius:50px; background-color:darkred;");
        yellowLight->setStyleSheet("border-radius:50px; background-color:darkgoldenrod;");
        greenLight->setStyleSheet("border-radius:50px; background-color:green;");
        greenTimer.start();
    });

    QObject::connect(yellowState, &QState::entered, [&]() {
        redLight->setStyleSheet("border-radius:50px; background-color:darkred;");
        yellowLight->setStyleSheet("border-radius:50px; background-color:yellow;");
        greenLight->setStyleSheet("border-radius:50px; background-color:black;");
        yellowTimer.start();
    });

    // -------- Transitions --------
    redState->addTransition(&redTimer, &QTimer::timeout, greenState);
    greenState->addTransition(&greenTimer, &QTimer::timeout, yellowState);
    yellowState->addTransition(&yellowTimer, &QTimer::timeout, redState);

    machine.setInitialState(redState);
    machine.start();

    return app.exec();
}
