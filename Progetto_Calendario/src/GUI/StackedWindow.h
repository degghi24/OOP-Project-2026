#ifndef STACKEDWINDOW_H
#define STACKEDWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include <QCalendarWidget>

//#include "WeekScollMenuBar" //opzionale se troppo complicato
//#include "TaskDetailWindow"
//#include "TaskEditWindow"

class StackedWindow: public QWidget{
    Q_OBJECT

private:

    QStackedLayout *stack = nullptr;
    QCalendarWidget *calendar = nullptr;

    //TaskDetailWindow *detail = nullptr
    //TaskEditWindow *edit = nullptr

private slots:
    void showTypeSelect();
    void showTaskCreation(QString type);

public:
    StackedWindow(QWidget *parent = nullptr);
};

#endif // STACKEDWINDOW_H
