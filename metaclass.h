#ifndef METACLASS_H
#define METACLASS_H

#include <QObject>
#include <QMetaObject>
#include <QMetaMethod>
#include <QDebug>

class MetaClass : public QObject {
    Q_OBJECT
public:
    MetaClass(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE void foo() { qDebug() << "foo() called"; }
    Q_INVOKABLE void bar() { qDebug() << "bar() called"; }
    Q_INVOKABLE void baz() { qDebug() << "baz() called"; }
};

#endif // METACLASS_H
