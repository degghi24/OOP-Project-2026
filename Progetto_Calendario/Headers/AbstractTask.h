#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include <string>
using std::string;
#include "Model/Visitor.h"

class AbstractTask {
private:
    string id;
    string title;
    string description;
    string assignee;
    string creationDate;

public:
    AbstractTask(string id, string title, string description,
                 string assignee, string creationDate);
    virtual ~AbstractTask() = default;

    string getId()           const;
    string getTitle()        const;
    string getDescription()  const;
    string getAssignee()     const;
    string getCreationDate() const;

    void setTitle      (const string& newTitle);
    void setDescription(const string& newDesc);
    void setAssignee   (const string& newAssignee);

    virtual void display()          = 0;
    virtual bool remove()           = 0;
    virtual void accept(Visitor& v) = 0;
};

#endif // ABSTRACTTASK_H