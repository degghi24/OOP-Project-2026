#include "Headers/TimedTask.h"

TimedTask::TimedTask(string id, string title, string description,
                     string assignee, string creationDate,
                     string startDate, string endDate,
                     string startTime, int totalDuration)
    : AbstractTask(id, title, description, assignee, creationDate),
    startDate(startDate), endDate(endDate),
    startTime(startTime), totalDuration(totalDuration)
{}

string TimedTask::getStartDate()     const { return startDate;     }
string TimedTask::getEndDate()       const { return endDate;       }
string TimedTask::getStartTime()     const { return startTime;     }
int    TimedTask::getTotalDuration() const { return totalDuration; }

void TimedTask::setStartDate (const string& newStartDate) { startDate     = newStartDate; }
void TimedTask::setEndDate   (const string& newEndDate)   { endDate       = newEndDate;   }
void TimedTask::setStartTime (const string& newStartTime) { startTime     = newStartTime; }
void TimedTask::setDuration  (const int& newDuration)     { totalDuration = newDuration;  }

bool TimedTask::isOngoing() const {
    return false; // placeholder
}

bool TimedTask::overlapsWith(TimedTask& other) const {
    return false; // placeholder
}
