#ifndef DEADLINE_H
#define DEADLINE_H

#include <QDate>
#include <string>
using std::string;
#include "AbstractTask.h"

class Deadline : virtual public AbstractTask {
public:
    enum Priority { LOW, MEDIUM, HIGH };

private:
    QDate dueDate;
    Priority priority;
    bool completed;
    bool skipped;

public:
    Deadline(string title, string description,
             string assignee, QDate creationDate,
             QDate dueDate, Priority priority,
             bool completed, bool skipped);
    virtual ~Deadline() = default;

    QDate   getDueDate()  const;
    Priority getPriority() const;
    bool     isCompleted() const;
    bool     isSkipped()   const;

    void setDueDate  (const QDate& newDueDate);
    void setPriority (const Priority& newPriority);
    void setCompleted(const bool& newCompleted);
    void setSkipped  (const bool& newSkipped);

    bool isOverdue()      const;
    int  daysRemaining()  const;

    virtual bool remove()           = 0;
    virtual void accept(ConstVisitor& v) = 0;
    virtual void accept(Visitor& v) = 0;
};

#endif // DEADLINE_H
