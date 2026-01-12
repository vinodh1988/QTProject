// ================= restaurant.h =================
// Header-only logic for Producer–Consumer with priority and bounded buffer

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QRandomGenerator>
#include <QQueue>

/* ================= FoodContainer (Shared Resource) ================= */
class FoodContainer : public QObject {
    Q_OBJECT
public:
    explicit FoodContainer(QObject *parent = nullptr)
        : QObject(parent), cakes(0) {}

    void produce(const QString &cookName) {
        QMutexLocker locker(&mutex); // whenever a cook produces and adds cake to container mutex lock is acquired

        while (cakes == MAX_CAKES) {
            emit log(cookName + " waiting (container full)");
            notFull.wait(&mutex); // lock is temporarily released
        } // produce will wait until container gets cleared

        //production logic
        int freeSpace = MAX_CAKES - cakes; // if free space is less than 5 produce exact amount of cakes to full the container
        // if freespace is greater than 5 , the producer will produce any number of cakes randome 1-freespace+1
        int produced = (freeSpace <= 5)
                           ? freeSpace
                           : QRandomGenerator::global()->bounded(1, freeSpace + 1);

        cakes += produced;
        emit log(cookName + " produced " + QString::number(produced) + " cakes. Total=" + QString::number(cakes));
        emit cakeCountChanged(cakes);

        notEmpty.wakeAll();// this is used to nofity that container is not empty anymore
    }

    void consume(const QString &tableName) {
        QMutexLocker locker(&mutex);

        //when somebody sits on the table , they will give the order
        // the logic here is a customer is allowed to order max 20 cakes at a time
        int order = QRandomGenerator::global()->bounded(1, MAX_CAKES / 2 + 1);
        bool loggedWaiting = false;

        if (!waitingTables.contains(tableName))
            waitingTables.enqueue(tableName);

        while (waitingTables.head() != tableName || cakes < order) {
            if (!loggedWaiting) {
                emit log(tableName + " ordered " + QString::number(order) + " cakes and waiting");
                loggedWaiting = true;
            }
            notEmpty.wait(&mutex); // lock is released temporarily
        }

        waitingTables.dequeue();
        cakes -= order;

        emit log(tableName + " received " + QString::number(order) + " cakes. Total=" + QString::number(cakes));
        emit cakeCountChanged(cakes);

        notFull.wakeAll();
    }

signals:
    void log(const QString &msg);
    void cakeCountChanged(int count);

private:
    static const int MAX_CAKES = 40; //max capacity
    int cakes; //default to zero
    QMutex mutex; // to handle mutex locking
    QWaitCondition notEmpty;  // controls waiting in inter thread communiction - this signal used when ever cake is produced
    QWaitCondition notFull; // this signal is used when an order is dispatched
    QQueue<QString> waitingTables; // there are the two tables and tables are added in the quee
};

/* ================= Worker Threads ================= */
class Cook : public QThread {
public:
    Cook(const QString &name, FoodContainer *c)
        : cookName(name), container(c) {}

    void run() override {
        while (true) {
            QThread::sleep(QRandomGenerator::global()->bounded(1, 3));
            container->produce(cookName); //cook produces cakes
        }
    } // this method runs whenever thread is started

private:
    QString cookName;
    FoodContainer *container;
};

class Table : public QThread {
public:
    Table(const QString &name, FoodContainer *c)
        : tableName(name), container(c) {}

    void run() override {
        while (true) {
            QThread::sleep(QRandomGenerator::global()->bounded(1, 4));
            container->consume(tableName); // table consumes cakes
        }
    }

private:
    QString tableName;
    FoodContainer *container;
};

#endif // RESTAURANT_H

