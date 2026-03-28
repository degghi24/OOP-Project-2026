QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

HEADERS += \
    src/Model/Headers/AbstractTask.h \
    src/Model/Headers/TimedTask.h \
    src/Model/Headers/RepeatableTask.h \
    src/Model/Headers/Deadline.h \
    src/Model/Headers/Activity.h \
    src/Model/Headers/Reminder.h \
    src/Model/Headers/Work.h \
    src/Model/Headers/Bill.h \
    src/Model/Headers/Project.h \
    src/Model/Headers/TaskListManager.h\
    src/Model/data_persistancy/Visitor.h\
    src/Model/data_persistancy/TaskReader.h\
    src/Model/data_persistancy/json/jsonReader.h\
    src/GUI/MainWindow.h\
    src/GUI/ToolBar.h\
    src/GUI/TaskListWindow.h\

SOURCES += \
    src/Model/data_persistancy/json/jsonReader.cpp\
    src/Model/data_persistancy/xml\
    src/Model/AbstractTask.cpp \
    src/Model/TimedTask.cpp \
    src/Model/RepeatableTask.cpp \
    src/Model/Deadline.cpp \
    src/Model/Activity.cpp \
    src/Model/Reminder.cpp \
    src/Model/Work.cpp \
    src/Model/Bill.cpp \
    src/Model/Project.cpp \
    src/Model/TaskListManager.cpp\
    src/GUI/MainWindow.cpp\
    src/GUI/ToolBar.cpp\
    src/GUI/TaskListWindow.cpp\
    src/GUI/main.cpp\
INCLUDEPATH += src

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
