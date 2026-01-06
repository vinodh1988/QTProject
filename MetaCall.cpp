#include <QObject>
#include <QMetaObject>
#include <QMetaMethod>
#include <QDebug>
#include <metaclass.h>

int main() {
    MetaClass obj;

    const QMetaObject *metaObj = obj.metaObject();
    qDebug() << "Listing Q_INVOKABLE methods:";
    for (int i = 0; i < metaObj->methodCount(); ++i) {
        QMetaMethod method = metaObj->method(i);
        // Only list public Q_INVOKABLE methods declared in MyClass
        if (method.methodType() == QMetaMethod::Method &&
            method.access() == QMetaMethod::Public &&
            QString(metaObj->className()) == QString(method.enclosingMetaObject()->className()))
        {
            qDebug() << "Method:" << method.methodSignature();
            // Invoke method with no arguments
            method.invoke(&obj, Qt::DirectConnection);
        }
        }

    return 0;
}
