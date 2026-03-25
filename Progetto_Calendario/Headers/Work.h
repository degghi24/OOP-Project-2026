#ifndef WORK_H
#define WORK_H

#include <string>
#include <vector>
using std::string;
using std::vector;
#include "RepeatableTask.h"

class Work : public RepeatableTask {
private:
    vector<string> subTasks;
    int progress;
    string client;
    string category;
    string notes;

public:
    Work(string id, string title, string description,
         string assignee, string creationDate,
         vector<int> weekDays, int intervalDays,
         string repeatEndDate, bool active,
         vector<string> subTasks, int progress,
         string client, string category, string notes);
    virtual ~Work() = default;

    vector<string> getSubTasks()  const;
    int            getProgress()  const;
    string         getClient()    const;
    string         getCategory()  const;
    string         getNotes()     const;

    void setSubTasks (const vector<string>& newSubTasks);
    void setProgress (const int& newProgress);
    void setClient   (const string& newClient);
    void setCategory (const string& newCategory);
    void setNotes    (const string& newNotes);

    void addSubTask   (const string& task);
    bool removeSubTask(const string& task);

    void display()          override;
    bool remove()           override;
    void accept(Visitor& v) override;
};

#endif // WORK_H