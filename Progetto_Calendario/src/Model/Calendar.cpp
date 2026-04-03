#include "src/Model/Headers/Calendar.h"
#include <iostream>
using std::cout;
using std::endl;

Calendar* Calendar::instance = nullptr;

Calendar::Calendar() {}

Calendar::~Calendar() {
    for (AbstractTask* t : tasks)
        delete t;
    tasks.clear();
}

Calendar* Calendar::getInstance() {
    if (instance == nullptr)
        instance = new Calendar();
    return instance;
}

void Calendar::addTask(AbstractTask* task) {
    if (task != nullptr)
        tasks.push_back(task);
}

bool Calendar::removeTask(const std::string& id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            tasks.erase(it);
            return true;
        }
    }
    return false;
}

AbstractTask* Calendar::getTask(const std::string& id) {
    for (AbstractTask* t : tasks)
        if (t->getId() == id)
            return t;
    return nullptr;
}

std::vector<AbstractTask*> Calendar::getAllTasks() const {
    return tasks;
}

void Calendar::displayAll() const {
    if (tasks.empty()) {
        cout << "No tasks in calendar." << endl;
        return;
    }
    for (AbstractTask* t : tasks)
        t->display();
}