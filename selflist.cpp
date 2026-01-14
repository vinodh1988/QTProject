#include<QCoreApplication>
#include<functional>
#include<QDebug>
#include<QList>
#include <QThread>



int square(int x) {
    qDebug() << x << " is processed in square" << QThread::currentThread();
    return x*x;
}

int plus100(int x) {
    qDebug() << x << " is processed in plus100" << QThread::currentThread();
    return x+100;
}

bool isEven(int x){
    qDebug() << x << " is processed in Even" << QThread::currentThread();
    return x%2==0;
}

QList<int> mymap(QList<int>* list,std::function<int(int)> callback)
{
    QList<int> result;
    for(int i=0;i<list->size();i++)
    {
        int s=callback(list->at(i));
        result.append(s);
    }
    return result;
}

QList<int> myfilter(QList<int>* list, std::function<bool(int)> callback) {
     QList<int> result;
    for(int i=0;i<list->size();i++)
    {
        bool  s=callback(list->at(i));
        if(s)
            result.append(list->at(i));
    }
    return result;
}

    int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

        QList<int> source {1,3,5,6,6,13,12,15,12,15,1};
        QList <int> result =mymap(&source,square);
        QList <int> result2= mymap(&source, plus100);
        QList <int> result3 =myfilter(&source, isEven);

        qDebug() << result;
        qDebug() << result2;
        qDebug() << result3;


    }
