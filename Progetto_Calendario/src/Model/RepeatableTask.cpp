#include "Headers/RepeatableTask.h"

RepeatableTask::RepeatableTask(QString title, QString description,
                               QString assignee, QDate creationDate,
                               QBitArray weekDays,
                               QDate repeatEndDate)
    : AbstractTask(title, description, assignee, creationDate),
    weekDays(weekDays),
    repeatEndDate(repeatEndDate)
{}

QBitArray   RepeatableTask::getWeekDays()      const { return weekDays;      }
QDate      RepeatableTask::getRepeatEndDate() const { return repeatEndDate; }

void RepeatableTask::setWeekDays     (const QBitArray& newWeekDays)         { weekDays      = newWeekDays;      }
void RepeatableTask::setRepeatEndDate(const QDate& newRepeatEndDate)       { repeatEndDate = newRepeatEndDate; }

RepeatableTask::~RepeatableTask(){
    weekDays.clear();
}
