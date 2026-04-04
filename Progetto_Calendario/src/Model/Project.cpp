#include "data_persistancy/Visitor.h"
#include "qcontainerfwd.h"
#include "Headers/Project.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

Project::Project(string id, string title, string description,
                 string assignee, string creationDate,
                 string dueDate, Priority priority,
                 bool completed, bool skipped,
                 string milestone, QStringList team,
                 double budget, string status, QStringList tags)
    : AbstractTask(id, title, description, assignee, creationDate),
    Deadline(id, title, description, assignee, creationDate,
             dueDate, priority, completed, skipped),
    milestone(milestone), team(team),
    budget(budget), status(status), tags(tags)
{}

string         Project::getMilestone() const { return milestone; }
QStringList    Project::getTeam()      const { return team;      }
double         Project::getBudget()    const { return budget;    }
string         Project::getStatus()    const { return status;    }
QStringList    Project::getTags()      const { return tags;      }

void Project::setMilestone(const string& newMilestone) { milestone = newMilestone; }
void Project::setBudget   (const double& newBudget)    { budget    = newBudget;    }
void Project::setStatus   (const string& newStatus)    { status    = newStatus;    }

void Project::addMember(const QString& member) {
    team.push_back(member);
}

bool Project::removeMember(const string& member) {
    auto it = std::find(team.begin(), team.end(), member);
    if (it != team.end()) {
        team.erase(it);
        return true;
    }
    return false;
}

void Project::addTag(const QString& tag) {
    tags.push_back(tag);
}

void Project::display() {
    cout << "Project: "   << getTitle() << endl;
    cout << "Milestone: " << milestone << endl;
    cout << "Budget: "    << budget << endl;
    cout << "Status: "    << status << endl;
    cout << "Team: "      << team.size() << " members" << endl;
}

bool Project::remove() {
    return true; // placeholder
}

void Project::accept(Visitor& v) {
    v.visit(*this);
}
