#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include "../Visitor.h"

class AbstractTask;
class TimedTask;
class RepeatableTask;
class Deadline;

class jsonVisitor: public Visitor{

private:

    QJsonObject object;

    void insertAbstract(const AbstractTask& A, QJsonObject& obj);
    void insertTimed(const TimedTask& T, QJsonObject& obj);
    void insertRepeat(const RepeatableTask& R, QJsonObject& obj);
    void insertDeadline(const Deadline& D, QJsonObject& obj);

public:

    QJsonObject getObject() const;
    void visit(const Activity& a);
    void visit(const Reminder& r);
    void visit(const Work& w);
    void visit(const Bill& b);
    void visit(const Project& p);
};

#endif // JSONVISITOR_H
