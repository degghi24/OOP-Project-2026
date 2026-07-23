#ifndef STACKEDWINDOW_H
#define STACKEDWINDOW_H

#include "GUI/GuiVisitors/DetailVisitor.h"
#include "GUI/GuiVisitors/EditVisitor.h"
#include "Model/Headers/AbstractTask.h"
#include <QWidget>
#include <QStackedLayout>
#include <QCalendarWidget>
#include <QPushButton>
#include <QScrollArea>

//#include "WeekScollMenuBar" //opzionale se troppo complicato
//#include "TaskDetailWindow"
//#include "TaskEditWindow"

class StackedWindow: public QWidget{
    Q_OBJECT

private:

    QStackedLayout *stack = nullptr;
    QCalendarWidget *calendar = nullptr;

    DetailVisitor detailVisitor;
    EditVisitor editVisitor;

    QFrame *detailFrame = nullptr;
    QScrollArea *detailScrollArea = nullptr;
    QPushButton *editButton = nullptr;
    QPushButton *removeButton = nullptr;

    QFrame *editFrame = nullptr;
    QScrollArea *editScrollArea = nullptr;
    QPushButton *saveButton = nullptr;
    QPushButton *discardButton = nullptr;
    //TaskDetailWindow *detail = nullptr
    //TaskEditWindow *edit = nullptr

    void setUpDetailFrame();
    void setUpEditFrame();

public slots:
    void showDetailWindow(AbstractTask *task);

public:
    StackedWindow(QWidget *parent = nullptr);
};

#endif // STACKEDWINDOW_H
