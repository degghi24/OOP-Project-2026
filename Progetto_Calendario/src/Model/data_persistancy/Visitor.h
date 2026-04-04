#ifndef VISITOR_H
#define VISITOR_H

class Activity;
class Reminder;
class Work;
class Bill;
class Project;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(const Activity& a) = 0;
    virtual void visit(const Reminder& r) = 0;
    virtual void visit(const Work& w)     = 0;
    virtual void visit(const Bill& b)     = 0;
    virtual void visit(const Project& p)  = 0;
};

#endif // VISITOR_H
