#include "Headers/RepeatableTask.h"

RepeatableTask::RepeatableTask(string id, string title, string description,
                               string assignee, string creationDate,
                               vector<int> weekDays, int intervalDays,
                               string repeatEndDate, bool active)
    : AbstractTask(id, title, description, assignee, creationDate),
    weekDays(weekDays), intervalDays(intervalDays),
    repeatEndDate(repeatEndDate), active(active)
{}

vector<int> RepeatableTask::getWeekDays()      const { return weekDays;      }
int         RepeatableTask::getIntervalDays()  const { return intervalDays;  }
string      RepeatableTask::getRepeatEndDate() const { return repeatEndDate; }
bool        RepeatableTask::isActive()         const { return active;        }

void RepeatableTask::setWeekDays     (const vector<int>& newWeekDays)       { weekDays      = newWeekDays;      }
void RepeatableTask::setIntervalDays (const int& newIntervalDays)           { intervalDays  = newIntervalDays;  }
void RepeatableTask::setRepeatEndDate(const string& newRepeatEndDate)       { repeatEndDate = newRepeatEndDate; }
void RepeatableTask::setActive       (const bool& newActive)                { active        = newActive;        }
