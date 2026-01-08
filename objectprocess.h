#ifndef OBJECTPROCESS_H
#define OBJECTPROCESS_H

#include <QObject>
#include <QMetaObject>
#include <QMetaProperty>
#include <QVariant>
#include <QDebug>
//all QT Heirarchy classes subclasses of QObject
void processQObject(QObject *obj)
{
    const QMetaObject *mo = obj->metaObject();

    qDebug() << "Runtime class:" << mo->className();

    for (int i = 0; i < mo->propertyCount(); ++i) {
        QMetaProperty prop = mo->property(i);

        qDebug() << "Property:"
                 << prop.name()
                 << "(" << prop.typeName() << ")";

        if (QString(prop.name()) == "temperature") {

            QVariant value = prop.read(obj);
            qDebug() << "Current temperature:" << value.toDouble();

            prop.write(obj, value.toDouble() + 5.0);
            qDebug() << "Updated temperature:"
                     << prop.read(obj).toDouble();
        }
    }
}


#endif // OBJECTPROCESS_H
