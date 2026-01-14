#include "candidatethread.h"

void CandidateThread::run() {
    // Wait for an available room
    ui->rooms.acquire(); // blocks if all 3 rooms are full

    int roomIndex = -1;

    // Get a room from the pool safely
    {
        QMutexLocker locker(&ui->poolMutex);
        if(!ui->availableRooms.isEmpty()){
            roomIndex = ui->availableRooms.dequeue();
        }
    } // when a thread checks for room availability no other thread will enter this blcok

    if(roomIndex == -1) roomIndex = 0; // fallback safety

    // Random number of questions
    int totalQ = QRandomGenerator::global()->bounded(5,16); // 5-15 questions

    for(int q=1; q<=totalQ; q++){
        msleep(QRandomGenerator::global()->bounded(50,301)); // 50-300 ms per question
        emit ui->updateRoom(roomIndex, candidate, q, totalQ);
    }

    // Clear room
    emit ui->clearRoom(roomIndex);

    // Update stats
    {
        QMutexLocker locker(&ui->uiMutex);
        ui->totalCandidatesDone++;
        emit ui->updateStats(ui->totalCandidatesDone, ui->totalCandidates - ui->totalCandidatesDone);
    } //UI of overall inverviews is updated no other thread will modify simultaneously

    // Return room to pool
    {
        QMutexLocker locker(&ui->poolMutex); //locks for pool
        ui->availableRooms.enqueue(roomIndex);
    }

    ui->rooms.release(); // free a slot in semaphore  - semaphore resource is release
}
