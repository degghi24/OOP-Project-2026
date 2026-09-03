#include "xmlReader.h"

XmlReader::XmlReader() {}

XmlReader::AbstractTaskData XmlReader::readAbstractTaskData(QXmlStreamReader& xml) {
    AbstractTaskData d;
    auto attr = xml.attributes();
    d.id           = attr.value("id").toString();
    d.title        = attr.value("title").toString();
    d.description  = attr.value("description").toString();
    d.assignee     = attr.value("assignee").toString();
    d.creationDate = QDate::fromString(attr.value("creationDate").toString(),"yyyy-MM-d");
    return d;
}

XmlReader::TimedTaskData XmlReader::readTimedTaskData(QXmlStreamReader& xml) {
    TimedTaskData d;
    auto attr = xml.attributes();
    d.startDate     = QDate::fromString(attr.value("startDate").toString(),"yyyy-MM-d");
    d.endDate       = QDate::fromString(attr.value("endDate").toString(),"yyyy-MM-d");
    d.startTime     = attr.value("startTime").toString();
    d.totalDuration = attr.value("totalDuration").toInt();
    return d;
}

XmlReader::RepeatableTaskData XmlReader::readRepeatableTaskData(QXmlStreamReader& xml) {
    RepeatableTaskData d;
    auto attr = xml.attributes();
    d.repeatEndDate = QDate::fromString(attr.value("repeatEndDate").toString(),"yyyy-MM-d");

    QStringList split = attr.value("weekDays").toString().split(",", Qt::SkipEmptyParts);
    d.weekDays.resize(7);
    for(int i = 0; i < split.size(); ++i){
        d.weekDays.setBit(i, split[i].toInt());
    }

    return d;
}

XmlReader::DeadlineData XmlReader::readDeadlineData(QXmlStreamReader& xml) {
    DeadlineData d;
    auto attr = xml.attributes();
    d.dueDate   = QDate::fromString(attr.value("dueDate").toString(),"yyyy-MM-d");
    d.priority  = attr.value("priority").toInt();
    d.completed = (attr.value("completed").toString() == "true" || attr.value("completed").toInt() == 1);
    d.skipped   = (attr.value("skipped").toString() == "true" || attr.value("skipped").toInt() == 1);
    return d;
}

Activity* XmlReader::readActivity(QXmlStreamReader& xml) {
    AbstractTaskData a = readAbstractTaskData(xml);
    TimedTaskData    t = readTimedTaskData(xml);
    auto attr = xml.attributes();

    Activity* res = new Activity(
        a.title,
        a.description, a.assignee,
        a.creationDate,
        t.startDate, t.endDate,
        t.startTime, t.totalDuration,
        attr.value("location").toString(),
        attr.value("participantCount").toInt(),
        attr.value("eventType").toString(),
        (attr.value("online").toString() == "true"),
        attr.value("meetingLink").toString()
        );

    xml.skipCurrentElement();
    return res;
}

Reminder* XmlReader::readReminder(QXmlStreamReader& xml) {
    AbstractTaskData a = readAbstractTaskData(xml);
    TimedTaskData    t = readTimedTaskData(xml);
    auto attr = xml.attributes();

    Reminder* res = new Reminder(
       a.title,
        a.description, a.assignee,
        a.creationDate,
        t.startDate, t.endDate,
        t.startTime, t.totalDuration,
        attr.value("notifyTime").toString(),
        attr.value("alertMessage").toString(),
        (attr.value("snoozed").toString() == "true"),
        attr.value("snoozeMinutes").toInt()
        );

    xml.skipCurrentElement();
    return res;
}

Work* XmlReader::readWork(QXmlStreamReader& xml) {
    AbstractTaskData   a = readAbstractTaskData(xml);
    RepeatableTaskData r = readRepeatableTaskData(xml);
    auto attr = xml.attributes();

    QStringList subList = attr.value("subTasks").toString().split("|", Qt::SkipEmptyParts);

    Work* res = new Work(
        a.title,
        a.description, a.assignee,
        a.creationDate,
        r.weekDays,
        r.repeatEndDate,
        subList, attr.value("progress").toInt(),
        attr.value("client").toString(),
        attr.value("category").toString(),
        attr.value("notes").toString()
        );

    xml.skipCurrentElement();
    return res;
}

Bill* XmlReader::readBill(QXmlStreamReader& xml) {
    AbstractTaskData a = readAbstractTaskData(xml);
    DeadlineData     d = readDeadlineData(xml);
    auto attr = xml.attributes();

    Bill* res = new Bill(
        a.title,
        a.description, a.assignee,
        a.creationDate,
        d.dueDate,
        static_cast<Deadline::Priority>(d.priority),
        d.completed, d.skipped,
        attr.value("amount").toDouble(),
        (attr.value("paid").toString() == "true"),
        attr.value("provider").toString(),
        attr.value("IBAN").toString(),
        (attr.value("recurring").toString() == "true")
        );

    xml.skipCurrentElement();
    return res;
}

Project* XmlReader::readProject(QXmlStreamReader& xml) {
    AbstractTaskData a = readAbstractTaskData(xml);
    DeadlineData     d = readDeadlineData(xml);
    auto attr = xml.attributes();

    auto toStdVec = [](const QString& input) {
        QStringList list = input.split("|", Qt::SkipEmptyParts);
        return list;
    };

    Project* res = new Project(
        a.title,
        a.description, a.assignee,
        a.creationDate,
        d.dueDate,
        static_cast<Deadline::Priority>(d.priority),
        d.completed, d.skipped,
        attr.value("milestone").toString(),
        toStdVec(attr.value("team").toString()),
        attr.value("budget").toDouble(),
        attr.value("status").toString(),
        toStdVec(attr.value("tags").toString())
        );

    xml.skipCurrentElement();
    return res;
}

QList<AbstractTask*> XmlReader::readAll(const QString& filename) {
    QList<AbstractTask*> tasks;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return tasks;

    QXmlStreamReader xml(&file);

    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.isStartElement()) {
            QString name = xml.name().toString().toLower();
            if (name == "tasks") continue;

            AbstractTask* t = nullptr;
            if      (name == "activity") t = readActivity(xml);
            else if (name == "reminder") t = readReminder(xml);
            else if (name == "work")     t = readWork(xml);
            else if (name == "bill")     t = readBill(xml);
            else if (name == "project")  t = readProject(xml);

            if (t) tasks.append(t);
        }
    }
    file.close();
    return tasks;
}
