#include <QApplication>
#include "musicplayerwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MusicPlayerWindow w;
    w.show();
    return a.exec();
}

