#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>
#include <string>
#include "src/Model/Headers/AbstractTask.h"

class Calendar {
private:
    static Calendar* instance;

    std::vector<AbstractTask*> tasks;

    Calendar();

public:
    ~Calendar();

    Calendar(const Calendar&) = delete;
    Calendar& operator=(const Calendar&) = delete;

    static Calendar* getInstance();

    void addTask(AbstractTask* task);
    bool removeTask(const std::string& id);

    AbstractTask* getTask(const std::string& id);

    std::vector<AbstractTask*> getAllTasks() const;

    void displayAll() const;
};

#endif