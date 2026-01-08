#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label("Hello World from Qt!");
    label.resize(250, 100);
    label.show();

    return app.exec();
}

