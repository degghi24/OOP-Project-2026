#include "data_persistancy/Visitor.h"
#include "Headers/Work.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

Work::Work(string id, string title, string description,
           string assignee, string creationDate,
           vector<int> weekDays, int intervalDays,
           string repeatEndDate, bool active,
           vector<string> subTasks, int progress,
           string client, string category, string notes)
    : AbstractTask(id, title, description, assignee, creationDate),
    RepeatableTask(id, title, description, assignee, creationDate,
                   weekDays, intervalDays, repeatEndDate, active),
    subTasks(subTasks), progress(progress),
    client(client), category(category), notes(notes)
{}

vector<string> Work::getSubTasks()  const { return subTasks; }
int            Work::getProgress()  const { return progress; }
string         Work::getClient()    const { return client;   }
string         Work::getCategory()  const { return category; }
string         Work::getNotes()     const { return notes;    }

void Work::setSubTasks (const vector<string>& newSubTasks) { subTasks = newSubTasks; }
void Work::setProgress (const int& newProgress)            { progress = newProgress; }
void Work::setClient   (const string& newClient)           { client   = newClient;   }
void Work::setCategory (const string& newCategory)         { category = newCategory; }
void Work::setNotes    (const string& newNotes)            { notes    = newNotes;    }

void Work::addSubTask(const string& task) {
    subTasks.push_back(task);
}

bool Work::removeSubTask(const string& task) {
    auto it = std::find(subTasks.begin(), subTasks.end(), task);
    if (it != subTasks.end()) {
        subTasks.erase(it);
        return true;
    }
    return false;
}

void Work::display() {
    cout << "Work: "      << getTitle() << endl;
    cout << "Client: "    << client << endl;
    cout << "Category: "  << category << endl;
    cout << "Progress: "  << progress << "%" << endl;
    cout << "Subtasks: "  << subTasks.size() << endl;
}

bool Work::remove() {
    return true; // placeholder
}

void Work::accept(Visitor& v) {
    v.visit(*this);
}
