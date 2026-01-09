#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString sno="123";
    QString name="Roger";
    QString city="Ranchi";


    QFile file("d:/datafiles/storex.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << sno << "," << name << "," << city << "\n";
        file.close();
        qDebug() << "Data written to file.\n";
    } else {
        qDebug() << "Failed to open file for writing.\n";
    }

    return 0;
}
