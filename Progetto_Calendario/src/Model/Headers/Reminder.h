#ifndef REMINDER_H
#define REMINDER_H

#include "TimedTask.h"

class Reminder : public TimedTask {
private:
    QString notifyTime;
    QString alertMessage;
    bool snoozed;
    int snoozeMinutes;


public:
    Reminder(QString title, QString description,
             QString assignee, QDate creationDate,
             QDate startDate, QDate endDate,
             QString startTime, int totalDuration,
             QString notifyTime, QString alertMessage,
             bool snoozed, int snoozeMinutes);
    virtual ~Reminder() override;

    QString getNotifyTime()    const;
    QString getAlertMessage()  const;
    bool   isSnoozed()        const;
    int    getSnoozeMinutes() const;

    void setNotifyTime   (const QString& newNotifyTime);
    void setAlertMessage (const QString& newAlertMessage);
    void setSnoozed      (const bool& newSnoozed);
    void setSnoozeMinutes(const int& newSnoozeMinutes);

    void snooze(int min);

    bool remove()           override;
    void accept(ConstVisitor& v) override;
    void accept(Visitor& v) override;
};

#endif // REMINDER_H
