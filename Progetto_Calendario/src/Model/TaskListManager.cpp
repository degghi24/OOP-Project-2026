#include "Headers/TaskListManager.h"
#include "../Model/data_persistancy/json/jsonReader.h"
#include "../Model/data_persistancy/json/jsonVisitor.h"
#include "../Model/data_persistancy/xml/xmlReader.h"
#include "../Model/data_persistancy/xml/xmlVisitor.h"


TaskListManager::TaskListManager() : ID(0) {}

TaskListManager::~TaskListManager() {
    clearList();
}

unsigned int TaskListManager::getID() const {
    return ID;
}

void TaskListManager::incrementID(){ //initialized at 0 by default
    ID++;
}

void TaskListManager::addTask(AbstractTask* task) {
    if (!task) return;

    task->setId((getID()));
    taskList.push_back(task);
    incrementID();
}

bool TaskListManager::removeTask(const unsigned int& id) {
    for (auto it = taskList.begin(); it != taskList.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            taskList.erase(it);
            return true;
        }
    }
    return false;
}

const std::vector<AbstractTask*>& TaskListManager::getTaskList() const {
    return taskList;
}

void TaskListManager::clearList() {
    taskList.clear();
}

bool TaskListManager::saveToFile(const QString& filepath)const{  //Saves the library to a file
    QString dataType = filepath.mid(filepath.lastIndexOf("."));
    qDebug()<<dataType;

    if(dataType == ".xml"){
        XmlVisitor visitor = XmlVisitor();

        for (auto task : taskList) {
            task->accept(visitor);
        }

        QDomDocument doc = visitor.getDocument();

        QFile file(filepath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            return false;
        }

        QTextStream stream(&file);
        stream << doc.toString();
        file.close();

    }

    if(dataType == ".json"){
        QFile File(filepath);
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

bool TaskListManager::loadFromFile(const QString& filepath){ //Loads the library from a file

    clearList();
    QString dataType = filepath.mid(filepath.lastIndexOf("."));
    qDebug()<<dataType;

    if(dataType == ".xml"){

        XmlReader reader;

        QList<AbstractTask*> tasks = reader.readAll(filepath);

        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            addTask(*it);
        }
        return true;

    }

    if(dataType == ".json"){

        JsonReader reader;

        QList<AbstractTask*> tasks = reader.readAll(filepath);

        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            addTask(*it);
        }
        return true;

    }

    return false;
}


AbstractTask* TaskListManager::getTaskById(const unsigned int& id) const {
    for (auto task : taskList) {
        if (task->getId() == id)
            return task;
    }
    return nullptr;
}


std::vector<AbstractTask*> TaskListManager::findByTitle(const QString& text) const {
    std::vector<AbstractTask*> result;

    for (auto task : taskList) {
        if (task->getTitle().compare(text)) {
            result.push_back(task);
        }
    }

    return result;
}
