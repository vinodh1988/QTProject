QT += core widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Containers.cpp \
        MetaCall.cpp \
        MetaDemo.cpp \
        MoreContainerConcepts.cpp \
        ThreadDemo.cpp \
        blockingvsnonblocking.cpp \
        broadcastdemo.cpp \
        car.cpp \
        controller.cpp \
        eventexample.cpp \
        firstui.cpp \
        librarycaller.cpp \
        logs.cpp \
        main.cpp \
        memory.cpp \
        metricthreads.cpp \
        multithreadedjobs.cpp \
        propertydemo.cpp \
        propmeta.cpp \
        qfileread.cpp \
        qfilewrite.cpp \
        qtjson.cpp \
        qtypes.cpp \
        regularexp.cpp \
        restothreadmutex.cpp \
        sender.cpp \
        settings.cpp \
        signaldemo.cpp \
        signalslotsintegrate.cpp \
        speedmain.cpp \
        timermain.cpp \
        xmlread.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    broadcast.h \
    buttonheader.h \
    car.h \
    controller.h \
    device.h \
    events.h \
    messagecontroller.h \
    metaclass.h \
    metricexpose.h \
    objectprocess.h \
    operations.h \
    plain.h \
    restaurant.h \
    sender.h \
    sensorsystem.h \
    speedcontroller.h \
    temperaturesensor.h \
    threadsources.h \
    workers.h

DISTFILES += \
    settings.ini

DEFINES += PROJECT_DIR=\"$$PWD\"
