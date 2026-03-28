#include "Headers/AbstractTask.h"

AbstractTask::AbstractTask(string id, string title, string description,
                           string assignee, string creationDate)
    : id(id), title(title), description(description),
    assignee(assignee), creationDate(creationDate)
{}

string AbstractTask::getId()           const { return id;           }
string AbstractTask::getTitle()        const { return title;        }
string AbstractTask::getDescription()  const { return description;  }
string AbstractTask::getAssignee()     const { return assignee;     }
string AbstractTask::getCreationDate() const { return creationDate; }

void AbstractTask::setTitle      (const string& newTitle)    { title       = newTitle;    }
void AbstractTask::setDescription(const string& newDesc)     { description = newDesc;     }
void AbstractTask::setAssignee   (const string& newAssignee) { assignee    = newAssignee; }
