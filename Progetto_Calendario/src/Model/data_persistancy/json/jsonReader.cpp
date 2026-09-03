#include "jsonReader.h"
#include <QDebug>

JsonReader::JsonReader() {}

JsonReader::AbstractTaskData JsonReader::readAbstractTaskData(const QJsonObject& obj) {
    AbstractTaskData d;
    d.id           = obj["id"].toString();
    d.title        = obj["title"].toString();
    d.description  = obj["description"].toString();
    d.assignee     = obj["assignee"].toString();
    d.creationDate = QDate::fromString(obj["startDate"].toString(),"yyyy-MM-d");
    return d;
}

JsonReader::TimedTaskData JsonReader::readTimedTaskData(const QJsonObject& obj) {
    TimedTaskData d;
    d.startDate     = QDate::fromString(obj["startDate"].toString(),"yyyy-MM-d");
    d.endDate       = QDate::fromString(obj["endDate"].toString(),"yyyy-MM-d");
    d.startTime     = obj["startTime"].toString();
    d.totalDuration = obj["totalDuration"].toInt();
    return d;
}

JsonReader::RepeatableTaskData JsonReader::readRepeatableTaskData(const QJsonObject& obj) {
    RepeatableTaskData d;
    d.repeatEndDate = QDate::fromString(obj["repeatEndDate"].toString(),"yyyy-MM-d");
    QJsonArray a = obj["weekDays"].toArray();
    d.weekDays.resize(7);
    for (int i = 0; i < a.size(); ++i){
        d.weekDays.setBit(i, a[i].toBool());
    }
    return d;
}

JsonReader::DeadlineData JsonReader::readDeadlineData(const QJsonObject& obj) {
    DeadlineData d;
    d.dueDate   = QDate::fromString(obj["dueDate"].toString(),"yyyy-MM-d");
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
        a.title,
        a.description, a.assignee,
        a.creationDate,
        t.startDate, t.endDate,
        t.startTime, t.totalDuration,
        obj["location"].toString(),
        obj["participantCount"].toInt(),
        obj["eventType"].toString(),
        obj["online"].toBool(),
        obj["meetingLink"].toString()
        );
}

Reminder* JsonReader::readReminder(const QJsonObject& obj) {
    AbstractTaskData a = readAbstractTaskData(obj);
    TimedTaskData    t = readTimedTaskData(obj);
    return new Reminder(
        a.title,
        a.description, a.assignee,
        a.creationDate,
        t.startDate, t.endDate,
        t.startTime, t.totalDuration,
        obj["notifyTime"].toString(),
        obj["alertMessage"].toString(),
        obj["snoozed"].toBool(),
        obj["snoozeMinutes"].toInt()
        );
}

Work* JsonReader::readWork(const QJsonObject& obj) {
    AbstractTaskData   a = readAbstractTaskData(obj);
    RepeatableTaskData r = readRepeatableTaskData(obj);

    QStringList subTasks;
    for (const QJsonValue& v : obj["subTasks"].toArray())
        subTasks.push_back(v.toString());

    return new Work(
        a.title,
        a.description, a.assignee,
        a.creationDate,
        r.weekDays,
        r.repeatEndDate,
        subTasks, obj["progress"].toInt(),
        obj["client"].toString(),
        obj["category"].toString(),
        obj["notes"].toString()
        );
}

Bill* JsonReader::readBill(const QJsonObject& obj) {
    AbstractTaskData a = readAbstractTaskData(obj);
    DeadlineData     d = readDeadlineData(obj);
    return new Bill(
        a.title,
        a.description, a.assignee,
        a.creationDate,
        d.dueDate,
        static_cast<Deadline::Priority>(d.priority),
        d.completed, d.skipped,
        obj["amount"].toDouble(),
        obj["paid"].toBool(),
        obj["provider"].toString(),
        obj["IBAN"].toString(),
        obj["recurring"].toBool()
        );
}

Project* JsonReader::readProject(const QJsonObject& obj) {
    AbstractTaskData a = readAbstractTaskData(obj);
    DeadlineData     d = readDeadlineData(obj);

    QStringList team, tags;
    for (const QJsonValue& v : obj["team"].toArray())
        team.push_back(v.toString());
    for (const QJsonValue& v : obj["tags"].toArray())
        tags.push_back(v.toString());

    return new Project(
        a.title,
        a.description, a.assignee,
        a.creationDate,
        d.dueDate,
        static_cast<Deadline::Priority>(d.priority),
        d.completed, d.skipped,
        obj["milestone"].toString(),
        team, obj["budget"].toDouble(),
        obj["status"].toString(),
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
        if      (type == "Activity") t = readActivity(obj);
        else if (type == "Reminder") t = readReminder(obj);
        else if (type == "Work")     t = readWork(obj);
        else if (type == "Bill")     t = readBill(obj);
        else if (type == "Project")  t = readProject(obj);

        if (t != nullptr)
            tasks.append(t);
    }

    return tasks;
}
