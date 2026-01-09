#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("d:/datafiles/config.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file!";
        return 1;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);
    if (doc.isNull()) {
        qWarning() << "JSON parse error:" << parseError.errorString();
        return 1;
    }

    QJsonObject obj = doc.object();

    qDebug() << "appName:" << obj.value("appName").toString();
    qDebug() << "version:" << obj.value("version").toString();
    qDebug() << "theme:" << obj.value("theme").toString();
    qDebug() << "autoSave:" << obj.value("autoSave").toBool();
    qDebug() << "maxNotes:" << obj.value("maxNotes").toInt();
    qDebug() << "backupInterval:" << obj.value("backupInterval").toInt();
    qDebug() << "language:" << obj.value("language").toString();

    QJsonObject userObj = obj.value("user").toObject();
    qDebug() << "User:";
    qDebug() << "  name:" << userObj.value("name").toString();
    qDebug() << "  email:" << userObj.value("email").toString();
    qDebug() << "  notifications:" << userObj.value("notifications").toBool();

    return 0;
}
