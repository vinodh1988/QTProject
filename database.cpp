#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    /*
    qDebug() << "Available SQL drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach (const QString& driver, drivers)
        qDebug() << driver;*/


    if (!QFile::exists("D:/qt.db")) {
        QMessageBox::critical(nullptr,
                              "Error",
                              "Database file D:/qt.db not found");
        return -1;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/qtdb.db");

    if (!db.open()) {
        QMessageBox::critical(nullptr,
                              "Database Error",
                              db.lastError().text());
        return -1;
    }

    QWidget window;
    window.setWindowTitle("Add Person (SQLite)");
    window.resize(320, 160);

    QLabel *nameLabel = new QLabel("Name:");
    QLabel *cityLabel = new QLabel("City:");

    QLineEdit *nameEdit = new QLineEdit;
    QLineEdit *cityEdit = new QLineEdit;

    QPushButton *insertBtn = new QPushButton("Insert");

    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEdit);

    QHBoxLayout *cityLayout = new QHBoxLayout;
    cityLayout->addWidget(cityLabel);
    cityLayout->addWidget(cityEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(cityLayout);
    mainLayout->addWidget(insertBtn);

    window.setLayout(mainLayout);

    QObject::connect(insertBtn, &QPushButton::clicked, [&]() {

        QString name = nameEdit->text().trimmed();
        QString city = cityEdit->text().trimmed();

        if (name.isEmpty() || city.isEmpty()) {
            QMessageBox::warning(&window,
                                 "Validation Error",
                                 "Name and City cannot be empty");
            return;
        }

        QSqlQuery query(db);
        query.prepare(
            "INSERT INTO person (`name`, `city`) "
            "VALUES (:name, :city)"
            );

        query.bindValue(":name", name);
        query.bindValue(":city", city);

        if (!query.exec()) {
            QMessageBox::critical(&window,
                                  "Insert Error",
                                  query.lastError().text());
            qDebug() << query.lastError();
        } else {
            QMessageBox::information(&window,
                                     "Success",
                                     "Record inserted successfully");
            nameEdit->clear();
            cityEdit->clear();
        }
    });

    window.show();
    return app.exec();
}
