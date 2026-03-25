#ifndef DEADLINE_H
#define DEADLINE_H

#include <string>
using std::string;
#include "Headers/AbstractTask.h"

class Deadline : virtual public AbstractTask {
public:
    enum Priority { LOW, MEDIUM, HIGH };

private:
    string dueDate;
    Priority priority;
    bool completed;
    bool skipped;

public:
    Deadline(string id, string title, string description,
             string assignee, string creationDate,
             string dueDate, Priority priority,
             bool completed, bool skipped);
    virtual ~Deadline() = default;

    string   getDueDate()  const;
    Priority getPriority() const;
    bool     isCompleted() const;
    bool     isSkipped()   const;

    void setDueDate  (const string& newDueDate);
    void setPriority (const Priority& newPriority);
    void setCompleted(const bool& newCompleted);
    void setSkipped  (const bool& newSkipped);

    bool isOverdue()      const;
    int  daysRemaining()  const;

    virtual void display()          = 0;
    virtual bool remove()           = 0;
    virtual void accept(Visitor& v) = 0;
};

#endif // DEADLINE_H