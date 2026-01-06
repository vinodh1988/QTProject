#include <QCoreApplication>
#include <QDebug>

#include <QList>
#include <QVector>
#include <QMap>
#include <QSet>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);


    QList<int> list;
    list << 1 << 2 << 3;
    qInfo() << "QList:";

    for (int v : list)
        qInfo() << v;


    QVector<int> vector;
    vector << 10 << 20 << 30;
    qInfo() << "QVector:";
    for (int v : vector)
        qInfo() << v;


    QMap<QString, int> map;
    map["Alice"] = 90;
    map["Bob"] = 85;

    qInfo() << "QMap:";
    for (auto it = map.begin(); it != map.end(); ++it)
    qInfo()<< it.key() << " -> " << it.value();

        QSet<QString> set;
    set.insert("Qt");
    set.insert("Qt");   // duplicate ignored
    set.insert("C++");

    qInfo() << "QSet:";
    for (const auto &s : set)
        qInfo() << s;

    return 0;
}
/*

/*
 *  Set in unordered
 *  Set is index based
 *  Set does not allow duplicates
 */
