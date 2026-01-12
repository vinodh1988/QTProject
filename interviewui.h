#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QProgressBar>
#include <QMutex>
#include <QSemaphore>
#include <QQueue>

class InterviewUI : public QWidget {
    Q_OBJECT
public:
    InterviewUI(QWidget *parent = nullptr);

    QSemaphore rooms;          // max 3 rooms
    QMutex uiMutex;            // mutex for stats update

    QLabel* roomLabels[3];
    QProgressBar* roomProgress[3];

    QLabel* totalDoneLabel;
    QLabel* leftLabel;

    int totalCandidatesDone;
    int totalCandidates;

    QMutex poolMutex;          // mutex for room pool
    QQueue<int> availableRooms; // pool of available room numbers

signals:
    void updateRoom(int roomIndex, int candidateNum, int currentQuestion, int totalQuestions); ///room stats
    void clearRoom(int roomIndex);
    void updateStats(int done, int left); // update totaldone and totaleft variable
};
