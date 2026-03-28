#ifndef REMINDER_H
#define REMINDER_H

#include <string>
using std::string;
#include "TimedTask.h"

class Reminder : public TimedTask {
private:
    string notifyTime;
    string alertMessage;
    bool snoozed;
    int snoozeMinutes;

public:
    Reminder(string id, string title, string description,
             string assignee, string creationDate,
             string startDate, string endDate,
             string startTime, int totalDuration,
             string notifyTime, string alertMessage,
             bool snoozed, int snoozeMinutes);
    virtual ~Reminder() = default;

    string getNotifyTime()    const;
    string getAlertMessage()  const;
    bool   isSnoozed()        const;
    int    getSnoozeMinutes() const;

    void setNotifyTime   (const string& newNotifyTime);
    void setAlertMessage (const string& newAlertMessage);
    void setSnoozed      (const bool& newSnoozed);
    void setSnoozeMinutes(const int& newSnoozeMinutes);

    void notify();
    void snooze(int min);

    void display()          override;
    bool remove()           override;
    void accept(Visitor& v) override;
};

#endif // REMINDER_H