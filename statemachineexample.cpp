#include <QCoreApplication>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QDebug>
#include <QTimer>
/*
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStateMachine machine; // way to create a state machine

    QState *state1 = new QState(); //state 1
    QState *state2 = new QState(); //state 2
    QFinalState *finalState = new QFinalState(); //final state

    QTimer state1timer;
    QTimer state2timer;

    state1timer.setInterval(2000);       // 2 seconds
    state2timer.setInterval(3000);

    state1 ->addTransition( &state1timer, &QTimer::timeout,state2);
    state2 ->addTransition(&state2timer,  &QTimer::timeout,finalState);

    QObject::connect(state1, &QState::entered, [&]() {
        qDebug() << "Entered State 1";
        state1timer.start();
    });
    QObject::connect(state2, &QState::entered, [&]() {
        qDebug() << "Entered State 2";
        state2timer.start();
    });
    QObject::connect(finalState, &QFinalState::entered, [&]() {
        qDebug() << "Entered Final State";


    });
    QObject::connect(&machine, &QStateMachine::finished, []() {
        qDebug() << "State machine finished";
        QCoreApplication::quit();
    });

    machine.addState(state1);
    machine.addState(state2);
    machine.addState(finalState);
    machine.setInitialState(state1);

    machine.start();

    return a.exec();
}
*/
