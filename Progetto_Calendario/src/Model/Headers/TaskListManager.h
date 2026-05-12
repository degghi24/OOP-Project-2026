#ifndef TASKLISTMANAGER_H
#define TASKLISTMANAGER_H

#include <vector>
#include <string>
#include "AbstractTask.h"

class TaskListManager {

private:

    std::vector<AbstractTask*> taskList;
    unsigned int ID;
    void incrementID();

public:

    TaskListManager();
    ~TaskListManager();

    unsigned int getID() const;

    void addTask(AbstractTask* task);

    bool removeTask(const std::string& id);

    const std::vector<AbstractTask*>& getTaskList() const;

    static TaskListManager& getInstance(){
        static TaskListManager instance;
        return instance;
    }

    bool saveToFile(const string& filepath)const; //Saves the library to a file
    bool loadFromFile(const string& filepath); //Loads the library from a file

    void clearList();

    AbstractTask* getTaskById(const std::string& id) const;

    std::vector<AbstractTask*> findByTitle(const std::string& text) const;
};

#endif
