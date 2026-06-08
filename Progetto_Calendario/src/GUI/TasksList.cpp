#include "TasksList.h"

#include <QErrorMessage>

TasksList::TasksList(QWidget *parent): QWidget(parent), containerLayout(new QVBoxLayout(this)){

    TaskBlock *one = new TaskBlock("Attività", new QDate(2026,01,01), 0, new QDate(2026,01,01));
    TaskBlock *two = new TaskBlock("Work", new QDate(2026,01,02), 1);
    TaskBlock *three = new TaskBlock("Project", new QDate(2026,01,03), 3, new QDate(2026,01,04));
    TaskBlock *four = new TaskBlock("Reminder", new QDate(2026,01,04), 4, new QDate(2026,01,04));

    addTask(one);
    addTask(two);
    addTask(three);
    addTask(four);

    containerLayout->setSpacing(5);
    containerLayout->setAlignment(Qt::AlignTop);

}

void TasksList::addTask(TaskBlock* task){
    connect(task, &TaskBlock::clicked, this, &TasksList::selected);

    if(list.isEmpty()){
        list.append(task);
        containerLayout->addWidget(task);
    }else if(*list.last()->getStartDate() <= *task->getStartDate()){
        list.append(task);
        containerLayout->addWidget(task);
    }else{
        for(int i = 0; i < list.size(); ++i){
            qDebug()<<*list[i]->getStartDate()<<*task->getStartDate();
            qDebug()<<(*list[i]->getStartDate() >= *task->getStartDate());
            if(*task->getStartDate() <= *list[i]->getStartDate()){
                list.insert(i, task);
                containerLayout->insertWidget(i,task);
                break;
            }
        }
    }
}

void TasksList::addTask(AbstractTask* task){
    //TaskBlock* newBlock = new TaskBlock(task);
    //addTask(newBlock);
}


void TasksList::selected(TaskBlock* task){
    if(selectedTask != task){
        if(selectedTask){
            selectedTask->unselected();
        }
        task->selected();
        selectedTask = task;
    }else if(selectedTask == task){
        selectedTask->unselected();
        selectedTask = nullptr;
    }
}

bool TasksList::filter(Filter filterValues){

    QList<int> indexesShowed;

    qDebug()<<*filterValues.startDate;
    if(filterValues.endDate){
        qDebug()<<*filterValues.endDate;
    }else{
        qDebug()<<"nullptr";
    }
    qDebug()<<filterValues.type-1;
    qDebug()<<filterValues.title;
    qDebug()<<"---";


    //se l'input è errato non fa nulla
    if(filterValues.endDate && *filterValues.startDate > *filterValues.endDate){
        QErrorMessage errorMessage;
        errorMessage.showMessage("Data Inizio maggiore della Data Fine");
        return false;
    }

    if(filterValues.type < 0 || filterValues.type > 5){
        QErrorMessage errorMessage;
        errorMessage.showMessage("Tipo Inesistente");
        return false;
    }

    //se non è impostato nulla nel filter allora mostra tutto
    if(filterValues.startDate == nullptr && filterValues.endDate == nullptr &&
        filterValues.type == 0 && (filterValues.title.isEmpty() || filterValues.title.isNull()))
    {
        show();
        for(int i = 0; i < containerLayout->count(); ++i){
            list[i]->show(); // mostra tutto
        }
        return true;
    }

    //se ogni campo è compilato basta controllare uan volta la lista
    if(filterValues.startDate != nullptr && filterValues.endDate != nullptr &&
        filterValues.type != 0 && !filterValues.title.isEmpty() && !filterValues.title.isNull()){
        for(int i = 0; i < containerLayout->count(); ++i){
            if(*filterValues.startDate > *list[i]->getStartDate() || *filterValues.endDate < *list[i]->getEndDate()
                || filterValues.type != list[i]->getType()+1 || !list[i]->getTitle().contains(filterValues.title)){
                list[i]->hide();
            }
        }
        return true;
    }

    //altrimenti di controlla uno a uno i campi

    if(filterValues.startDate != nullptr){
        bool isSmaller = true;
        for(int i = containerLayout->count()-1; i >= 0; --i){
            if(isSmaller){
                if(*filterValues.startDate <= *list[i]->getStartDate()){
                    list[i]->show();
                    indexesShowed.prepend(i);
                }else{
                    isSmaller = false;
                    list[i]->hide();
                }
            }else{
                list[i]->hide();
            }
        }
    }

    if(filterValues.endDate != nullptr){
        if(indexesShowed.empty()){
            for(int i = 0; i < containerLayout->count(); ++i){
                if(list[i]->getEndDate() && *filterValues.endDate < *list[i]->getEndDate()){
                    list[i]->hide();
                }else{
                    list[i]->show();
                    indexesShowed.append(i);
                }
            }
        }else{
            int indexCount = indexesShowed.count();
            for(int it = 0; it < indexCount; ++it){
                if(list[it]->getEndDate() && *filterValues.endDate < *list[it]->getEndDate()){
                    list[it]->hide();
                    indexesShowed.removeAll(it);
                }else{
                    list[it]->show();
                }
            }
        }
    }

    if(filterValues.type != 0){
        if(indexesShowed.empty()){
            for(int i = 0; i < containerLayout->count(); ++i){
                if(filterValues.type-1 != list[i]->getType()){
                    list[i]->hide();
                }else{
                    list[i]->show();
                    indexesShowed.append(i);
                }
            }
        }else{
            int indexCount = indexesShowed.count();
            for(int it = 0; it < indexCount; ++it){
                qDebug()<<indexesShowed.toList();
                qDebug()<<"Iterator:"<<it;
                qDebug()<<"Type:"<<list[it]->getType();
                if(filterValues.type-1 != list[it]->getType()){
                    qDebug()<<"Remove";
                    list[it]->hide();
                    indexesShowed.removeAll(it);
                }else{

                    list[it]->show();
                    qDebug()<<"Show";
                }
            }
        }
    }

    qDebug()<<indexesShowed.toList();

    if(!filterValues.title.isEmpty() && !filterValues.title.isNull()){
        if(indexesShowed.empty()){
            for(int i = 0; i < containerLayout->count(); ++i){
                if(!list[i]->getTitle().contains(filterValues.title)){
                    list[i]->hide();
                }else{
                    list[i]->show();
                    indexesShowed.append(i);
                }
            }
        }else{
            int indexCount = indexesShowed.count();
            for(int it = 0; it < indexCount; ++it){
                if(!list[it]->getTitle().contains(filterValues.title)){
                    list[it]->hide();
                    indexesShowed.removeAll(it);
                }else{
                    list[it]->show();
                }
            }
        }
    }

    return true;
}

