#include "data_persistancy/ConstVisitor.h"
#include "Headers/TaskListManager.h"
#include "Headers/Work.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

Work::Work(QString title, QString description,
           QString assignee, QDate creationDate,
           QBitArray weekDays,
           QDate repeatEndDate,
           QStringList subTasks, int progress,
           QString client, QString category, QString notes)
    : AbstractTask(title, description, assignee, creationDate),
    RepeatableTask(title, description, assignee, creationDate,
                   weekDays, repeatEndDate),
    subTasks(subTasks), progress(progress),
    client(client), category(category), notes(notes)
{}

QStringList Work::getSubTasks()  const { return subTasks; }
int            Work::getProgress()  const { return progress; }
QString         Work::getClient()    const { return client;   }
QString         Work::getCategory()  const { return category; }
QString         Work::getNotes()     const { return notes;    }

void Work::setSubTasks (const QStringList &newSubTasks) { subTasks = newSubTasks; }
void Work::setProgress (const int& newProgress)            { progress = newProgress; }
void Work::setClient   (const QString& newClient)           { client   = newClient;   }
void Work::setCategory (const QString& newCategory)         { category = newCategory; }
void Work::setNotes    (const QString& newNotes)            { notes    = newNotes;    }

void Work::addSubTask(const QString& task) {
    subTasks.append(task);
}

bool Work::removeSubTask(const QString& task) {
    auto it = std::find(subTasks.begin(), subTasks.end(), task);
    if (it != subTasks.end()) {
        subTasks.erase(it);
        return true;
    }
    return false;
}
bool Work::remove() {
    return TaskListManager::getInstance().removeTask(getId());
}

void Work::accept(ConstVisitor &v) {
    v.visit(*this);
}

void Work::accept(Visitor &v) {
    v.visit(this);
}

Work::~Work(){
    subTasks.clear();
}
