#ifndef JSONREADER_H
#define JSONREADER_H

#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "../../Headers/AbstractTask.h"
#include "../../Headers/Activity.h"
#include "../../Headers/Reminder.h"
#include "../../Headers/Work.h"
#include "../../Headers/Bill.h"
#include "../../Headers/Project.h"

class JsonReader {
private:
    struct AbstractTaskData {
        QString id, title, description, assignee;
        QDate creationDate;
    };
    struct TimedTaskData {
        QDate startDate, endDate;
        QString startTime;
        int     totalDuration;
    };
    struct RepeatableTaskData {
        QBitArray  weekDays;
        QDate    repeatEndDate;
    };
    struct DeadlineData {
        QDate dueDate;
        int     priority;
        bool    completed, skipped;
    };

    AbstractTaskData  readAbstractTaskData (const QJsonObject& obj);
    TimedTaskData     readTimedTaskData    (const QJsonObject& obj);
    RepeatableTaskData readRepeatableTaskData(const QJsonObject& obj);
    DeadlineData      readDeadlineData     (const QJsonObject& obj);

    Activity* readActivity(const QJsonObject& obj);
    Reminder* readReminder(const QJsonObject& obj);
    Work*     readWork    (const QJsonObject& obj);
    Bill*     readBill    (const QJsonObject& obj);
    Project*  readProject (const QJsonObject& obj);

public:
    JsonReader();
    QList<AbstractTask*> readAll(const QString& filename);
};

#endif // JSONREADER_H
