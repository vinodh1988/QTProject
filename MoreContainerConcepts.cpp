#include <QList>
#include <QVector>
#include <QDebug>

int main() {
    QList<int> list;
    list << 1 << 2 << 3 << 4;

    // Convert QList to QVector
    QVector<int> vector = list.toVector();

    // Convert QVector back to QList
    QList<int> list2 = vector.toList();

    qDebug() << "QList:" << list;
    qDebug() << "QVector:" << vector;
    qDebug() << "QList2:" << list2;


    QList<QString> animals;
    animals << "cat" << "dog" << "bird" << "cat" << "dog" << "fish";

    // Slice: take the first 4 elements
    QList<QString> sublist = animals.mid(0, 4);

    // Convert the sublist to a set (removes duplicates)
    QSet<QString> animalSet = QSet<QString>(animals.begin(),animals.end());

    qDebug() << "Original list:" << animals;
    qDebug() << "Sliced sublist:" << sublist;
    qDebug() << "Set from sublist (unique):" << animalSet;


    return 0;
}
