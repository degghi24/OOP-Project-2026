#ifndef WORK_H
#define WORK_H

#include <string>
#include <vector>
#include "QList"
using std::string;
using std::vector;
#include "RepeatableTask.h"

class Work : public RepeatableTask {
private:
    QStringList subTasks;
    int progress;
    string client;
    string category;
    string notes;

public:
    Work(string id, string title, string description,
         string assignee, string creationDate,
         QBitArray weekDays, int intervalDays,
         string repeatEndDate, bool active,
         QStringList subTasks, int progress,
         string client, string category, string notes);
    virtual ~Work() = default;

    QStringList getSubTasks()  const;
    int            getProgress()  const;
    string         getClient()    const;
    string         getCategory()  const;
    string         getNotes()     const;

    void setSubTasks (const QStringList& newSubTasks);
    void setProgress (const int& newProgress);
    void setClient   (const string& newClient);
    void setCategory (const string& newCategory);
    void setNotes    (const string& newNotes);

    void addSubTask   (const QString& task);
    bool removeSubTask(const QString& task);

    void display()          override;
    bool remove()           override;
    void accept(Visitor& v) override;
};

#endif // WORK_H
