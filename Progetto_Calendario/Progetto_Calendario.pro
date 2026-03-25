QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

HEADERS += \
    Headers/AbstractTask.h \
    Headers/TimedTask.h \
    Headers/RepeatableTask.h \
    Headers/Deadline.h \
    Headers/Activity.h \
    Headers/Reminder.h \
    Headers/Work.h \
    Headers/Bill.h \
    Headers/Project.h \
    Model/Visitor.h \
    GUI/mainwindow.h

SOURCES += \
    Model/AbstractTask.cpp \
    Model/TimedTask.cpp \
    Model/RepeatableTask.cpp \
    Model/Deadline.cpp \
    Model/Activity.cpp \
    Model/Reminder.cpp \
    Model/Work.cpp \
    Model/Bill.cpp \
    Model/Project.cpp \
    GUI/mainwindow.cpp \
    GUI/main.cpp

INCLUDEPATH += Headers

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target