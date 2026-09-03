#include "data_persistancy/ConstVisitor.h"
#include "qcontainerfwd.h"
#include "Headers/TaskListManager.h"
#include "Headers/Project.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

Project::Project(QString title, QString description,
                 QString assignee, QDate creationDate,
                 QDate dueDate, Priority priority,
                 bool completed, bool skipped,
                 QString milestone, QStringList team,
                 int budget, QString status, QStringList tags)
    : AbstractTask(title, description, assignee, creationDate),
    Deadline(title, description, assignee, creationDate,
             dueDate, priority, completed, skipped),
    milestone(milestone), team(team),
    budget(budget), status(status), tags(tags)
{}

QString         Project::getMilestone() const { return milestone; }
QStringList    Project::getTeam()      const { return team;      }
double         Project::getBudget()    const { return budget;    }
QString         Project::getStatus()    const { return status;    }
QStringList    Project::getTags()      const { return tags;      }

void Project::setMilestone(const QString& newMilestone) { milestone = newMilestone; }
void Project::setBudget   (const double& newBudget)    { budget    = newBudget;    }
void Project::setStatus   (const QString& newStatus)    { status    = newStatus;    }

void Project::addMember(const QString& member) {
    team.push_back(member);
}

bool Project::removeMember(const QString& member) {
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

bool Project::remove() {
    return TaskListManager::getInstance().removeTask(getId());
}

void Project::accept(ConstVisitor& v) {
    v.visit(*this);
}

void Project::accept(Visitor &v) {
    v.visit(this);
}

Project::~Project(){
    team.clear();
    tags.clear();
}
