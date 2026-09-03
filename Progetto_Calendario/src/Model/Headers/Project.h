#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include <QStringList>
using std::vector;
#include "Deadline.h"

class Project : public Deadline {
private:
    QString milestone;
    QStringList team;
    double budget;
    QString status;
    QStringList tags;

public:
    Project(QString title, QString description,
            QString assignee, QDate creationDate,
            QDate dueDate, Priority priority,
            bool completed, bool skipped,
            QString milestone, QStringList team,
            int budget, QString status, QStringList tags);
    virtual ~Project() override;

    QString         getMilestone() const;
    QStringList    getTeam()      const;
    double         getBudget()    const;
    QString         getStatus()    const;
    QStringList    getTags()      const;

    void setMilestone(const QString& newMilestone);
    void setBudget   (const double& newBudget);
    void setStatus   (const QString& newStatus);

    void addMember   (const QString& member);
    bool removeMember(const QString& member);
    void addTag      (const QString& tag);

    bool remove()           override;
    void accept(ConstVisitor& v) override;
    void accept(Visitor& v) override;
};

#endif // PROJECT_H
