#ifndef TIMEDTASK_H
#define TIMEDTASK_H

#include <string>
using std::string;
#include "AbstractTask.h"

class TimedTask : virtual public AbstractTask {
private:
    string startDate;
    string endDate;
    string startTime;
    int totalDuration;

public:
    TimedTask(string id, string title, string description,
              string assignee, string creationDate,
              string startDate, string endDate,
              string startTime, int totalDuration);
    virtual ~TimedTask() = default;

    string getStartDate()      const;
    string getEndDate()        const;
    string getStartTime()      const;
    int    getTotalDuration()  const;

    void setStartDate (const string& newStartDate);
    void setEndDate   (const string& newEndDate);
    void setStartTime (const string& newStartTime);
    void setDuration  (const int& newDuration);

    bool isOngoing()                    const;
    bool overlapsWith(TimedTask& other)  const;

    virtual void display()          = 0;
    virtual bool remove()           = 0;
    virtual void accept(Visitor& v) = 0;
};

#endif // TIMEDTASK_H
