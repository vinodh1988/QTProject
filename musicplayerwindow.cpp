#include "musicplayerwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

// ---------------- Constructor ----------------
MusicPlayerWindow::MusicPlayerWindow(QWidget *parent)
    : QMainWindow(parent),
    currentSongIndex(0),
    progressValue(0)
{
    setupUI();
    loadSongs();
    setupStates();
    machine.start();
}

// ---------------- UI ----------------
void MusicPlayerWindow::setupUI()
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    stateLabel = new QLabel("STOPPED");
    stateLabel->setAlignment(Qt::AlignCenter);
    stateLabel->setStyleSheet("font-size:18px; font-weight:bold;");

    songLabel = new QLabel("No Song");
    songLabel->setAlignment(Qt::AlignCenter);

    progressBar = new QProgressBar;
    progressBar->setRange(0, 100);

    btnPlay = new QPushButton("▶ Play");
    btnPause = new QPushButton("⏸ Pause");
    btnStop = new QPushButton("⏹ Stop");
    btnNext = new QPushButton("⏭ Next");
    btnPrev = new QPushButton("⏮ Prev");

    QHBoxLayout *controls = new QHBoxLayout;
    controls->addWidget(btnPrev);
    controls->addWidget(btnPlay);
    controls->addWidget(btnPause);
    controls->addWidget(btnStop);
    controls->addWidget(btnNext);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stateLabel);
    layout->addWidget(songLabel);
    layout->addWidget(progressBar);
    layout->addLayout(controls);

    central->setLayout(layout);
}

// ---------------- Songs ----------------
void MusicPlayerWindow::loadSongs()
{
    for (int i = 1; i <= 10; ++i)
        songs << QString("Song %1").arg(i);

    updateSongLabel();
}

void MusicPlayerWindow::updateSongLabel()
{
    songLabel->setText("Now Playing: " + songs[currentSongIndex]);
}

void MusicPlayerWindow::nextSong()
{
    currentSongIndex = (currentSongIndex + 1) % songs.size();
    progressValue = 0;
    progressBar->setValue(0);
    updateSongLabel();
}

void MusicPlayerWindow::previousSong()
{
    currentSongIndex =
        (currentSongIndex - 1 + songs.size()) % songs.size();
    progressValue = 0;
    progressBar->setValue(0);
    updateSongLabel();
}

// ---------------- State Machine ----------------
void MusicPlayerWindow::setupStates()
{
    stopped = new QState(&machine);
    playing = new QState(&machine);
    paused  = new QState(&machine);

    // ---- STOPPED ----
    connect(stopped, &QState::entered, this, [&](){
        stateLabel->setText("STOPPED");
        progressTimer.stop();
        progressValue = 0;
        progressBar->setValue(0);

        btnPlay->setEnabled(true);
        btnPause->setEnabled(false);
        btnStop->setEnabled(false);
        btnNext->setEnabled(false);
        btnPrev->setEnabled(false);
    });

    // ---- PLAYING ----
    connect(playing, &QState::entered, this, [&](){
        stateLabel->setText("PLAYING");

        btnPlay->setEnabled(false);
        btnPause->setEnabled(true);
        btnStop->setEnabled(true);
        btnNext->setEnabled(true);
        btnPrev->setEnabled(true);

        progressTimer.start(100);
    });

    // ---- PAUSED ----
    connect(paused, &QState::entered, this, [&](){
        stateLabel->setText("PAUSED");
        progressTimer.stop();

        btnPlay->setEnabled(true);
        btnPause->setEnabled(false);
        btnStop->setEnabled(true);
        btnNext->setEnabled(true);
        btnPrev->setEnabled(true);
    });

    // ---- Transitions ----
    stopped->addTransition(btnPlay, &QPushButton::clicked, playing);
    playing->addTransition(btnPause, &QPushButton::clicked, paused);
    paused->addTransition(btnPlay, &QPushButton::clicked, playing);

    playing->addTransition(btnStop, &QPushButton::clicked, stopped);
    paused->addTransition(btnStop, &QPushButton::clicked, stopped);

    playing->addTransition(this, &MusicPlayerWindow::songFinished, playing);

    machine.setInitialState(stopped);

    // ---- Timer Logic ----
    connect(&progressTimer, &QTimer::timeout, this, [&](){
        progressValue++;
        progressBar->setValue(progressValue);

        if (progressValue >= 100) {
            nextSong();
            emit songFinished();
        }
    });

    // ---- Song Navigation ----
    connect(btnNext, &QPushButton::clicked, this, &MusicPlayerWindow::nextSong);
    connect(btnPrev, &QPushButton::clicked, this, &MusicPlayerWindow::previousSong);
}
