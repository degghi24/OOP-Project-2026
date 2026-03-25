#include "Deadline.h"

Deadline::Deadline(string id, string title, string description,
                   string assignee, string creationDate,
                   string dueDate, Priority priority,
                   bool completed, bool skipped)
    : AbstractTask(id, title, description, assignee, creationDate),
    dueDate(dueDate), priority(priority),
    completed(completed), skipped(skipped)
{}

string         Deadline::getDueDate()  const { return dueDate;   }
Deadline::Priority Deadline::getPriority() const { return priority;  }
bool           Deadline::isCompleted() const { return completed; }
bool           Deadline::isSkipped()   const { return skipped;   }

void Deadline::setDueDate  (const string& newDueDate)     { dueDate    = newDueDate;    }
void Deadline::setPriority (const Priority& newPriority)  { priority   = newPriority;   }
void Deadline::setCompleted(const bool& newCompleted)     { completed  = newCompleted;  }
void Deadline::setSkipped  (const bool& newSkipped)       { skipped    = newSkipped;    }

bool Deadline::isOverdue() const {
    return false; // placeholder
}

int Deadline::daysRemaining() const {
    return 0; // placeholder
}