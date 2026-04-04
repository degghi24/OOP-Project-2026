#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include <QStringList>
using std::string;
using std::vector;
#include "Deadline.h"

class Project : public Deadline {
private:
    string milestone;
    QStringList team;
    double budget;
    string status;
    QStringList tags;

public:
    Project(string id, string title, string description,
            string assignee, string creationDate,
            string dueDate, Priority priority,
            bool completed, bool skipped,
            string milestone,QStringList team,
            double budget, string status, QStringList tags);
    virtual ~Project() = default;

    string         getMilestone() const;
    QStringList    getTeam()      const;
    double         getBudget()    const;
    string         getStatus()    const;
    QStringList    getTags()      const;

    void setMilestone(const string& newMilestone);
    void setBudget   (const double& newBudget);
    void setStatus   (const string& newStatus);

    void addMember   (const QString& member);
    bool removeMember(const string& member);
    void addTag      (const QString& tag);

    void display()          override;
    bool remove()           override;
    void accept(Visitor& v) override;
};

#endif // PROJECT_H
