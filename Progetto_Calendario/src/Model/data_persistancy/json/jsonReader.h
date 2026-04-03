#ifndef JSONREADER_H
#define JSONREADER_H

#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "src/Model/Headers/AbstractTask.h"
#include "src/Model/Headers/Activity.h"
#include "src/Model/Headers/Reminder.h"
#include "src/Model/Headers/Work.h"
#include "src/Model/Headers/Bill.h"
#include "src/Model/Headers/Project.h"

class JsonReader {
private:
    struct AbstractTaskData {
        QString id, title, description, assignee, creationDate;
    };
    struct TimedTaskData {
        QString startDate, endDate, startTime;
        int     totalDuration;
    };
    struct RepeatableTaskData {
        QList<int> weekDays;
        int        intervalDays;
        QString    repeatEndDate;
        bool       active;
    };
    struct DeadlineData {
        QString dueDate;
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