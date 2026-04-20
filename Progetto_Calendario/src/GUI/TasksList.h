#ifndef TASKSLIST_H
#define TASKSLIST_H

#include <QWidget>
#include <QVBoxLayout>

//#include "Model/Headers/AbstractTask.h"
#include "TaskBlock.h"

class TasksList: public QWidget{
    Q_OBJECT

private:

    QList<TaskBlock*> list; //per ordinare
    QVBoxLayout *container = nullptr;

public:

    void addTask(TaskBlock* task);
    //void addTask(AbstractTask* task);

    void fillContainer(QList<TaskBlock*> list);

    //void filter(); implementare il filter

    TasksList(QWidget *parent = nullptr);
};

#endif // TASKSLIST_H
