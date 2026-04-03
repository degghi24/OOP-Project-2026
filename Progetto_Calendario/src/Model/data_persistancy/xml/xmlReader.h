#ifndef XMLREADER_H
#define XMLREADER_H

#include <QList>
#include <QFile>
#include <QXmlStreamReader>

#include "src/Model/Headers/AbstractTask.h"
#include "src/Model/Headers/Activity.h"
#include "src/Model/Headers/Reminder.h"
#include "src/Model/Headers/Work.h"
#include "src/Model/Headers/Bill.h"
#include "src/Model/Headers/Project.h"

class XmlReader {
private:

    struct AbstractTaskData {
        QString id, title, description, assignee, creationDate;
    };

    struct TimedTaskData {
        QString startDate, endDate, startTime;
        int totalDuration;
    };

    struct RepeatableTaskData {
        QList<int> weekDays;
        int intervalDays;
        QString repeatEndDate;
        bool active;
    };

    struct DeadlineData {
        QString dueDate;
        int priority;
        bool completed, skipped;
    };

    AbstractTaskData readAbstractTaskData(QXmlStreamReader& xml);
    TimedTaskData readTimedTaskData(QXmlStreamReader& xml);
    RepeatableTaskData readRepeatableTaskData(QXmlStreamReader& xml);
    DeadlineData readDeadlineData(QXmlStreamReader& xml);

    Activity* readActivity(QXmlStreamReader& xml);
    Reminder* readReminder(QXmlStreamReader& xml);
    Work* readWork(QXmlStreamReader& xml);
    Bill* readBill(QXmlStreamReader& xml);
    Project* readProject(QXmlStreamReader& xml);

public:
    XmlReader();
    QList<AbstractTask*> readAll(const QString& filename);
};

#endif