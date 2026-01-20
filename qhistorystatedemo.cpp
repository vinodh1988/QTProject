#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QStateMachine>
#include <QState>
#include <QHistoryState>
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    QWidget window;
    window.setWindowTitle("QHistoryState - Proper Demonstration");

    QLabel *status = new QLabel("Status: Idle");

    QPushButton *startBtn  = new QPushButton("Start");
    QPushButton *nextBtn   = new QPushButton("Next");
    QPushButton *pauseBtn  = new QPushButton("Pause");
    QPushButton *resumeBtn = new QPushButton("Resume");
    QPushButton *resetBtn  = new QPushButton("Reset");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(status);
    layout->addWidget(startBtn);
    layout->addWidget(nextBtn);
    layout->addWidget(pauseBtn);
    layout->addWidget(resumeBtn);
    layout->addWidget(resetBtn);

    // ---------------- State Machine ----------------
    QStateMachine machine;

    QState *idle   = new QState(); //initial state
    QState *working = new QState(); //it has substates
    QState *paused = new QState(); //normal state

    // Substates of working
    QState *step1 = new QState(working); //substates of working
    QState *step2 = new QState(working); //substate of working

    // 🔥 History remembers last active step
    QHistoryState *history = new QHistoryState(working);
    history->setDefaultState(step1);

    // Required
    working->setInitialState(step1);

    machine.addState(idle);
    machine.addState(working);
    machine.addState(paused);
    machine.setInitialState(idle);

    // ---------------- Transitions ----------------

    // Enter working fresh
    idle->addTransition(startBtn, &QPushButton::clicked, working);

    // Pause leaves the compound state
    working->addTransition(pauseBtn, &QPushButton::clicked, paused);

    // Resume re-enters via HISTORY
    paused->addTransition(resumeBtn, &QPushButton::clicked, history);  // paused to resume (history is the transition)

    // Internal progress
    step1->addTransition(nextBtn, &QPushButton::clicked, step2);

    // Reset from anywhere
    idle->addTransition(resetBtn, &QPushButton::clicked, idle);
    paused->addTransition(resetBtn, &QPushButton::clicked, idle);
    working->addTransition(resetBtn, &QPushButton::clicked, idle);

    // ---------------- UI CONTROL ----------------
    QObject::connect(idle, &QState::entered, [&]() {
        status->setText("State: Idle");

        startBtn->setEnabled(true);
        nextBtn->setEnabled(false);
        pauseBtn->setEnabled(false);
        resumeBtn->setEnabled(false);
    });

    QObject::connect(step1, &QState::entered, [&]() {
        status->setText("State: Working - Step 1");

        startBtn->setEnabled(false);
        nextBtn->setEnabled(true);
        pauseBtn->setEnabled(true);
        resumeBtn->setEnabled(false);
    });

    QObject::connect(step2, &QState::entered, [&]() {
        status->setText("State: Working - Step 2");

        startBtn->setEnabled(false);
        nextBtn->setEnabled(false);
        pauseBtn->setEnabled(true);
        resumeBtn->setEnabled(false);
    });

    QObject::connect(paused, &QState::entered, [&]() {
        status->setText("State: Paused");

        startBtn->setEnabled(false);
        nextBtn->setEnabled(false);
        pauseBtn->setEnabled(false);
        resumeBtn->setEnabled(true);
    });

    machine.start();
    window.show();

    return app.exec();
}*/
