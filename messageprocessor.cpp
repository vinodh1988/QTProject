#include <messagewindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MessageProcessingWidget w;
    w.setWindowTitle("Message Processing State Machine");
    w.resize(400, 200);
    w.show();

    return app.exec();
}
