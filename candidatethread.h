#pragma once
#include <QThread>
#include <QRandomGenerator>
#include <QMutexLocker>
#include "InterviewUI.h"

class CandidateThread : public QThread {
    Q_OBJECT
public:
    CandidateThread(int candidateNumber, InterviewUI* ui) : candidate(candidateNumber), ui(ui) {}

protected:
    void run() override;

private:
    int candidate; // id of the candidate
    InterviewUI* ui;  // Interview UI which has resources room no
};
