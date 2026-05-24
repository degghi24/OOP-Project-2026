#include "TasksList.h"

#include <QErrorMessage>

TasksList::TasksList(QWidget *parent): QWidget(parent), containerLayout(new QVBoxLayout(this)){

    /*TaskBlock *one = new TaskBlock("Inizio", "1", "Tipo", "Fine");
    TaskBlock *two = new TaskBlock("Inizio", "2", "Tipo");
    TaskBlock *three = new TaskBlock("Inizio", "3", "Tipo", "Fine");
    TaskBlock *four = new TaskBlock("Inizio", "4", "Tipo");


    containerLayout->addWidget(one);
    containerLayout->addWidget(two);
    containerLayout->addWidget(three);
    containerLayout->addWidget(four);*/
    //container->setContentsMargins(10,5,10,5);
    containerLayout->setSpacing(5);

}

void TasksList::addTask(TaskBlock* task){
    for(int i = 0; i < list.size(); ++i){
        if(list[i]->getStartDate() > task->getStartDate()){
            list.insert(i, task);
            containerLayout->insertWidget(i,task);
            break;
        }
    }
}


bool TasksList::filter(Filter filterValues){

    filterValues.title;
    filterValues.startDate;
    filterValues.endDate;
    filterValues.type;

    indexesShowed.clear();

    //se l'input è errato non fa nulla
    if(*filterValues.startDate > *filterValues.endDate){
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
            containerLayout->itemAt(i)->widget()->show(); // mostra tutto
        }
        return true;
    }

    //se ogni campo è compilato basta controllare uan volta la lista
    if(filterValues.startDate != nullptr && filterValues.endDate != nullptr &&
        filterValues.type != 0 && !filterValues.title.isEmpty() && !filterValues.title.isNull()){
        for(int i = 0; i < containerLayout->count(); ++i){
            if(*filterValues.startDate > list[i]->getStartDate() || *filterValues.endDate < list[i]->getEndDate()
                || filterValues.type != list[i]->getType()+1 || !list[i]->getTitle().contains(filterValues.title)){
                containerLayout->itemAt(i)->widget()->hide();
            }
        }
        return true;
    }

    //altrimenti di controlla uno a uno i campi

    if(filterValues.startDate != nullptr){
        bool isSmaller = true;
        for(int i = containerLayout->count(); i> 0; --i){
            if(isSmaller){
                if(*filterValues.startDate <= list[i]->getStartDate()){
                    indexesShowed.append(i);
                }else{
                    isSmaller = false;
                    containerLayout->itemAt(i)->widget()->hide();
                }
            }else{
                containerLayout->itemAt(i)->widget()->hide();
            }
        }
    }

    if(filterValues.endDate != nullptr){
        if(indexesShowed.empty()){
            for(int i = 0; i < containerLayout->count(); ++i){
                if(*filterValues.endDate < list[i]->getEndDate()){
                    containerLayout->itemAt(i)->widget()->hide();
                }else{
                    indexesShowed.append(i);
                }
            }
        }else{
            for(auto it : std::as_const(indexesShowed)){
                if(*filterValues.endDate < list[it]->getEndDate()){
                    containerLayout->itemAt(it)->widget()->hide();
                    indexesShowed.removeOne(it);
                    indexesShowed.squeeze();
                }
            }
        }
    }

    if(filterValues.type != 0){
        if(indexesShowed.empty()){
            for(int i = 0; i < containerLayout->count(); ++i){
                if(filterValues.type != list[i]->getType()+1){
                    containerLayout->itemAt(i)->widget()->hide();
                }else{
                    indexesShowed.append(i);
                }
            }
        }else{
            for(auto it : std::as_const(indexesShowed)){
                if(filterValues.type != list[it]->getType()+1){
                    containerLayout->itemAt(it)->widget()->hide();
                    indexesShowed.removeOne(it);
                    indexesShowed.squeeze();
                }
            }
        }
    }

    if(!filterValues.title.isEmpty() && !filterValues.title.isNull()){
        if(indexesShowed.empty()){
            for(int i = 0; i < containerLayout->count(); ++i){
                if(!list[i]->getTitle().contains(filterValues.title)){
                    containerLayout->itemAt(i)->widget()->hide();
                }else{
                    indexesShowed.append(i);
                }
            }
        }else{
            for(auto it : std::as_const(indexesShowed)){
                if(!list[it]->getTitle().contains(filterValues.title)){
                    containerLayout->itemAt(it)->widget()->hide();
                    indexesShowed.removeOne(it);
                    indexesShowed.squeeze();
                }
            }
        }
    }

    return true;
}

