#include "XmlVisitor.h"

#include "src/Model/Headers/AbstractTask.h"
#include "src/Model/Headers/TimedTask.h"
#include "src/Model/Headers/RepeatableTask.h"
#include "src/Model/Headers/Deadline.h"

#include "src/Model/Headers/Activity.h"
#include "src/Model/Headers/Reminder.h"
#include "src/Model/Headers/Work.h"
#include "src/Model/Headers/Bill.h"
#include "src/Model/Headers/Project.h"


XmlVisitor::XmlVisitor() {

    root = doc.createElement("Tasks");
    doc.appendChild(root);
}

QDomDocument XmlVisitor::getDocument() const {
    return doc;
}

void XmlVisitor::insertAbstract(const AbstractTask& A, QDomElement& el) {

    el.setAttribute("id", QString::fromStdString(A.getId()));
    el.setAttribute("title", QString::fromStdString(A.getTitle()));
    el.setAttribute("description", QString::fromStdString(A.getDescription()));
    el.setAttribute("assignee", QString::fromStdString(A.getAssignee()));
    el.setAttribute("creationDate", QString::fromStdString(A.getCreationDate()));
}

void XmlVisitor::insertTimed(const TimedTask& T, QDomElement& el) {

    el.setAttribute("startDate", QString::fromStdString(T.getStartDate()));
    el.setAttribute("endDate", QString::fromStdString(T.getEndDate()));
    el.setAttribute("startTime", QString::fromStdString(T.getStartTime()));
    el.setAttribute("totalDuration", T.getTotalDuration());
}

void XmlVisitor::insertRepeat(const RepeatableTask& R, QDomElement& el) {

    QBitArray week = R.getWeekDays();
    QString days;

    for(int i = 0; i < week.size(); ++i) {
        if(week.testBit(i))
            days += QString::number(i) + ",";
    }

    el.setAttribute("weekDays", days);
    el.setAttribute("intervalDays", R.getIntervalDays());
    el.setAttribute("repeatEndDate", QString::fromStdString(R.getRepeatEndDate()));
    el.setAttribute("active", R.isActive());
}

void XmlVisitor::insertDeadline(const Deadline& D, QDomElement& el) {

    el.setAttribute("dueDate", QString::fromStdString(D.getDueDate()));
    el.setAttribute("priority", D.getPriority());
    el.setAttribute("completed", D.isCompleted());
    el.setAttribute("skipped", D.isSkipped());
}

void XmlVisitor::visit(const Activity& a) {

    QDomElement el = doc.createElement("Activity");

    insertAbstract(a, el);
    insertTimed(a, el);

    root.appendChild(el);
}

void XmlVisitor::visit(const Reminder& r) {

    QDomElement el = doc.createElement("Reminder");

    insertAbstract(r, el);
    insertTimed(r, el);

    root.appendChild(el);
}

void XmlVisitor::visit(const Work& w) {

    QDomElement el = doc.createElement("Work");

    insertAbstract(w, el);
    insertRepeat(w, el);

    root.appendChild(el);
}

void XmlVisitor::visit(const Bill& b) {

    QDomElement el = doc.createElement("Bill");

    insertAbstract(b, el);
    insertDeadline(b, el);

    root.appendChild(el);
}

void XmlVisitor::visit(const Project& p) {

    QDomElement el = doc.createElement("Project");

    insertAbstract(p, el);
    insertDeadline(p, el);

    root.appendChild(el);
}