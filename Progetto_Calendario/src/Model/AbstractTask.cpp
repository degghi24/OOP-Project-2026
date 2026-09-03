#include "Headers/AbstractTask.h"

AbstractTask::AbstractTask(QString title, QString description,
                           QString assignee, QDate creationDate)
    :title(title), description(description),
    assignee(assignee), creationDate(creationDate)
{}

unsigned int AbstractTask::getId()           const { return id;           }
QString AbstractTask::getTitle()        const { return title;        }
QString AbstractTask::getDescription()  const { return description;  }
QString AbstractTask::getAssignee()     const { return assignee;     }
QDate AbstractTask::getCreationDate() const { return creationDate; }

void AbstractTask::setId         (const unsigned int& newId)       { id          = newId;       }
void AbstractTask::setTitle      (const QString& newTitle)    { title       = newTitle;    }
void AbstractTask::setDescription(const QString& newDesc)     { description = newDesc;     }
void AbstractTask::setAssignee   (const QString& newAssignee) { assignee    = newAssignee; }
