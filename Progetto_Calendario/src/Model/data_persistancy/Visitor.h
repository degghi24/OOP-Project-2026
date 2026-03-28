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

    virtual void visit(Activity& a) = 0;
    virtual void visit(Reminder& r) = 0;
    virtual void visit(Work& w)     = 0;
    virtual void visit(Bill& b)     = 0;
    virtual void visit(Project& p)  = 0;
};

#endif // VISITOR_H