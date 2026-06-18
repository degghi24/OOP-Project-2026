#include "Headers/TimedTask.h"

TimedTask::TimedTask(string title, string description,
                     string assignee, QDate creationDate,
                     QDate startDate, QDate endDate,
                     string startTime, int totalDuration)
    : AbstractTask(title, description, assignee, creationDate),
    startDate(startDate), endDate(endDate),
    startTime(startTime), totalDuration(totalDuration)
{}

QDate TimedTask::getStartDate()     const { return startDate;     }
QDate TimedTask::getEndDate()       const { return endDate;       }
string TimedTask::getStartTime()     const { return startTime;     }
int    TimedTask::getTotalDuration() const { return totalDuration; }

void TimedTask::setStartDate (const QDate& newStartDate) { startDate     = newStartDate; }
void TimedTask::setEndDate   (const QDate& newEndDate)   { endDate       = newEndDate;   }
void TimedTask::setStartTime (const string& newStartTime) { startTime     = newStartTime; }
void TimedTask::setDuration  (const int& newDuration)     { totalDuration = newDuration;  }

bool TimedTask::isOngoing() const {
    return false; // placeholder
}

bool TimedTask::overlapsWith(TimedTask& other) const {
    return false; // placeholder
}
