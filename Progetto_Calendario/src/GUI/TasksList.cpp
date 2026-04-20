#include "TasksList.h"

TasksList::TasksList(QWidget *parent): QWidget(parent), container(new QVBoxLayout(this)){
    TaskBlock *one = new TaskBlock("Inizio", "1", "Tipo", "Fine");
    TaskBlock *two = new TaskBlock("Inizio", "2", "Tipo");
    TaskBlock *three = new TaskBlock("Inizio", "3", "Tipo", "Fine");
    TaskBlock *four = new TaskBlock("Inizio", "4", "Tipo");


    container->insertWidget(0,one);
    container->insertWidget(1,two);
    container->insertWidget(2,three);
    container->insertWidget(3,four);

    //container->setContentsMargins(10,5,10,5);
    container->setSpacing(5);

}

void TasksList::addTask(TaskBlock* task){
    for(int i = 0; i < list.size(); ++i){
        if(list[i]->getStartDate() > task->getStartDate()){
            list.insert(i, task);
            container->insertWidget(i,task);
            break;
        }
    }
}

void TasksList::fillContainer(QList<TaskBlock*> list){

    for(int i = 0; i < container->count(); ++i){
        container->insertWidget(i,list[i]);
    }
}
