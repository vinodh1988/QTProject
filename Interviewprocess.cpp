#include <QApplication>
#include "interviewui.h"
#include "candidatethread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InterviewUI ui;
    ui.show();

    // Launch 100 candidates
    for(int i=1;i<=100;i++){
        CandidateThread* t = new CandidateThread(i, &ui);
        t->start();
    }

    return a.exec();
}
