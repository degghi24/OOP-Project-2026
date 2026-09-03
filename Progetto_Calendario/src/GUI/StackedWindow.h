#ifndef STACKEDWINDOW_H
#define STACKEDWINDOW_H

#include "../Model/Headers/AbstractTask.h"
#include <QWidget>
#include <QStackedLayout>
#include <QCalendarWidget>
#include <QPushButton>
#include <QScrollArea>

//#include "WeekScollMenuBar" //opzionale se troppo complicato
#include "TaskDetailWindow.h"
#include "TaskEditWindow.h"

class StackedWindow: public QWidget{
    Q_OBJECT

private:

    QStackedLayout *stack = nullptr;
    QCalendarWidget *calendar = nullptr;


    TaskDetailWindow *detail = nullptr;
    TaskEditWindow *edit = nullptr;

    void close();

    DetailPage* createDetailPage();
    EditPage* createEditPage();

    void updateDetailPage(AbstractTask *taskToUpdate);

signals:
    void unselectTaskBlock();
    void removeTask(AbstractTask* task);
    void selectedFilterDate(QDate newDate);

public slots:
    void showDetailWindow(AbstractTask *task);
    void showEditWindow(AbstractTask* task);

public:
    StackedWindow(QWidget *parent = nullptr);
    void toHomePage();
};

#endif // STACKEDWINDOW_H
