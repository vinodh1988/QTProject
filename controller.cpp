#include "controller.h"
#include <QDebug>

Controller::Controller(QObject* parent)
    : QObject(parent)
{
    qDebug() << "Controller created";

    // Child object
    QObject* child = new QObject(this);
    child->setObjectName("ChildObject");

    qDebug() << "Child created:" << child->objectName();
} //using this constructor the parent object set through constructor for dynamic allocation

Controller::~Controller()
{
    qDebug() << "Controller destroyed";
}
