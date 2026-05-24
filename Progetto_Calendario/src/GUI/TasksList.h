#ifndef TASKSLIST_H
#define TASKSLIST_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QDate>

//#include "Model/Headers/AbstractTask.h"
#include "TaskBlock.h"

struct Filter{
    QString title;
    QDate *startDate;
    QDate *endDate;
    int type; //
};

class TasksList: public QWidget{
    Q_OBJECT

public slots:
    bool filter(Filter filterValues);

private:
    QList<int> indexesShowed;

    QVBoxLayout *containerLayout = nullptr;
    QList<TaskBlock*> list; //per ordinare

    void searchTitle();
    void searchType();
    void searchEndDate();
    void searchStartDate();

public:

    void addTask(TaskBlock* task);
    //void addTask(AbstractTask* task);

    void fillContainer(QList<TaskBlock*> list);

    //void filter(); implementare il filter

    TasksList(QWidget *parent = nullptr);
};

#endif // TASKSLIST_H
