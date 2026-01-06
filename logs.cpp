#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>
#include <QFile>
#include <QTextStream>

void myMessageHandler(QtMsgType type,
                      const QMessageLogContext &context,
                      const QString &msg)
{
    QTextStream out(stdout);

    switch (type) {
    case QtDebugMsg:
        out << "[DEBUG] ";
        break;
    case QtInfoMsg:
        out << "[INFO] ";
        break;
    case QtWarningMsg:
        out << "[WARNING] ";
        break;
    case QtCriticalMsg:
        out << "[CRITICAL] ";
        break;
    case QtFatalMsg:
        out << "[FATAL] ";
        break;
    }

    out << msg << "\n";
}
/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

   qInstallMessageHandler(myMessageHandler);


    qDebug()    << "This is a debug message";
    qInfo()     << "System initialized";
    qWarning()  << "Temperature is high";
    qCritical() << "System failure detected";


    QLoggingCategory::setFilterRules(
        "*.debug=false\n"
        "*.info=true\n"
        "*.warning=true\n"
        "*.critical=true"
        );

    qDebug()    << "This debug will NOT appear";
    qInfo()     << "Info still appears";
    qWarning()  << "Warning still appears";
    qCritical() << "Critical still appears";

    return 0;
}

*/
