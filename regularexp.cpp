#include <QCoreApplication>
#include <QStringList>
#include <QRegularExpression>
#include <QTextStream>

/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QStringList stringList = {
        "apple",
        "banana",
        "apricot",
        "grape",
        "pineapple",
        "orange",
        "123",
        "abc",
        "cat",
        "still",
        "peter",
        "joe",
        "a&b"
    };

    QString pattern = "^[a-zA-Z0-9]{3}$"; // Example: strings starting with 'a'
    QRegularExpression regex(pattern);

    QTextStream out(stdout);
    out << "Strings matching regex '" << pattern << "':\n";
    for (const QString &str : stringList) {
        if (regex.match(str).hasMatch()) {
            out << str << "\n";
        }
    }

    return 0;
}
*/
