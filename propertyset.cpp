#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QStateMachine>
#include <QState>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // ---------------- UI ----------------
    QWidget window;
    window.setWindowTitle("StateMachine Property Assignment");

    QLabel *label = new QLabel("OFF");
    label->setAlignment(Qt::AlignCenter);

    QPushButton *toggleBtn = new QPushButton("Toggle");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(label);
    layout->addWidget(toggleBtn);

    // ---------------- State Machine ----------------
    QStateMachine machine;

    QState *offState = new QState();
    QState *onState  = new QState();

    machine.addState(offState);
    machine.addState(onState);
    machine.setInitialState(offState);

    // ---------------- Property Assignment ----------------
    offState->assignProperty(label, "text", "OFF"); //you can assign property to any object when you are in a particular
    offState->assignProperty(label, "styleSheet", "color: red; font-size: 20px;");

    onState->assignProperty(label, "text", "ON");
    onState->assignProperty(label, "styleSheet", "color: green; font-size: 20px;");

    // ---------------- Transitions ----------------
    offState->addTransition(toggleBtn, &QPushButton::clicked, onState); //instead of timer even object events could be transition
    onState->addTransition(toggleBtn, &QPushButton::clicked, offState);

    machine.start();
    window.show();

    return app.exec();
}
