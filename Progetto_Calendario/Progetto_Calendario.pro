TEMPLATE = app
TARGET = CalendarApp

QT += core gui widgets xml
CONFIG += c++17

HEADERS += \
    src/GUI/AddTask/TaskCreationWindow.h \
    src/GUI/AddTask/TypeSelectionPopup.h \
    src/GUI/FilterWindow.h \
    src/GUI/Pages/BlankPage.h \
    src/GUI/Pages/DetailPage.h \
    src/GUI/Pages/EditPage.h \
    src/GUI/Pages/EditPages/AbstractEditPage.h \
    src/GUI/Pages/EditPages/ActivityEdit.h \
    src/GUI/Pages/EditPages/BillEdit.h \
    src/GUI/Pages/EditPages/DeadlineEditPage.h \
    src/GUI/Pages/EditPages/ProjectEdit.h \
    src/GUI/Pages/EditPages/ReminderEdit.h \
    src/GUI/Pages/EditPages/RepeatableEditPage.h \
    src/GUI/Pages/EditPages/TimedEditPage.h \
    src/GUI/Pages/EditPages/WorkEdit.h \
    src/GUI/StackedWindow.h \
    src/GUI/TaskBlock.h \
    src/GUI/TasksList.h \
    src/GUI/TasksListWindow.h \
    src/Model/Headers/TaskFactory.h \
    src/Model/Headers/AbstractTask.h \
    src/Model/Headers/Calendar.h \
    src/Model/Headers/TimedTask.h \
    src/Model/Headers/RepeatableTask.h \
    src/Model/Headers/Deadline.h \
    src/Model/Headers/Activity.h \
    src/Model/Headers/Reminder.h \
    src/Model/Headers/Work.h \
    src/Model/Headers/Bill.h \
    src/Model/Headers/Project.h \
    src/Model/Headers/TaskListManager.h \
    src/Model/data_persistancy/Visitor.h \
    src/Model/data_persistancy/TaskReader.h \
    src/Model/data_persistancy/json/jsonReader.h \
    src/Model/data_persistancy/json/jsonVisitor.h \
    src/Model/data_persistancy/xml/xmlReader.h \
    src/Model/data_persistancy/xml/xmlVisitor.h \
    src/GUI/MainWindow.h \
    src/GUI/ToolBar.h \

SOURCES += \
    src/GUI/Pages/EditPages/AbstractEditPage.cpp \
    src/GUI/Pages/EditPages/ActivityEdit.cpp \
    src/GUI/Pages/EditPages/BillEdit.cpp \
    src/GUI/Pages/EditPages/DeadlineEditPage.cpp \
    src/GUI/Pages/EditPages/ProjectEdit.cpp \
    src/GUI/Pages/EditPages/ReminderEdit.cpp \
    src/GUI/Pages/EditPages/RepeatableEditPage.cpp \
    src/GUI/Pages/EditPages/TimedEditPage.cpp \
    src/GUI/Pages/BlankPage.cpp \
    src/GUI/Pages/DetailPage.cpp \
    src/GUI/Pages/EditPage.cpp \
    src/GUI/AddTask/TaskCreationWindow.cpp \
    src/GUI/AddTask/TypeSelectionPopup.cpp \
    src/GUI/FilterWindow.cpp \
    src/GUI/Pages/EditPages/WorkEdit.cpp \
    src/GUI/StackedWindow.cpp \
    src/GUI/TaskBlock.cpp \
    src/GUI/TasksList.cpp \
    src/GUI/TasksListWindow.cpp \
    src/Model/TaskFactory.cpp \
    src/Model/data_persistancy/json/jsonReader.cpp \
    src/Model/data_persistancy/json/jsonVisitor.cpp \
    src/Model/data_persistancy/xml/xmlReader.cpp \
    src/Model/data_persistancy/xml/xmlVisitor.cpp \
    src/Model/Calendar.cpp \
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
    src/GUI/main.cpp\

INCLUDEPATH += src \

RESOURCES += resources.qrc


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
