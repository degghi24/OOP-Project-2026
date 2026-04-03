#include "JsonReader.h"
#include <QDebug>

JsonReader::JsonReader() {}

JsonReader::AbstractTaskData JsonReader::readAbstractTaskData(const QJsonObject& obj) {
    AbstractTaskData d;
    d.id           = obj["id"].toString();
    d.title        = obj["title"].toString();
    d.description  = obj["description"].toString();
    d.assignee     = obj["assignee"].toString();
    d.creationDate = obj["creationDate"].toString();
    return d;
}

JsonReader::TimedTaskData JsonReader::readTimedTaskData(const QJsonObject& obj) {
    TimedTaskData d;
    d.startDate     = obj["startDate"].toString();
    d.endDate       = obj["endDate"].toString();
    d.startTime     = obj["startTime"].toString();
    d.totalDuration = obj["totalDuration"].toInt();
    return d;
}

JsonReader::RepeatableTaskData JsonReader::readRepeatableTaskData(const QJsonObject& obj) {
    RepeatableTaskData d;
    d.intervalDays  = obj["intervalDays"].toInt();
    d.repeatEndDate = obj["repeatEndDate"].toString();
    d.active        = obj["active"].toBool();
    for (const QJsonValue& v : obj["weekDays"].toArray())
        d.weekDays.append(v.toInt());
    return d;
}

JsonReader::DeadlineData JsonReader::readDeadlineData(const QJsonObject& obj) {
    DeadlineData d;
    d.dueDate   = obj["dueDate"].toString();
    d.priority  = obj["priority"].toInt();
    d.completed = obj["completed"].toBool();
    d.skipped   = obj["skipped"].toBool();
    return d;
}

// ── creazione oggetti concreti ───────────────────────────────────────────────

Activity* JsonReader::readActivity(const QJsonObject& obj) {
    AbstractTaskData a = readAbstractTaskData(obj);
    TimedTaskData    t = readTimedTaskData(obj);
    return new Activity(
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        t.startDate.toStdString(), t.endDate.toStdString(),
        t.startTime.toStdString(), t.totalDuration,
        obj["location"].toString().toStdString(),
        obj["participantCount"].toInt(),
        obj["eventType"].toString().toStdString(),
        obj["online"].toBool(),
        obj["meetingLink"].toString().toStdString()
        );
}

Reminder* JsonReader::readReminder(const QJsonObject& obj) {
    AbstractTaskData a = readAbstractTaskData(obj);
    TimedTaskData    t = readTimedTaskData(obj);
    return new Reminder(
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        t.startDate.toStdString(), t.endDate.toStdString(),
        t.startTime.toStdString(), t.totalDuration,
        obj["notifyTime"].toString().toStdString(),
        obj["alertMessage"].toString().toStdString(),
        obj["snoozed"].toBool(),
        obj["snoozeMinutes"].toInt()
        );
}

Work* JsonReader::readWork(const QJsonObject& obj) {
    AbstractTaskData   a = readAbstractTaskData(obj);
    RepeatableTaskData r = readRepeatableTaskData(obj);

    std::vector<int> weekDays(r.weekDays.begin(), r.weekDays.end());
    std::vector<std::string> subTasks;
    for (const QJsonValue& v : obj["subTasks"].toArray())
        subTasks.push_back(v.toString().toStdString());

    return new Work(
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        weekDays, r.intervalDays,
        r.repeatEndDate.toStdString(), r.active,
        subTasks, obj["progress"].toInt(),
        obj["client"].toString().toStdString(),
        obj["category"].toString().toStdString(),
        obj["notes"].toString().toStdString()
        );
}

Bill* JsonReader::readBill(const QJsonObject& obj) {
    AbstractTaskData a = readAbstractTaskData(obj);
    DeadlineData     d = readDeadlineData(obj);
    return new Bill(
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        d.dueDate.toStdString(),
        static_cast<Deadline::Priority>(d.priority),
        d.completed, d.skipped,
        obj["amount"].toDouble(),
        obj["paid"].toBool(),
        obj["provider"].toString().toStdString(),
        obj["IBAN"].toString().toStdString(),
        obj["recurring"].toBool()
        );
}

Project* JsonReader::readProject(const QJsonObject& obj) {
    AbstractTaskData a = readAbstractTaskData(obj);
    DeadlineData     d = readDeadlineData(obj);

    std::vector<std::string> team, tags;
    for (const QJsonValue& v : obj["team"].toArray())
        team.push_back(v.toString().toStdString());
    for (const QJsonValue& v : obj["tags"].toArray())
        tags.push_back(v.toString().toStdString());

    return new Project(
        a.id.toStdString(), a.title.toStdString(),
        a.description.toStdString(), a.assignee.toStdString(),
        a.creationDate.toStdString(),
        d.dueDate.toStdString(),
        static_cast<Deadline::Priority>(d.priority),
        d.completed, d.skipped,
        obj["milestone"].toString().toStdString(),
        team, obj["budget"].toDouble(),
        obj["status"].toString().toStdString(),
        tags
        );
}

QList<AbstractTask*> JsonReader::readAll(const QString& filename) {
    QList<AbstractTask*> tasks;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Errore apertura file:" << file.errorString();
        return tasks;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (doc.isNull() || !doc.isArray()) {
        qDebug() << "File JSON non valido";
        return tasks;
    }

    for (const QJsonValue& val : doc.array()) {
        if (!val.isObject()) continue;
        QJsonObject obj  = val.toObject();
        QString     type = obj["type"].toString();

        AbstractTask* t = nullptr;
        if      (type == "activity") t = readActivity(obj);
        else if (type == "reminder") t = readReminder(obj);
        else if (type == "work")     t = readWork(obj);
        else if (type == "bill")     t = readBill(obj);
        else if (type == "project")  t = readProject(obj);

        if (t != nullptr)
            tasks.append(t);
    }

    return tasks;
}