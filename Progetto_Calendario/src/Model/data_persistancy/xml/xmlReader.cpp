#include "src/Model/data_persistancy/xml/xmlReader.h"

XmlReader::XmlReader() {}

XmlReader::AbstractTaskData XmlReader::readAbstractTaskData(QXmlStreamReader& xml) {
    AbstractTaskData d;
    auto attr = xml.attributes();
    d.id           = attr.value("id").toString();
    d.title        = attr.value("title").toString();
    d.description  = attr.value("description").toString();
    d.assignee     = attr.value("assignee").toString();
    d.creationDate = attr.value("creationDate").toString();
    return d;
}

XmlReader::TimedTaskData XmlReader::readTimedTaskData(QXmlStreamReader& xml) {
    TimedTaskData d;
    auto attr = xml.attributes();
    d.startDate     = attr.value("startDate").toString();
    d.endDate       = attr.value("endDate").toString();
    d.startTime     = attr.value("startTime").toString();
    d.totalDuration = attr.value("totalDuration").toInt();
    return d;
}

XmlReader::RepeatableTaskData XmlReader::readRepeatableTaskData(QXmlStreamReader& xml) {
    RepeatableTaskData d;
    auto attr = xml.attributes();
    d.intervalDays  = attr.value("intervalDays").toInt();
    d.repeatEndDate = attr.value("repeatEndDate").toString();
    d.active        = (attr.value("active").toString() == "true" || attr.value("active").toInt() == 1);

    QStringList split = attr.value("weekDays").toString().split(",", Qt::SkipEmptyParts);

    for(int i = 0; i < split.size(); ++i){
        d.weekDays.setBit(i, split[i].toInt());
    }

    return d;
}

XmlReader::DeadlineData XmlReader::readDeadlineData(QXmlStreamReader& xml) {
    DeadlineData d;
    auto attr = xml.attributes();
    d.dueDate   = attr.value("dueDate").toString();
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
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        t.startDate.toStdString(), t.endDate.toStdString(),
        t.startTime.toStdString(), t.totalDuration,
        attr.value("location").toString().toStdString(),
        attr.value("participantCount").toInt(),
        attr.value("eventType").toString().toStdString(),
        (attr.value("online").toString() == "true"),
        attr.value("meetingLink").toString().toStdString()
        );

    xml.skipCurrentElement();
    return res;
}

Reminder* XmlReader::readReminder(QXmlStreamReader& xml) {
    AbstractTaskData a = readAbstractTaskData(xml);
    TimedTaskData    t = readTimedTaskData(xml);
    auto attr = xml.attributes();

    Reminder* res = new Reminder(
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        t.startDate.toStdString(), t.endDate.toStdString(),
        t.startTime.toStdString(), t.totalDuration,
        attr.value("notifyTime").toString().toStdString(),
        attr.value("alertMessage").toString().toStdString(),
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
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        r.weekDays, r.intervalDays,
        r.repeatEndDate.toStdString(), r.active,
        subList, attr.value("progress").toInt(),
        attr.value("client").toString().toStdString(),
        attr.value("category").toString().toStdString(),
        attr.value("notes").toString().toStdString()
        );

    xml.skipCurrentElement();
    return res;
}

Bill* XmlReader::readBill(QXmlStreamReader& xml) {
    AbstractTaskData a = readAbstractTaskData(xml);
    DeadlineData     d = readDeadlineData(xml);
    auto attr = xml.attributes();

    Bill* res = new Bill(
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        d.dueDate.toStdString(),
        static_cast<Deadline::Priority>(d.priority),
        d.completed, d.skipped,
        attr.value("amount").toDouble(),
        (attr.value("paid").toString() == "true"),
        attr.value("provider").toString().toStdString(),
        attr.value("IBAN").toString().toStdString(),
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
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        d.dueDate.toStdString(),
        static_cast<Deadline::Priority>(d.priority),
        d.completed, d.skipped,
        attr.value("milestone").toString().toStdString(),
        toStdVec(attr.value("team").toString()),
        attr.value("budget").toDouble(),
        attr.value("status").toString().toStdString(),
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
