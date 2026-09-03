#include "Headers/TimedTask.h"

TimedTask::TimedTask(QString title, QString description,
                     QString assignee, QDate creationDate,
                     QDate startDate, QDate endDate,
                     QString startTime, int totalDuration)
    : AbstractTask(title, description, assignee, creationDate),
    startDate(startDate), endDate(endDate),
    startTime(startTime), totalDuration(totalDuration)
{}

QDate TimedTask::getStartDate()     const { return startDate;     }
QDate TimedTask::getEndDate()       const { return endDate;       }
QString TimedTask::getStartTime()     const { return startTime;     }
int    TimedTask::getTotalDuration() const { return totalDuration; }

void TimedTask::setStartDate (const QDate& newStartDate) { startDate     = newStartDate; }
void TimedTask::setEndDate   (const QDate& newEndDate)   { endDate       = newEndDate;   }
void TimedTask::setStartTime (const QString& newStartTime) { startTime     = newStartTime; }
void TimedTask::setDuration  (const int& newDuration)     { totalDuration = newDuration;  }

bool TimedTask::isOngoing() const {
    QDate today = QDate::currentDate();

    return today >= startDate && today <= endDate;
}

bool TimedTask::overlapsWith(TimedTask& other) const {
    return !(endDate < other.startDate || startDate > other.endDate);
}
