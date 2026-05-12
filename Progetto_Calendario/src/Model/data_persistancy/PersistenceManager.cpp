#include "src/Model/data_persistancy/PersistenceManager.h"

#include "json/jsonReader.h"
#include "json/jsonVisitor.h"
#include "xml/xmlReader.h"
#include "xml/xmlVisitor.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>
#include <QDomDocument>

bool PersistencyManager::saveToJson(const TaskListManager& manager, const std::string& filePath) {
    QJsonArray array;

    for (auto task : manager.getTaskList()) {
        jsonVisitor visitor;
        task->accept(visitor);
        array.append(visitor.getObject());
    }

    QJsonDocument doc(array);

    QFile file(QString::fromStdString(filePath));
    if (!file.open(QIODevice::WriteOnly))
        return false;

    file.write(doc.toJson());
    file.close();

    return true;
}

bool PersistencyManager::loadFromJson(TaskListManager& manager, const std::string& filePath) {
    JsonReader reader;

    QList<AbstractTask*> tasks = reader.readAll(QString::fromStdString(filePath));

    manager.clearList();

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        manager.addTaskWithoutId(*it);
    }

    return true;
}

bool PersistencyManager::saveToXml(const TaskListManager& manager, const std::string& filePath) {
    XmlVisitor visitor;

    for (auto task : manager.getTaskList()) {
        task->accept(visitor);
    }

    QDomDocument doc = visitor.getDocument();

    QFile file(QString::fromStdString(filePath));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream stream(&file);
    stream << doc.toString();
    file.close();

    return true;
}

bool PersistencyManager::loadFromXml(TaskListManager& manager, const std::string& filePath) {
    XmlReader reader;

    QList<AbstractTask*> tasks = reader.readAll(QString::fromStdString(filePath));

    manager.clearList();

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        manager.addTaskWithoutId(*it);
    }

    return true;
}