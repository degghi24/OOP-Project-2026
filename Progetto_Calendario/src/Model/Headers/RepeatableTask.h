#ifndef REPEATABLETASK_H
#define REPEATABLETASK_H

#include <string>
#include <vector>
#include <QBitArray>
using std::string;
using std::vector;
#include "AbstractTask.h"



class RepeatableTask : virtual public AbstractTask {
private:

    QBitArray weekDays;
    int intervalDays;
    string repeatEndDate;
    bool active;

public:
    RepeatableTask(string id, string title, string description,
                   string assignee, string creationDate,
                   QBitArray weekDays, int intervalDays,
                   string repeatEndDate, bool active);
    virtual ~RepeatableTask() = default;

    QBitArray    getWeekDays()      const;
    int         getIntervalDays()  const;
    string      getRepeatEndDate() const;
    bool        isActive()         const;

    void setWeekDays     (const QBitArray& newWeekDays);
    void setIntervalDays (const int& newIntervalDays);
    void setRepeatEndDate(const string& newRepeatEndDate);
    void setActive       (const bool& newActive);

    virtual void display()          = 0;
    virtual bool remove()           = 0;
    virtual void accept(Visitor& v) = 0;
};

#endif // REPEATABLETASK_H
