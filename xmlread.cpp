#include <QCoreApplication>
#include <QFile>
#include <QXmlStreamReader>
#include <QTextStream>
#include <QString>
#include <QList>
#include <QVector>
#include <QDebug>
/*
struct Person {
    QString sno;
    QString name;
    QString city;
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QFile file("d:/datafiles/person.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file!";
        return 1;
    }

    QXmlStreamReader xml(&file);
    QVector<Person> people;

    while (!xml.atEnd() && !xml.hasError()) {
        xml.readNext();
        if (xml.isStartElement() && xml.name() == "person") {
            Person p;
            while (!(xml.isEndElement() && xml.name() == "person")) {
                xml.readNext();
                if (xml.isStartElement()) {
                    if (xml.name() == "sno")
                        p.sno = xml.readElementText();
                    else if (xml.name() == "name")
                        p.name = xml.readElementText();
                    else if (xml.name() == "city")
                        p.city = xml.readElementText();
                }
            }
            people.append(p);
        }
    }

    file.close();

    QTextStream out(stdout);
    out << QString("%1 | %2 | %3\n").arg("SNo", -5).arg("Name", -20).arg("City", -15);
    out << QString("%1-+-%2-+-%3\n")
               .arg(QString(5, '-'))
               .arg(QString(20, '-'))
               .arg(QString(15, '-'));
    for (const Person &p : people) {
        out << QString("%1 | %2 | %3\n")
        .arg(p.sno, -5)
            .arg(p.name, -20)
            .arg(p.city, -15);
    }

    return 0;
}
*/
