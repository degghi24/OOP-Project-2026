#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
using std::string;
using std::vector;
#include "Deadline.h"

class Project : public Deadline {
private:
    string milestone;
    vector<string> team;
    double budget;
    string status;
    vector<string> tags;

public:
    Project(string id, string title, string description,
            string assignee, string creationDate,
            string dueDate, Priority priority,
            bool completed, bool skipped,
            string milestone, vector<string> team,
            double budget, string status, vector<string> tags);
    virtual ~Project() = default;

    string         getMilestone() const;
    vector<string> getTeam()      const;
    double         getBudget()    const;
    string         getStatus()    const;
    vector<string> getTags()      const;

    void setMilestone(const string& newMilestone);
    void setBudget   (const double& newBudget);
    void setStatus   (const string& newStatus);

    void addMember   (const string& member);
    bool removeMember(const string& member);
    void addTag      (const string& tag);

    void display()          override;
    bool remove()           override;
    void accept(Visitor& v) override;
};

#endif // PROJECT_H