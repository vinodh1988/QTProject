#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream cin(stdin);
    QTextStream cout(stdout);

    cout << "Enter Sno: ";
    cout.flush();
    QString sno = cin.readLine();

    cout << "Enter Name: ";
    cout.flush();
    QString name = cin.readLine();

    cout << "Enter City: ";
    cout.flush();
    QString city = cin.readLine();

    QFile file("d:/datafiles/storex.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << sno << "," << name << "," << city << "\n";
        file.close();
        cout << "Data written to file.\n";
    } else {
        cout << "Failed to open file for writing.\n";
    }

    return 0;
}
