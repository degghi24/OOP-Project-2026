#ifndef PERSISTENCYMANAGER_H
#define PERSISTENCYMANAGER_H

#include <string>
#include "../Headers/TaskListManager.h"

class PersistencyManager {
public:
    static bool saveToJson(const TaskListManager& manager, const std::string& filePath);
    static bool saveToXml (const TaskListManager& manager, const std::string& filePath);

    static bool loadFromJson(TaskListManager& manager, const std::string& filePath);
    static bool loadFromXml (TaskListManager& manager, const std::string& filePath);
};

#endif