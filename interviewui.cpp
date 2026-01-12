#include "interviewui.h"
#include <QRandomGenerator>

InterviewUI::InterviewUI(QWidget *parent) : QWidget(parent), rooms(3), totalCandidatesDone(0), totalCandidates(100)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QGridLayout* grid = new QGridLayout();
    for(int i=0; i<3; ++i){
        roomLabels[i] = new QLabel("Room " + QString::number(i+1) + ": empty");
        roomProgress[i] = new QProgressBar();
        roomProgress[i]->setMinimum(0);
        roomProgress[i]->setMaximum(0);
        grid->addWidget(roomLabels[i], i, 0);
        grid->addWidget(roomProgress[i], i, 1);
        availableRooms.enqueue(i); // initially all rooms free
    }
    mainLayout->addLayout(grid);

    totalDoneLabel = new QLabel("Candidates Done: 0");
    leftLabel = new QLabel("Candidates Left: 100");
    mainLayout->addWidget(totalDoneLabel);
    mainLayout->addWidget(leftLabel);

    setLayout(mainLayout);

    connect(this, &InterviewUI::updateRoom, this, [=](int room, int candidate, int currQ, int totalQ){
        roomLabels[room]->setText(QString("Room %1: Candidate %2 (%3/%4)").arg(room+1).arg(candidate).arg(currQ).arg(totalQ));
        roomProgress[room]->setMaximum(totalQ);
        roomProgress[room]->setValue(currQ);
    });
    connect(this, &InterviewUI::clearRoom, this, [=](int room){
        roomLabels[room]->setText(QString("Room %1: empty").arg(room+1));
        roomProgress[room]->setMaximum(0);
        roomProgress[room]->setValue(0);
    });
    connect(this, &InterviewUI::updateStats, this, [=](int done, int left){
        totalDoneLabel->setText(QString("Candidates Done: %1").arg(done));
        leftLabel->setText(QString("Candidates Left: %1").arg(left));
    });
}
