#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include <QString>
#include <QDate>
#include "../data_persistancy/ConstVisitor.h"
#include "../../GUI/GuiVisitors/Visitor.h"

class AbstractTask {
private:
    unsigned int id;
    QString title;
    QString description;
    QString assignee;
    QDate creationDate;

public:
    AbstractTask(QString title, QString description,
                 QString assignee, QDate creationDate);
    virtual ~AbstractTask() = default;

    unsigned int getId()           const;
    QString getTitle()        const;
    QString getDescription()  const;
    QString getAssignee()     const;
    QDate getCreationDate() const;

    void setId         (const unsigned int &newId);
    void setTitle      (const QString& newTitle);
    void setDescription(const QString& newDesc);
    void setAssignee   (const QString& newAssignee);

    virtual bool remove()           = 0;
    virtual void accept(ConstVisitor& v) = 0;
    virtual void accept(Visitor& v) = 0;

};

#endif // ABSTRACTTASK_H
