#ifndef REPEATABLETASK_H
#define REPEATABLETASK_H

#include <string>
#include <vector>
using std::string;
using std::vector;
#include "AbstractTask.h"

class RepeatableTask : virtual public AbstractTask {
private:
    vector<int> weekDays;
    int intervalDays;
    string repeatEndDate;
    bool active;

public:
    RepeatableTask(string id, string title, string description,
                   string assignee, string creationDate,
                   vector<int> weekDays, int intervalDays,
                   string repeatEndDate, bool active);
    virtual ~RepeatableTask() = default;

    vector<int> getWeekDays()      const;
    int         getIntervalDays()  const;
    string      getRepeatEndDate() const;
    bool        isActive()         const;

    void setWeekDays     (const vector<int>& newWeekDays);
    void setIntervalDays (const int& newIntervalDays);
    void setRepeatEndDate(const string& newRepeatEndDate);
    void setActive       (const bool& newActive);

    virtual void display()          = 0;
    virtual bool remove()           = 0;
    virtual void accept(Visitor& v) = 0;
};

#endif // REPEATABLETASK_H
