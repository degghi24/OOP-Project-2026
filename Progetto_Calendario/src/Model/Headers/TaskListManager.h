#ifndef TASKLISTMANAGER_H
#define TASKLISTMANAGER_H

#include <Vector>

#include "AbstractTask.h"

class TaskListManager{ //is the complete list of task

protected: //Singleton
    TaskListManager();

public:

    void addTask(AbstractTask *task);
    void removeTask(const AbstractTask *task);

    void clearList();

    void incrementID(); //initialized at 0 by default
    unsigned int getID() const;

    const std::vector<AbstractTask*>& getTaskList() const; //return TaskList as const

    static TaskListManager& getInstance(){
        static TaskListManager instance;
        return instance;
    }

    bool saveToFile(const string& filepath)const; //Saves the library to a file
    bool loadFromFile(const string& filepath); //Loads the library from a file

    // Delete so it is impossible to copy the singleton
    TaskListManager(const TaskListManager&) = delete;
    TaskListManager& operator=(const TaskListManager&) = delete;

private:
    std::vector<AbstractTask*> taskList;
    unsigned int ID;
};


#endif
