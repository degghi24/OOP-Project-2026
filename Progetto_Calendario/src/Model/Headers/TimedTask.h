#ifndef TIMEDTASK_H
#define TIMEDTASK_H

#include <string>
using std::string;
#include "AbstractTask.h"

#include <QDate>

class TimedTask : virtual public AbstractTask {
private:
    QDate startDate;
    QDate endDate;
    string startTime;
    int totalDuration;

public:
    TimedTask(string title, string description,
              string assignee, string creationDate,
              QDate startDate, QDate endDate,
              string startTime, int totalDuration);
    virtual ~TimedTask() = default;

    QDate getStartDate()      const;
    QDate getEndDate()        const;
    string getStartTime()      const;
    int    getTotalDuration()  const;

    void setStartDate (const QDate& newStartDate);
    void setEndDate   (const QDate& newEndDate);
    void setStartTime (const string& newStartTime);
    void setDuration  (const int& newDuration);

    bool isOngoing()                    const;
    bool overlapsWith(TimedTask& other)  const;

    virtual void display()          = 0;
    virtual bool remove()           = 0;
    virtual void accept(Visitor& v) = 0;
};

#endif // TIMEDTASK_H
