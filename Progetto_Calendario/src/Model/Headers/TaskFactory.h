#ifndef TASKFACTORY_H
#define TASKFACTORY_H

#include <string>
#include "src/Model/Headers/AbstractTask.h"
#include "src/Model/Headers/Deadline.h"
#include "src/Model/Headers/Activity.h"
#include "src/Model/Headers/Reminder.h"
#include "src/Model/Headers/Work.h"
#include "src/Model/Headers/Bill.h"
#include "src/Model/Headers/Project.h"
using std::string;

class TaskFactory {
public:
    static AbstractTask* createActivity(
        string id, string title, string description,
        string assignee, string creationDate,
        string startDate, string endDate,
        string startTime, int totalDuration,
        string location, int participantCount,
        string eventType, bool online, string meetingLink);

    static AbstractTask* createReminder(
        string id, string title, string description,
        string assignee, string creationDate,
        string startDate, string endDate,
        string startTime, int totalDuration,
        string notifyTime, string alertMessage,
        bool snoozed, int snoozeMinutes);

    static AbstractTask* createWork(
        string id, string title, string description,
        string assignee, string creationDate,
        QBitArray weekDays, int intervalDays,
        string repeatEndDate, bool active,
        QStringList subTasks, int progress,
        string client, string category, string notes);

    static AbstractTask* createBill(
        string id, string title, string description,
        string assignee, string creationDate,
        string dueDate, Deadline::Priority priority,
        bool completed, bool skipped,
        double amount, bool paid,
        string provider, string IBAN, bool recurring);

    static AbstractTask* createProject(
        string id, string title, string description,
        string assignee, string creationDate,
        string dueDate, Deadline::Priority priority,
        bool completed, bool skipped,
        string milestone, QStringList team,
        double budget, string status, QStringList tags);
};

#endif // TASKFACTORY_H
