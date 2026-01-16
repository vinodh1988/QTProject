#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QStateMachine>
#include <QState>
#include <QTimer>
#include <QFont>
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // -------- UI --------
    QWidget window;
    window.setWindowTitle("Butterfly Life Cycle - State Machine");
    window.setFixedSize(350, 250);

    QLabel *stageLabel = new QLabel;
    stageLabel->setAlignment(Qt::AlignCenter);

    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    stageLabel->setFont(font);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stageLabel);
    window.setLayout(layout);
    window.show();

    // -------- State Machine --------
    QStateMachine machine;

    QState *eggState       = new QState(&machine);
    QState *larvaState     = new QState(&machine);
    QState *pupaState      = new QState(&machine);
    QState *butterflyState = new QState(&machine);

    // -------- Timers --------
    QTimer eggTimer;
    QTimer larvaTimer;
    QTimer pupaTimer;
    QTimer butterflyTimer;

    eggTimer.setInterval(2000);       // 2 seconds
    larvaTimer.setInterval(3000);     // 3 seconds
    pupaTimer.setInterval(4000);      // 4 seconds
    butterflyTimer.setInterval(3000); // 3 seconds

    // -------- State Behavior --------
    QObject::connect(eggState, &QState::entered, [&]() {
        stageLabel->setText("🥚 Egg");
        eggTimer.start();
    });

    QObject::connect(larvaState, &QState::entered, [&]() {
        stageLabel->setText("🐛 Larva (Caterpillar)");
        larvaTimer.start();
    });

    QObject::connect(pupaState, &QState::entered, [&]() {
        stageLabel->setText("🟤 Pupa (Chrysalis)");
        pupaTimer.start();
    });

    QObject::connect(butterflyState, &QState::entered, [&]() {
        stageLabel->setText("🦋 Butterfly (Adult)");
        butterflyTimer.start();
    });

    // -------- Transitions --------
    eggState->addTransition(&eggTimer, &QTimer::timeout, larvaState);
    larvaState->addTransition(&larvaTimer, &QTimer::timeout, pupaState);
    pupaState->addTransition(&pupaTimer, &QTimer::timeout, butterflyState);
    butterflyState->addTransition(&butterflyTimer, &QTimer::timeout, eggState);

    machine.setInitialState(eggState);
    machine.start();

    return app.exec();
}
*/
