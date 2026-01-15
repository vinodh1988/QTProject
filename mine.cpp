#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QSemaphore>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>
/*
// ---------- Constants ----------
const int TOTAL_MINERS = 100;
const int MAX_MINERS_IN_MINE = 5;
const double MIN_TIME = 0.25; // seconds
const double MAX_TIME = 5.0;  // seconds
const int HIT_INTERVAL_MS = 30;
const int MAX_MINERAL_KG = 500000;

// ---------- Miner Record ----------
struct MinerRecord {
    QString name;
    double timeSpent;      // seconds
    int rounds;            // number of hits
    int kgsMined;
};

// ---------- Semaphore to limit miners in the mine ----------
QSemaphore mineSemaphore(MAX_MINERS_IN_MINE);

// ---------- Miner Task ----------
MinerRecord mineMiner(const QString &minerName)
{
    MinerRecord record;
    record.name = minerName;
    record.rounds = 0;
    record.kgsMined = 0;

    // Random mining time for this miner (fixed bounded ambiguity)
    double miningTimeSec = QRandomGenerator::global()->bounded(
                               static_cast<int>(MIN_TIME * 1000),
                               static_cast<int>(MAX_TIME * 1000)
                               ) / 1000.0;

    QElapsedTimer timer; // elapsed timer to used to calculcat the time since timer is started
    timer.start();

    while (timer.elapsed() / 1000.0 < miningTimeSec)
    {
        QThread::msleep(HIT_INTERVAL_MS); // simulate mining hit
        int minedKg = QRandomGenerator::global()->bounded(1, 51); // 1-50 kg
        record.kgsMined += minedKg;
        record.rounds++;

        if (record.kgsMined >= MAX_MINERAL_KG) // stop if max reached
            break;
    }

    record.timeSpent = timer.elapsed() / 1000.0; // seconds
    return record;
}

// ---------- Worker Function ----------
MinerRecord minerWorker(const QString &minerName)
{
    mineSemaphore.acquire(); // only 5 miners in mine at once
    qDebug() << minerName << "entered the mine";

    MinerRecord result = mineMiner(minerName);

    qDebug() << minerName << "leaving mine, mined:"
             << result.kgsMined << "kg in" << result.rounds << "rounds";

    mineSemaphore.release();
    return result;
}

// ---------- Main ----------
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QVector<QString> minerNames;
    for (int i = 1; i <= TOTAL_MINERS; ++i)
        minerNames.append(QString("Miner%1").arg(i));

    QVector<QFuture<MinerRecord>> futures;
    QVector<MinerRecord> results;

    // Launch miners asynchronously
    for (const QString &name : minerNames)
        futures.append(QtConcurrent::run(minerWorker, name)); //100 miners are added into q concurrent thread poll

    // Wait for all miners to finish
    for (auto &f : futures)
    {
        f.waitForFinished();
        results.append(f.result());
    }

    // Write CSV file to D:/
    QFile file("D:/mining_results.csv");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qWarning() << "Cannot open file for writing!";
        return -1;
    }

    QTextStream out(&file);
    out << "MinerName,TimeSpent(s),Rounds,KgsMined\n";
    for (const MinerRecord &r : results)
    {
        out << r.name << ","
            << QString::number(r.timeSpent, 'f', 2) << ","
            << r.rounds << ","
            << r.kgsMined << "\n";
    }

    file.close();
    qDebug() << "CSV file generated at D:/mining_results.csv";

    return 0;
}
*/
