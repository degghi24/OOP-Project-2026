#ifndef BLOCKVISITOR_H
#define BLOCKVISITOR_H

#include "Visitor.h"
#include "Model/Headers/Activity.h"
#include "Model/Headers/Reminder.h"
#include "Model/Headers/Work.h"
#include "Model/Headers/Bill.h"
#include "Model/Headers/Project.h"

#include "../TaskBlock.h"

class BlockVisitor: public Visitor{

private:
    TaskBlock* taskBlock = nullptr;

public:

    TaskBlock* getTaskBlock();
    void visit(Activity* a);
    void visit(Reminder* r);
    void visit(Work* w);
    void visit(Bill* b);
    void visit(Project* p);

};

#endif // BLOCKVISITOR_H
