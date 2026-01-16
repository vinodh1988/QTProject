#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H


#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QTimer>
#include <QPushButton>
#include "messageholder.h"

class MessageProcessingWidget : public QWidget
{
    Q_OBJECT

public:
    MessageProcessingWidget(QWidget *parent = nullptr)
        : QWidget(parent),
        m_holder(new MessageHolder(this)),
        m_queueSizeLabel(new QLabel(this)),
        m_statusLabel(new QLabel(this)),
        m_messageLabel(new QLabel(this)),
        m_processedCount(0)
    {
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(new QLabel("Queue Size:", this));
        layout->addWidget(m_queueSizeLabel);
        layout->addWidget(new QLabel("Status:", this));
        layout->addWidget(m_statusLabel);
        layout->addWidget(new QLabel("Current Message:", this));
        layout->addWidget(m_messageLabel);

        setLayout(layout);

        connect(m_holder, &MessageHolder::messagecreated, this, &MessageProcessingWidget::updateQueueSize);

        setupStateMachine();
        updateQueueSize();
    }

private slots:
    void updateQueueSize()
    {
        m_queueSizeLabel->setText(QString::number(m_holder->qsize()));
        // Above line is a workaround; ideally, MessageHolder should provide a queueSize() method.
    }

    void processMessage()
    {
        QString msg = m_holder->read();
        if (msg!="Queue is empty") {
            m_messageLabel->setText(msg);
            m_processedCount++;
        } else {
            m_messageLabel->setText("No message - Queue is empty - no message to process");
        }
        updateQueueSize();
    }

    void updateStatus(const QString &status)
    {
        m_statusLabel->setText(status);
    }

    void resetProcessedCount()
    {
        m_processedCount = 0;
    }

private:
    MessageHolder *m_holder;
    QLabel *m_queueSizeLabel; //display queuesize
    QLabel *m_statusLabel; // to display which state is active now
    QLabel *m_messageLabel; // to show current message
    int m_processedCount; // number of message processed used processing state <=10

    void setupStateMachine()
    {
        QStateMachine *machine = new QStateMachine(this); //create state machine

        QState *restState = new QState();
        QState *processingState = new QState();
        QState *maintenanceState = new QState();

        // REST STATE
        //restState->assignProperty(m_statusLabel, "text", "Resting");
        connect(restState, &QState::entered, this, [this]() {
            updateStatus("Resting");
        });

        // PROCESSING STATE
      //  processingState->assignProperty(m_statusLabel, "text", "Processing");
        connect(processingState, &QState::entered, this, [this]() {
            updateStatus("Processing");
            processMessage();
        });

        // MAINTENANCE STATE
       // maintenanceState->assignProperty(m_statusLabel, "text", "Maintenance");
        connect(maintenanceState, &QState::entered, this, [this]() {
            updateStatus("Maintenance");
            m_messageLabel->setText("In maintenance...");
        });

        // Timers for state transitions
        QTimer *restTimer = new QTimer(this);
        restTimer->setSingleShot(true);
        QTimer *maintenanceTimer = new QTimer(this);
        maintenanceTimer->setSingleShot(true);

        // Transitions
        restState->addTransition(restTimer, &QTimer::timeout, processingState);//after onesecond to processing state
        processingState->addTransition(this, &MessageProcessingWidget::processed10Messages, maintenanceState);
        processingState->addTransition(this, &MessageProcessingWidget::processedLessThan10, restState);
        maintenanceState->addTransition(maintenanceTimer, &QTimer::timeout,processingState);

        // State entered actions
        connect(restState, &QState::entered, restTimer, [restTimer]() {
            restTimer->start(1000);
        }); // timer starts and runs for 1 second

        connect(processingState, &QState::entered, this, [this]() {
            if (m_processedCount >= 10) {
                emit processed10Messages();
            } else {
                emit processedLessThan10();
            }
        });

        connect(maintenanceState, &QState::entered, maintenanceTimer, [maintenanceTimer, this]() {
            maintenanceTimer->start(10000);
            resetProcessedCount();
        }); //timeer starts for 10 seconds and processed count reset to zero

        machine->addState(restState);
        machine->addState(processingState);
        machine->addState(maintenanceState);//three states added to machine
        machine->setInitialState(restState); // initial state is rest
        machine->start();
    }

signals:
    void processed10Messages();
    void processedLessThan10();
};

#endif // MESSAGEWINDOW_H
