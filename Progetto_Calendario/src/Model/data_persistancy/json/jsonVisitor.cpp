#include "jsonVisitor.h"
#include "../../Headers/Activity.h"
#include "../../Headers/Reminder.h"
#include "../../Headers/Work.h"
#include "../../Headers/Bill.h"
#include "../../Headers/Project.h"

QJsonObject jsonVisitor::getObject() const {
    return object;
}

void jsonVisitor::insertAbstract(const AbstractTask& A, QJsonObject& obj){
    obj.insert("id",  QJsonValue::fromVariant(A.getId().c_str()));
    obj.insert("title", QJsonValue::fromVariant(A.getTitle().c_str()));
    obj.insert("description", QJsonValue::fromVariant(A.getDescription().c_str()));
    obj.insert("assignee", QJsonValue::fromVariant(A.getAssignee().c_str()));
    obj.insert("creationDate", QJsonValue::fromVariant(A.getCreationDate().c_str()));
}

void jsonVisitor::insertTimed(const TimedTask& T, QJsonObject& obj){
    insertAbstract(T, obj);
    obj.insert("startDate", QJsonValue::fromVariant(T.getStartDate().c_str()));
    obj.insert("endDate", QJsonValue::fromVariant(T.getEndDate().c_str()));
    obj.insert("startTime", QJsonValue::fromVariant(T.getStartTime().c_str()));
    obj.insert("totalDuration", QJsonValue::fromVariant(T.getTotalDuration()));
}

void jsonVisitor::insertRepeat(const RepeatableTask& R, QJsonObject& obj){
    insertAbstract(R, obj);
    QJsonArray workDays;
    for(int i = 0; i < R.getWeekDays().size(); ++i){
        workDays.append(bool(R.getWeekDays()[i]));
    }
    obj.insert("weekDays", workDays);
    obj.insert("intervalDays", QJsonValue::fromVariant(R.getIntervalDays()));
    obj.insert("repeatEndDate", QJsonValue::fromVariant(R.getRepeatEndDate().c_str()));
    obj.insert("active", QJsonValue::fromVariant(R.isActive()));
}

void jsonVisitor::insertDeadline(const Deadline& D, QJsonObject& obj){
    insertAbstract(D, obj);
    obj.insert("dueDate", QJsonValue::fromVariant(D.getDueDate().c_str()));
    obj.insert("priority", QJsonValue::fromVariant(D.getPriority()));
    obj.insert("completed", QJsonValue::fromVariant(D.isCompleted()));
    obj.insert("skipped", QJsonValue::fromVariant(D.isSkipped()));
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void jsonVisitor::visit(const Activity &a){
    QJsonObject activityObj;
    activityObj.insert("type", QJsonValue::fromVariant("Activity"));
    insertTimed(a, activityObj);
    activityObj.insert("location", QJsonValue::fromVariant(a.getLocation().c_str()));
    activityObj.insert("participantCount", QJsonValue::fromVariant(a.getParticipantCount()));
    activityObj.insert("eventType", QJsonValue::fromVariant(a.getEventType().c_str()));
    activityObj.insert("online", QJsonValue::fromVariant(a.isOnline()));
    activityObj.insert("meetingLink", QJsonValue::fromVariant(a.getMeetingLink().c_str()));
    object = activityObj;
}


void jsonVisitor::visit(const Reminder &r){
    QJsonObject reminderObj;
    reminderObj.insert("type", QJsonValue::fromVariant("Reminder"));
    insertTimed(r, reminderObj);
    reminderObj.insert("notifyTime", QJsonValue::fromVariant(r.getNotifyTime().c_str()));
    reminderObj.insert("alertMessage", QJsonValue::fromVariant(r.getAlertMessage().c_str()));
    reminderObj.insert("snoozed", QJsonValue::fromVariant(r.isSnoozed()));
    reminderObj.insert("snoozedMinute", QJsonValue::fromVariant(r.getSnoozeMinutes()));
    object = reminderObj;
}

void jsonVisitor::visit(const Work& w){
    QJsonObject workObj;
    workObj.insert("type", QJsonValue::fromVariant("Work"));
    insertRepeat(w, workObj);
    workObj.insert("subTasks", QJsonValue::fromVariant(w.getSubTasks()));
    workObj.insert("progress", QJsonValue::fromVariant(w.getProgress()));
    workObj.insert("client", QJsonValue::fromVariant(w.getClient().c_str()));
    workObj.insert("category", QJsonValue::fromVariant(w.getCategory().c_str()));
    workObj.insert("notes", QJsonValue::fromVariant(w.getNotes().c_str()));
    object = workObj;
}


void jsonVisitor::visit(const Bill &b){
    QJsonObject billObj;
    billObj.insert("type", QJsonValue::fromVariant("Bill"));
    insertDeadline(b, billObj);
    billObj.insert("amount", QJsonValue::fromVariant(b.getAmount()));
    billObj.insert("paid", QJsonValue::fromVariant(b.isPaid()));
    billObj.insert("provider", QJsonValue::fromVariant(b.getProvider().c_str()));
    billObj.insert("IBAN", QJsonValue::fromVariant(b.getIBAN().c_str()));
    billObj.insert("recurring", QJsonValue::fromVariant(b.isRecurring()));
    object = billObj;
}


void jsonVisitor::visit(const Project &p){
    QJsonObject projectObj;
    projectObj.insert("type", QJsonValue::fromVariant("Project"));
    insertDeadline(p, projectObj);
    projectObj.insert("milestone", QJsonValue::fromVariant(p.getMilestone().c_str()));
    projectObj.insert("team", QJsonValue::fromVariant(p.getTeam()));
    projectObj.insert("budget", QJsonValue::fromVariant(p.getBudget()));
    projectObj.insert("status", QJsonValue::fromVariant(p.getStatus().c_str()));
    projectObj.insert("tag", QJsonValue::fromVariant(p.getTags()));
    object = projectObj;
}
