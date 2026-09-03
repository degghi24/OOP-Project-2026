#include "xmlVisitor.h"

#include "../../Headers/AbstractTask.h"
#include "../../Headers/TimedTask.h"
#include "../../Headers/RepeatableTask.h"
#include "../../Headers/Deadline.h"

#include "../../Headers/Activity.h"
#include "../../Headers/Reminder.h"
#include "../../Headers/Work.h"
#include "../../Headers/Bill.h"
#include "../../Headers/Project.h"


XmlVisitor::XmlVisitor() {

    root = doc.createElement("Tasks");
    doc.appendChild(root);
}

QDomDocument XmlVisitor::getDocument() const {
    return doc;
}

void XmlVisitor::insertAbstract(const AbstractTask& A, QDomElement& el) {

    el.setAttribute("id", A.getId());
    el.setAttribute("title", A.getTitle());
    el.setAttribute("description", A.getDescription());
    el.setAttribute("assignee", A.getAssignee());
    el.setAttribute("creationDate", A.getCreationDate().toString("yyyy-MM-d"));
}

void XmlVisitor::insertTimed(const TimedTask& T, QDomElement& el) {

    el.setAttribute("startDate", T.getStartDate().toString("yyyy-MM-d"));
    el.setAttribute("endDate", T.getEndDate().toString("yyyy-MM-d"));
    el.setAttribute("startTime", (T.getStartTime()));
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
    el.setAttribute("repeatEndDate", R.getRepeatEndDate().toString("yyyy-MM-d"));
}

void XmlVisitor::insertDeadline(const Deadline& D, QDomElement& el) {

    el.setAttribute("dueDate", D.getDueDate().toString("yyyy-MM-d"));
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
