#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
/*
int main() {
    QString filePath = "d://datafiles/store.txt";
    QFile file(filePath);
    qDebug() << file .fileName()  << "" << QFileInfo(file).absoluteFilePath();


    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file:" << file.errorString();
        return 1;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
    }

    file.close();
    return 0;
}*/
