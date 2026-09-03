#ifndef TASKLISTMANAGER_H
#define TASKLISTMANAGER_H

#include <vector>
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

    bool removeTask(const unsigned int &id);

    const std::vector<AbstractTask*>& getTaskList() const;

    static TaskListManager& getInstance(){
        static TaskListManager instance;
        return instance;
    }

    bool saveToFile(const QString& filepath)const; //Saves the library to a file
    bool loadFromFile(const QString& filepath); //Loads the library from a file

    void clearList();

    AbstractTask* getTaskById(const unsigned int &id) const;

    std::vector<AbstractTask*> findByTitle(const QString& text) const;
};

#endif
