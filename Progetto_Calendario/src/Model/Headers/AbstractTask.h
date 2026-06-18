#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include <string>
#include <QDate>
using std::string;
#include "../data_persistancy/ConstVisitor.h"
#include "../../src/GUI/GuiVisitors/Visitor.h"

class AbstractTask {
private:
    string id;
    string title;
    string description;
    string assignee;
    QDate creationDate;

public:
    AbstractTask(string title, string description,
                 string assignee, QDate creationDate);
    virtual ~AbstractTask() = default;

    string getId()           const;
    string getTitle()        const;
    string getDescription()  const;
    string getAssignee()     const;
    QDate getCreationDate() const;

    void setId         (const std::string& newId);
    void setTitle      (const string& newTitle);
    void setDescription(const string& newDesc);
    void setAssignee   (const string& newAssignee);

    virtual bool remove()           = 0;
    virtual void accept(ConstVisitor& v) = 0;
    virtual void accept(Visitor& v) = 0;

};

#endif // ABSTRACTTASK_H
