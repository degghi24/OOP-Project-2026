#include "Headers/TaskListManager.h"
#include <algorithm>

TaskListManager::TaskListManager() : ID(0) {}

TaskListManager::~TaskListManager() {
    clearList();
}

// ID come string (conversione semplice da numero)
std::string TaskListManager::generateId() {
    return std::to_string(ID++);
}

void TaskListManager::addTask(AbstractTask* task) {
    if (!task) return;

    task->setId(generateId());
    taskList.push_back(task);
}

bool TaskListManager::removeTask(const std::string& id) {
    for (auto it = taskList.begin(); it != taskList.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            taskList.erase(it);
            return true;
        }
    }
    return false;
}

AbstractTask* TaskListManager::getTaskById(const std::string& id) const {
    for (auto task : taskList) {
        if (task->getId() == id)
            return task;
    }
    return nullptr;
}

const std::vector<AbstractTask*>& TaskListManager::getTaskList() const {
    return taskList;
}

void TaskListManager::clearList() {
    for (auto task : taskList) {
        delete task;
    }
    taskList.clear();
}

unsigned int TaskListManager::getID() const {
    return ID;
}

std::vector<AbstractTask*> TaskListManager::findByTitle(const std::string& text) const {
    std::vector<AbstractTask*> result;

    for (auto task : taskList) {
        if (task->getTitle().find(text) != std::string::npos) {
            result.push_back(task);
        }
    }

    return result;
}