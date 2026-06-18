#include "data_persistancy/ConstVisitor.h"
#include "Headers/Reminder.h"
#include <iostream>
using std::cout;
using std::endl;

Reminder::Reminder(string title, string description,
                   string assignee, QDate creationDate,
                   QDate startDate, QDate endDate,
                   string startTime, int totalDuration,
                   string notifyTime, string alertMessage,
                   bool snoozed, int snoozeMinutes)
    : AbstractTask(title, description, assignee, creationDate),
    TimedTask(title, description, assignee, creationDate,
              startDate, endDate, startTime, totalDuration),
    notifyTime(notifyTime), alertMessage(alertMessage),
    snoozed(snoozed), snoozeMinutes(snoozeMinutes)
{}

string Reminder::getNotifyTime()    const { return notifyTime;    }
string Reminder::getAlertMessage()  const { return alertMessage;  }
bool   Reminder::isSnoozed()        const { return snoozed;       }
int    Reminder::getSnoozeMinutes() const { return snoozeMinutes; }

void Reminder::setNotifyTime   (const string& newNotifyTime)    { notifyTime    = newNotifyTime;    }
void Reminder::setAlertMessage (const string& newAlertMessage)  { alertMessage  = newAlertMessage;  }
void Reminder::setSnoozed      (const bool& newSnoozed)         { snoozed       = newSnoozed;       }
void Reminder::setSnoozeMinutes(const int& newSnoozeMinutes)    { snoozeMinutes = newSnoozeMinutes; }

void Reminder::notify() {
    cout << "Reminder: " << alertMessage << endl;
}

void Reminder::snooze(int min) {
    snoozed       = true;
    snoozeMinutes = min;
}

bool Reminder::remove() {
    return true; // placeholder
}

void Reminder::accept(ConstVisitor& v) {
    v.visit(*this);
}

void Reminder::accept(Visitor &v) {
    v.visit(this);
}
