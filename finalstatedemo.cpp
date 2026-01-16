#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QTimer>
#include <QDebug>
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // ---------------- UI ----------------
    QWidget window;
    window.setWindowTitle("Installer Demo - QFinalState");

    QLabel *label = new QLabel("Welcome to Installer");
    QPushButton *nextBtn = new QPushButton("Next");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(label);
    layout->addWidget(nextBtn);

    // ---------------- State Machine ----------------
    QStateMachine installer;

    QState *welcome = new QState();
    QState *license = new QState();
    QState *install = new QState();
    QState *verify  = new QState();
    QFinalState *done = new QFinalState(); //it is categorized as final state

    installer.addState(welcome);
    installer.addState(license);
    installer.addState(install);
    installer.addState(verify);
    installer.addState(done);

    installer.setInitialState(welcome);

    // ---------------- Transitions ----------------
    welcome->addTransition(nextBtn, &QPushButton::clicked, license);
    license->addTransition(nextBtn, &QPushButton::clicked, install);
    install->addTransition(nextBtn, &QPushButton::clicked, verify);
    verify->addTransition(nextBtn, &QPushButton::clicked, done);

    // ---------------- State Entry Actions ----------------
    QObject::connect(welcome, &QState::entered, [&](){
        label->setText("Welcome Screen");
        nextBtn->setText("Next");
    });

    QObject::connect(license, &QState::entered, [&](){
        label->setText("Accept License Agreement");
    });

    QObject::connect(install, &QState::entered, [&](){
        label->setText("Installing files...");
    });

    QObject::connect(verify, &QState::entered, [&](){
        label->setText("Verifying installation...");
    });

    // 🔥 FINAL COMPLETION POINT
    QObject::connect(&installer, &QStateMachine::finished, [&](){
        qDebug() << "Installation completed successfully!";
        label->setText("Installation Complete!");
        nextBtn->setEnabled(false);

        // Simulate launching installed application
        QTimer::singleShot(3500, &app, &QApplication::quit);
    });

    installer.start();
    window.show();

    return app.exec();
}*/
