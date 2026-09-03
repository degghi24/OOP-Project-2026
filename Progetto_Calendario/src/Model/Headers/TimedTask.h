#ifndef TIMEDTASK_H
#define TIMEDTASK_H

#include "AbstractTask.h"

#include <QDate>

class TimedTask : virtual public AbstractTask {
private:
    QDate startDate;
    QDate endDate;
    QString startTime;
    int totalDuration;

public:
    TimedTask(QString title, QString description,
              QString assignee, QDate creationDate,
              QDate startDate, QDate endDate,
              QString startTime, int totalDuration);
    virtual ~TimedTask() = default;

    QDate getStartDate()      const;
    QDate getEndDate()        const;
    QString getStartTime()      const;
    int    getTotalDuration()  const;

    void setStartDate (const QDate& newStartDate);
    void setEndDate   (const QDate& newEndDate);
    void setStartTime (const QString& newStartTime);
    void setDuration  (const int& newDuration);

    bool isOngoing()                    const;
    bool overlapsWith(TimedTask& other)  const;

    virtual bool remove()           = 0;
    virtual void accept(ConstVisitor& v) = 0;
    virtual void accept(Visitor& v) = 0;
};

#endif // TIMEDTASK_H
