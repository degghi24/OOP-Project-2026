#include "TasksList.h"
#include "GuiVisitors/BlockVisitor.h"

#include <QErrorMessage>

TasksList::TasksList(QWidget *parent): QWidget(parent), containerLayout(new QVBoxLayout(this)){
/*
    TaskBlock *one = new TaskBlock("Attività", new QDate(2026,01,01), 0, new QDate(2026,01,01));
    TaskBlock *two = new TaskBlock("Work", new QDate(2026,01,02), 1);
    TaskBlock *three = new TaskBlock("Project", new QDate(2026,01,03), 3, new QDate(2026,01,04));
    TaskBlock *four = new TaskBlock("Reminder", new QDate(2026,01,04), 4, new QDate(2026,01,04));

    addTask(one);
    addTask(two);
    addTask(three);
    addTask(four);
*/

    /*addTask(new Activity("Titolo Attività", "Desrizione", "IO", QDate::currentDate(), QDate::currentDate(), QDate::currentDate().addDays(1),
                         "15.00", 60, "Casa Mia", 1, "Lavoro", false, "Tua Madre"));
*/

    containerLayout->setSpacing(5);
    containerLayout->setAlignment(Qt::AlignTop);

}

void TasksList::addTask(TaskBlock* taskBlock){
    //connect(taskBlock, &TaskBlock::clicked, this, &TasksList::selected);
    connect(taskBlock, static_cast<void (TaskBlock::*)(TaskBlock*)>(&TaskBlock::doubleClicked), this, &TasksList::selected);
    connect(taskBlock, static_cast<void (TaskBlock::*)(AbstractTask*)>(&TaskBlock::doubleClicked), this, &TasksList::taskToShow);

    if(list.isEmpty()){
        list.append(taskBlock);
        containerLayout->addWidget(taskBlock);
    }else if(list.last() && *list.last()->getEndDate() <= *taskBlock->getEndDate()){
        list.append(taskBlock);
        containerLayout->addWidget(taskBlock);
    }else{
        for(int i = 0; i < list.size(); ++i){
            if(*taskBlock->getEndDate() <= *list[i]->getEndDate()){
                list.insert(i, taskBlock);
                containerLayout->insertWidget(i,taskBlock);
                break;
            }
        }
    }
}

void TasksList::addTask(AbstractTask* task){
    BlockVisitor blockVisitor;
    task->accept(blockVisitor);
    addTask(blockVisitor.getTaskBlock());
}

void TasksList::removeTask(AbstractTask* taskToRemove){
    for(auto it = list.begin(); it != list.end(); ++it){
        if((*it)->getSavedTask()->getId() == taskToRemove->getId()){
            containerLayout->removeWidget(*it);
            delete *it;
            list.erase(it);
            list.squeeze();
            break;
        }
    }
}

QList<TaskBlock*>& TasksList::getList(){
    return list;
}

QVBoxLayout* TasksList::getLayout(){
    return containerLayout;
}

void TasksList::selected(TaskBlock* task){
    if(!selectedTaskBlock || selectedTaskBlock != task){
        if(selectedTaskBlock){
            selectedTaskBlock->unselected();
        }
        if(task != nullptr){
            task->selected();
        }
        selectedTaskBlock = task;
    }/*else if(selectedTaskBlock == task){
        selectedTaskBlock->unselected();
        selectedTaskBlock = nullptr;
    }*/
}

void TasksList::unselect(){
    selected(nullptr);
}

bool TasksList::filter(Filter filterValues){



    QList<int> indexesShowed;
    bool isEmptiedLater = false;

    //se l'input è errato non fa nulla
    if(filterValues.endDate && filterValues.startDate && *filterValues.startDate > *filterValues.endDate){
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

    //se ogni campo è compilato basta controllare una volta la lista
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
    int size = containerLayout->count();

    if(filterValues.startDate != nullptr){
        for(int i = 0; i < size; ++i){
            list[i]->show(); // nella prima iterazione mostra tutto
            if(list[i]->getStartDate() && *list[i]->getStartDate() < *filterValues.startDate){ //e successivamente nasconde
                list[i]->hide();
            }
        }
    }

    if(filterValues.endDate != nullptr){
        for(int i = 0; i < size; ++i){
            if(!list[i]->isHidden() && *list[i]->getEndDate() > *filterValues.endDate){
                list[i]->hide();
            }
        }
    }

    if(filterValues.type != 0){
        for(int i = 0; i < size; ++i){
            if(!list[i]->isHidden() && filterValues.type-1 != list[i]->getType()){
                list[i]->hide();
            }
        }
    }

    if(!filterValues.title.isEmpty() && !filterValues.title.isNull()){
        for(int i = 0; i < size; ++i){
            if(!list[i]->isHidden() && !list[i]->getTitle().contains(filterValues.title)){
                list[i]->hide();
            }
        }
    }


    /*
    //altrimenti di controlla uno a uno i campi

    //end date
    if(filterValues.endDate != nullptr){
        bool skipFlag = false;
        for(int i = 0; i < containerLayout->count(); ++i){
            if(!skipFlag){
                if(*filterValues.endDate <= *list[i]->getEndDate()){
                    skipFlag = true;
                    list[i]->hide();
                }else{
                    list[i]->show();
                    indexesShowed.prepend(i);
                }
            }else{
                list[i]->hide();
            }
        }
    }

    //start date

    if(filterValues.startDate != nullptr){
        if(indexesShowed.empty()){ //viene eseguita se il filtro di end date filtra tutto

            for(int i = 0; i < containerLayout->count(); ++i){

                if(list[i]->getStartDate() == nullptr){  //se non ha la start date viene mostrato senza controllo
                    list[i]->show();
                    indexesShowed.append(i);

                }else if(list[i]->getStartDate() && *filterValues.startDate <= *list[i]->getStartDate()){
                    list[i]->show();
                    indexesShowed.append(i);
                }else{
                    list[i]->hide();
                }
            }
        }else{
            int indexCount = indexesShowed.count();
            for(int it = 0; it < indexCount; ++it){

                if(list[it]->getStartDate() == nullptr){  //se non ha la start date viene mostrato senza controllo
                    list[it]->show();

                }else if(list[it]->getStartDate() != nullptr && *filterValues.startDate <= *list[it]->getStartDate()){
                    list[it]->show();
                }else{
                    list[it]->hide();
                    indexesShowed.removeAll(it);
                    if(indexesShowed.isEmpty()){
                        isEmptiedLater = true;
                    }
                }
            }
        }
    }

    if(filterValues.type != 0){
        if(indexesShowed.empty() && !isEmptiedLater){
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
                if(filterValues.type-1 != list[it]->getType()){
                    list[it]->hide();
                    indexesShowed.removeAll(it);
                }else{

                    list[it]->show();
                }
            }
        }
    }

    if(!filterValues.title.isEmpty() && !filterValues.title.isNull()){
        if(indexesShowed.empty() &&  !isEmptiedLater){
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

    */
    return true;
}

