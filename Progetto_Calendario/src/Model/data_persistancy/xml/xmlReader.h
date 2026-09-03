#ifndef XMLREADER_H
#define XMLREADER_H

#include <QList>
#include <QFile>
#include <QXmlStreamReader>

#include "../../Headers/AbstractTask.h"
#include "../../Headers/Activity.h"
#include "../../Headers/Reminder.h"
#include "../../Headers/Work.h"
#include "../../Headers/Bill.h"
#include "../../Headers/Project.h"

class XmlReader {
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
