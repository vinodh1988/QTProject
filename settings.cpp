#include <QCoreApplication>
#include <QSettings>
#include <QDebug>
/*
int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

#ifdef PROJECT_DIR
    qDebug() << "project dir";
#endif

    // Use INI file format explicitly, stored in the current directory

    QSettings settings("setting.ini", QSettings::IniFormat);
    qDebug() << settings.fileName();
    qDebug()<< settings.allKeys();
    // ---- Write settings (only if not already present) ----
    if (!settings.contains("window/width")) {
        settings.setValue("window/width", 1024);
        settings.setValue("window/height", 768);
        settings.setValue("user/name", "Alice");
        settings.setValue("user/age", 30);
        qDebug() << "Default settings written.";
    } else {
        qDebug() << "Settings already exist. Reading them...";
    }

    // ---- Read settings ----
    int width = settings.value("window/width").toInt();
    int height = settings.value("window/height").toInt();
    QString name = settings.value("user/name").toString();
    int age = settings.value("user/age").toInt();

    qDebug() << "Window size:" << width << "x" << height;
    qDebug() << "User:" << name << ", " << age;

    // ---- Modify a value ----
    settings.setValue("user/age", age + 1);
    qDebug() << "Incremented age by 1 for next run.";

    return 0;
}
*/
