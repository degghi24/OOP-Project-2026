#ifndef TASKLISTMANAGER_H
#define TASKLISTMANAGER_H

#include <vector>
#include <string>
#include "AbstractTask.h"

class TaskListManager {
private:
    std::vector<AbstractTask*> taskList;
    unsigned int ID;

public:
    TaskListManager();
    ~TaskListManager();

    std::string generateId();

    void addTask(AbstractTask* task);

    bool removeTask(const std::string& id);

    AbstractTask* getTaskById(const std::string& id) const;

    const std::vector<AbstractTask*>& getTaskList() const;

    void clearList();

    unsigned int getID() const;

    std::vector<AbstractTask*> findByTitle(const std::string& text) const;
};

#endif