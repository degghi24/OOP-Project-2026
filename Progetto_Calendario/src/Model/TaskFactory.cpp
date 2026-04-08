#include "Headers/TaskFactory.h"

AbstractTask* TaskFactory::createActivity(
    string id, string title, string description,
    string assignee, string creationDate,
    string startDate, string endDate,
    string startTime, int totalDuration,
    string location, int participantCount,
    string eventType, bool online, string meetingLink)
{
    return new Activity(
        id, title, description, assignee, creationDate,
        startDate, endDate, startTime, totalDuration,
        location, participantCount, eventType, online, meetingLink);
}

AbstractTask* TaskFactory::createReminder(
    string id, string title, string description,
    string assignee, string creationDate,
    string startDate, string endDate,
    string startTime, int totalDuration,
    string notifyTime, string alertMessage,
    bool snoozed, int snoozeMinutes)
{
    return new Reminder(
        id, title, description, assignee, creationDate,
        startDate, endDate, startTime, totalDuration,
        notifyTime, alertMessage, snoozed, snoozeMinutes);
}

AbstractTask* TaskFactory::createWork(
    string id, string title, string description,
    string assignee, string creationDate,
    QBitArray weekDays, int intervalDays,
    string repeatEndDate, bool active,
    QStringList subTasks, int progress,
    string client, string category, string notes)
{
    return new Work(
        id, title, description, assignee, creationDate,
        weekDays, intervalDays, repeatEndDate, active,
        subTasks, progress, client, category, notes);
}

AbstractTask* TaskFactory::createBill(
    string id, string title, string description,
    string assignee, string creationDate,
    string dueDate, Deadline::Priority priority,
    bool completed, bool skipped,
    double amount, bool paid,
    string provider, string IBAN, bool recurring)
{
    return new Bill(
        id, title, description, assignee, creationDate,
        dueDate, priority, completed, skipped,
        amount, paid, provider, IBAN, recurring);
}

AbstractTask* TaskFactory::createProject(
    string id, string title, string description,
    string assignee, string creationDate,
    string dueDate, Deadline::Priority priority,
    bool completed, bool skipped,
    string milestone, QStringList team,
    double budget, string status, QStringList tags)
{
    return new Project(
        id, title, description, assignee, creationDate,
        dueDate, priority, completed, skipped,
        milestone, team, budget, status, tags);
}
