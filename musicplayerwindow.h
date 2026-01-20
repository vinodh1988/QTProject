#ifndef MUSICPLAYERWINDOW_H
#define MUSICPLAYERWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QStateMachine>
#include <QState>
#include <QTimer>
#include <QStringList>

class MusicPlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MusicPlayerWindow(QWidget *parent = nullptr);
    ~MusicPlayerWindow() = default;

signals:
    void songFinished();

private:
    // UI
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QPushButton *btnNext;
    QPushButton *btnPrev;
    QLabel *stateLabel;
    QLabel *songLabel;
    QProgressBar *progressBar;

    // State machine
    QStateMachine machine;
    QState *stopped;
    QState *playing;
    QState *paused;

    // Music data
    QStringList songs;
    int currentSongIndex;
    int progressValue;

    // Timer
    QTimer progressTimer;

    void setupUI();
    void setupStates();
    void loadSongs();
    void updateSongLabel();
    void nextSong();
    void previousSong();
};

#endif
