#ifndef TASKREADER_H
#define TASKREADER_H

#include <QtXml>
#include <QJsonObject>
#include <string>

class TaskListManager;

class TaskReader{
public:
    virtual ~TaskReader();
    virtual TaskListManager* read(const std::string& filePath);
};

#endif
