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

private slots:
    void selected(TaskBlock* task);

public slots:
    bool filter(Filter filterValues);
    void unselect();
    void removeTask(AbstractTask* taskToRemove);
    void updateList(AbstractTask* taskToUpdate);

signals:
    void taskToShow(AbstractTask* task);

private:

    QVBoxLayout *containerLayout = nullptr;
    QList<TaskBlock*> list; //per ordinare

    TaskBlock *selectedTaskBlock = nullptr;

    void searchTitle();
    void searchType();
    void searchEndDate();
    void searchStartDate();

public:

    void addTask(TaskBlock* task);
    void addTask(AbstractTask* task);

    QList<TaskBlock*>& getList();
    QVBoxLayout* getLayout();

    TasksList(QWidget *parent = nullptr);
};

#endif // TASKSLIST_H
