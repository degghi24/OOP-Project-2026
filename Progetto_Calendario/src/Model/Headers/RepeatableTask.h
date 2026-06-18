#ifndef REPEATABLETASK_H
#define REPEATABLETASK_H

#include <string>
#include <vector>
#include <QBitArray>
#include <QDate>
using std::string;
using std::vector;
#include "AbstractTask.h"



class RepeatableTask : virtual public AbstractTask {
private:

    QBitArray weekDays;
    int intervalDays;
    QDate repeatEndDate;
    bool active;

public:
    RepeatableTask(string title, string description,
                   string assignee, QDate creationDate,
                   QBitArray weekDays, int intervalDays,
                   QDate repeatEndDate, bool active);
    virtual ~RepeatableTask() = default;

    QBitArray    getWeekDays()      const;
    int         getIntervalDays()  const;
    QDate      getRepeatEndDate() const;
    bool        isActive()         const;

    void setWeekDays     (const QBitArray& newWeekDays);
    void setIntervalDays (const int& newIntervalDays);
    void setRepeatEndDate(const QDate& newRepeatEndDate);
    void setActive       (const bool& newActive);

    virtual bool remove()           = 0;
    virtual void accept(ConstVisitor& v) = 0;
    virtual void accept(Visitor& v) = 0;
};

#endif // REPEATABLETASK_H
