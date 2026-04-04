#include "Headers/TaskListManager.h"
#include "data_persistancy/json/jsonVisitor.h"

#include "QFile"
#include "QJsonDocument"

TaskListManager::TaskListManager():taskList(){};

TaskListManager::~TaskListManager() {
    for (AbstractTask* t : taskList)
        delete t;
    taskList.clear();
}


void TaskListManager::addTask(AbstractTask *task){
    taskList.push_back(task);
    incrementID();
}

void TaskListManager::removeTask(const AbstractTask *task){
    for(auto it = taskList.begin(); it != taskList.end();){
        if( (*it)->getId() == task->getId() ){
            it = taskList.erase(it);
        }else{
            ++it;
        }
    }
}

void TaskListManager::clearList(){
    taskList.clear();
}

void TaskListManager::incrementID(){ //initialized at 0 by default
    ID++;
}
unsigned int TaskListManager::getID() const{ //used in creation of new task
    return ID;                               //the first task has ID = 0
}

const std::vector<AbstractTask*>& TaskListManager::getTaskList() const{//return TaskList as const
    return taskList;
}

bool TaskListManager::saveToFile(const string& filepath)const{  //Saves the library to a file
    string dataType = filepath.substr(filepath.find_last_of('.'));
    //da fare
    if(dataType == ".xml"){

    }

    if(dataType == ".json"){
        QFile File(filepath.c_str());
        jsonVisitor visitor = jsonVisitor();

        QJsonArray jsonItems;

        for(const auto& it : taskList){
            it->accept(visitor);
            jsonItems.push_back(visitor.getObject());
        }

        QJsonDocument doc(jsonItems);

        if(File.open(QIODevice::WriteOnly | QIODevice::Truncate)){
            qDebug() <<"File open";
            File.write(doc.toJson());
            File.close();
        }else{
            //throw exception
        }


    }

    return true;
}
bool TaskListManager::loadFromFile(const string& filepath){ //Loads the library from a file

    clearList();
    string dataType = filepath.substr(filepath.find_last_of('.'));

    if(dataType == ".xml"){

    }

    if(dataType == ".json"){

    }

    return false;
}
