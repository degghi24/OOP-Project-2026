#include "TasksList.h"

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

    bool titleChangeFlag = true;
    bool startDateChangeFlag = true;
    bool endDateChangeFlag = true;
    bool typeChangeFlag = true;

    if(storedFilterValues.title == filterValues.title) titleChangeFlag = false;
    if(storedFilterValues.startDate == filterValues.startDate) titleChangeFlag = false;
    if(storedFilterValues.endDate == filterValues.endDate) titleChangeFlag = false;
    if(storedFilterValues.type == filterValues.type) titleChangeFlag = false;

    storedFilterValues.title = filterValues.title;
    storedFilterValues.startDate = filterValues.startDate;
    storedFilterValues.endDate = filterValues.endDate;
    storedFilterValues.type = filterValues.type;

    //se non è impostato nulla nel filter allora mostra tutto
    if(storedFilterValues.startDate == nullptr && storedFilterValues.endDate == nullptr &&
       storedFilterValues.type == 0 && (storedFilterValues.title.isEmpty() || storedFilterValues.title.isNull()))
    {
        show();
        for(int i = 0; i < containerLayout->count(); ++i){
            containerLayout->itemAt(i)->widget()->show(); // mostra tutto
            indexesShowed.clear();
        }
        return true;
    }


    if(startDateChangeFlag){ //cambiato data inizio
        if(storedFilterValues.startDate == nullptr){ //cambiato data inizio in nullo
            if(endDateChangeFlag){ //cambiato data fine
                if(storedFilterValues.endDate == nullptr){ //cambiato data fine in nullo
                    if(typeChangeFlag){ //cambiato tipo
                        if(storedFilterValues.type == 0){ //cambiato tipo in tutto
                            if(titleChangeFlag){ //cambiato titolo
                                if(storedFilterValues.title.isEmpty() || storedFilterValues.title.isNull()){ //cambiato titolo in nullo
                                    for(int i = 0; i < containerLayout->count(); ++i){
                                        containerLayout->itemAt(i)->widget()->show(); // mostra tutto
                                        indexesShowed.clear();
                                    }
                                }else{
                                    for(int i = 0; i < containerLayout->count(); ++i){
                                        if(list[i]->getTitle().contains(storedFilterValues.title)){
                                            containerLayout->itemAt(i)->widget()->show();
                                            indexesShowed.append(i);
                                        }{
                                            containerLayout->itemAt(i)->widget()->hide();
                                            indexesShowed.removeOne(i);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else{ //cambiato data inizio in valore
            if(*storedFilterValues.startDate > list.last()->getStartDate()){ //se data inizio è maggiore dell'ultimo data inizio allora nascondo tutto
                hide();
            }else if(storedFilterValues.endDate != nullptr && *storedFilterValues.endDate < *storedFilterValues.startDate){ //se data inizio dato è maggiore del data fine dato, nascondo tutto
                hide();
            }else{
                bool isBefore = true;
                for(int i = containerLayout->count(); i> 0; --i){
                    if(isBefore){
                        if(*storedFilterValues.startDate <= list[i]->getStartDate()){
                            indexesShowed.append(i);
                        }else{
                            isBefore = false;
                            containerLayout->itemAt(i)->widget()->hide();
                        }
                    }else{
                        containerLayout->itemAt(i)->widget()->hide();
                    }
                }
            }
        }
    }

    if(endDateChangeFlag){
        if(storedFilterValues.endDate != nullptr){

        }
    }




    if(filterValues.endDate != nullptr){
        if(*filterValues.endDate < list.first()->getEndDate() || *filterValues.startDate > list.last()->getStartDate() || *filterValues.endDate < *filterValues.startDate ){
            hide();
        }else if(filterValues.type == 0){ //tutti i tipi

            if((filterValues.title.isEmpty() || filterValues.title.isNull())){ //senza titolo

                int start = 0;
                int end = containerLayout->count();
                while(start < containerLayout->count() && end > 0){
                    //forward (endDate)
                    if(*filterValues.endDate < list[start]->getEndDate() && !containerLayout->itemAt(start)->widget()->isHidden()){
                        containerLayout->itemAt(start)->widget()->hide();
                    }
                    //backward (startDate)
                    if(*filterValues.startDate < list[end]->getStartDate() && !containerLayout->itemAt(end)->widget()->isHidden()){
                        containerLayout->itemAt(end)->widget()->hide();
                    }

                    ++start;
                    --end;
                }

            }else{ // con titolo

                int start = 0;
                int end = containerLayout->count();
                while(start < containerLayout->count() && end > 0){
                    //forward (endDate)
                    if(*filterValues.endDate < list[start]->getEndDate() && !containerLayout->itemAt(start)->widget()->isHidden() && !list[start]->getTitle().contains(filterValues.title)){
                        containerLayout->itemAt(start)->widget()->hide();
                    }
                    //backward (startDate)
                    if(*filterValues.startDate < list[end]->getStartDate() && !containerLayout->itemAt(end)->widget()->isHidden() && !list[end]->getTitle().contains(filterValues.title)){
                        containerLayout->itemAt(end)->widget()->hide();
                    }

                    ++start;
                    --end;
                }

            }

        }else{ // con tipo
            int start = 0;
            int end = containerLayout->count();
            while(start < containerLayout->count() && end > 0){
                //forward (endDate)
                if(*filterValues.endDate < list[start]->getEndDate() && !containerLayout->itemAt(start)->widget()->isHidden() && !list[start]->getTitle().contains(filterValues.title) && (filterValues.type - 1) == list[start]->getType()){
                    containerLayout->itemAt(start)->widget()->hide();
                }
                //backward (startDate)
                if(*filterValues.startDate < list[end]->getStartDate() && !containerLayout->itemAt(end)->widget()->isHidden() && !list[end]->getTitle().contains(filterValues.title) && (filterValues.type - 1) == list[end]->getType()){
                    containerLayout->itemAt(end)->widget()->hide();
                }

                ++start;
                --end;
            }
        }

    }else{
        if(*filterValues.startDate > list.last()->getStartDate()){
            hide();
        }else{
            int end = containerLayout->count();
            bool flag = true;
            while(end > 0){
                if(flag && *filterValues.startDate > list[end]->getStartDate()){
                    flag = false;
                }else{
                    containerLayout->itemAt(end)->widget()->hide();
                }
                --end;
            }
        }
    }

    return false; //?
}

