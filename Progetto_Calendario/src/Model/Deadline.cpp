#include "Headers/Deadline.h"

Deadline::Deadline(QString title, QString description,
                   QString assignee, QDate creationDate,
                   QDate dueDate, Priority priority,
                   bool completed, bool skipped)
    : AbstractTask(title, description, assignee, creationDate),
    dueDate(dueDate), priority(priority),
    completed(completed), skipped(skipped)
{}

QDate         Deadline::getDueDate()  const { return dueDate;   }
Deadline::Priority Deadline::getPriority() const { return priority;  }
bool           Deadline::isCompleted() const { return completed; }
bool           Deadline::isSkipped()   const { return skipped;   }

void Deadline::setDueDate  (const QDate& newDueDate)     { dueDate    = newDueDate;    }
void Deadline::setPriority (const Priority& newPriority)  { priority   = newPriority;   }
void Deadline::setCompleted(const bool& newCompleted)     { completed  = newCompleted;  }
void Deadline::setSkipped  (const bool& newSkipped)       { skipped    = newSkipped;    }

bool Deadline::isOverdue() const {
    if (!dueDate.isValid())
        return false;

    return QDate::currentDate() > dueDate;
}

int Deadline::daysRemaining() const {
    if (!dueDate.isValid())
        return 0;

    return QDate::currentDate().daysTo(dueDate);
}
