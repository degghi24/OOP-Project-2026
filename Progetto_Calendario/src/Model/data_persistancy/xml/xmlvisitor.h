#ifndef XMLVISITOR_H
#define XMLVISITOR_H

#include <Qtxml\QDomDocument>
#include <Qtxml\QDomElement>

#include "../Visitor.h"

class AbstractTask;
class TimedTask;
class RepeatableTask;
class Deadline;

class Activity;
class Reminder;
class Work;
class Bill;
class Project;

class XmlVisitor : public Visitor {

private:
    QDomDocument doc;
    QDomElement root;

    void insertAbstract(const AbstractTask& A, QDomElement& el);
    void insertTimed(const TimedTask& T, QDomElement& el);
    void insertRepeat(const RepeatableTask& R, QDomElement& el);
    void insertDeadline(const Deadline& D, QDomElement& el);

public:
    XmlVisitor();

    QDomDocument getDocument() const;

    void visit(const Activity& a) override;
    void visit(const Reminder& r) override;
    void visit(const Work& w) override;
    void visit(const Bill& b) override;
    void visit(const Project& p) override;
};

#endif