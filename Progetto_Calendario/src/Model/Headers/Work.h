#ifndef WORK_H
#define WORK_H

#include <vector>
#include "QList"
using std::vector;
#include "RepeatableTask.h"

class Work : public RepeatableTask {
private:
    QStringList subTasks;
    int progress;
    QString client;
    QString category;
    QString notes;


public:
    Work(QString title, QString description,
         QString assignee, QDate creationDate,
         QBitArray weekDays,
         QDate repeatEndDate,
         QStringList subTasks, int progress,
         QString client, QString category, QString notes);
    virtual ~Work() override;

    QStringList getSubTasks()  const;
    int            getProgress()  const;
    QString         getClient()    const;
    QString         getCategory()  const;
    QString         getNotes()     const;

    void setSubTasks (const QStringList& newSubTasks);
    void setProgress (const int& newProgress);
    void setClient   (const QString& newClient);
    void setCategory (const QString& newCategory);
    void setNotes    (const QString& newNotes);

    void addSubTask   (const QString& task);
    bool removeSubTask(const QString& task);

    bool remove()           override;
    void accept(ConstVisitor& v) override;
    void accept(Visitor& v) override;
};

#endif // WORK_H
