#include <QCoreApplication>
#include <QDebug>

#include <QString>
#include <QByteArray>
#include <QVariant>
#include <QDate>
#include <QTime>
#include <QDateTime>

/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);


    QString text = "Qt Scalar";
    qInfo() << "QString:" << text;
    qInfo() << "Length:" << text.length();
    qInfo() << "Upper:" << text.toUpper();


    QByteArray bytes("ABC");
    bytes.append('\0');    // binary safe
    bytes.append("DEF");
    qInfo() << "QByteArray:" << bytes;
    qInfo() << "Size:" << bytes.size();


    QVariant v = 100;
    qInfo() << "QVariant int:" << v.toInt();

    v = "Variant String";
    qInfo() << "QVariant string:" << v.toString();

    QDate date = QDate::currentDate();
    qInfo() << "Current date:" << date.toString(Qt::ISODate);


    QTime time = QTime::currentTime();
    qInfo() << "Current time:" << time.toString();


    QDateTime now = QDateTime::currentDateTime();
    qInfo() << "Current datetime:" << now.toString(Qt::ISODate);

    return 0;
}
*/
