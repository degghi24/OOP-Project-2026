#include "data_persistancy/ConstVisitor.h"
#include "Headers/TaskListManager.h"
#include "Headers/Reminder.h"
#include <iostream>
using std::cout;
using std::endl;

Reminder::Reminder(QString title, QString description,
                   QString assignee, QDate creationDate,
                   QDate startDate, QDate endDate,
                   QString startTime, int totalDuration,
                   QString notifyTime, QString alertMessage,
                   bool snoozed, int snoozeMinutes)
    : AbstractTask(title, description, assignee, creationDate),
    TimedTask(title, description, assignee, creationDate,
              startDate, endDate, startTime, totalDuration),
    notifyTime(notifyTime), alertMessage(alertMessage),
    snoozed(snoozed), snoozeMinutes(snoozeMinutes)
{}

QString Reminder::getNotifyTime()    const { return notifyTime;    }
QString Reminder::getAlertMessage()  const { return alertMessage;  }
bool   Reminder::isSnoozed()        const { return snoozed;       }
int    Reminder::getSnoozeMinutes() const { return snoozeMinutes; }

void Reminder::setNotifyTime   (const QString& newNotifyTime)    { notifyTime    = newNotifyTime;    }
void Reminder::setAlertMessage (const QString& newAlertMessage)  { alertMessage  = newAlertMessage;  }
void Reminder::setSnoozed      (const bool& newSnoozed)         { snoozed       = newSnoozed;       }
void Reminder::setSnoozeMinutes(const int& newSnoozeMinutes)    { snoozeMinutes = newSnoozeMinutes; }

void Reminder::snooze(int min) {
    snoozed       = true;
    snoozeMinutes = min;
}

bool Reminder::remove() {
    return TaskListManager::getInstance().removeTask(getId());
}

void Reminder::accept(ConstVisitor& v) {
    v.visit(*this);
}

void Reminder::accept(Visitor &v) {
    v.visit(this);
}

Reminder::~Reminder(){
}
