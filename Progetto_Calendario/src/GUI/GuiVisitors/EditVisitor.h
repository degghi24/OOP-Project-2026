#ifndef EDITVISITOR_H
#define EDITVISITOR_H

#include "GUI/Pages/EditPage.h"
#include "Visitor.h"
#include "Model/Headers/Activity.h"
#include "Model/Headers/Reminder.h"
#include "Model/Headers/Work.h"
#include "Model/Headers/Bill.h"
#include "Model/Headers/Project.h"

class EditVisitor: public Visitor{

private:
    EditPage *page;

public:

    EditPage* getEditPage();
    void visit(Activity* a);
    void visit(Reminder* r);
    void visit(Work* w);
    void visit(Bill* b);
    void visit(Project* p);
};

#endif // EDITVISITOR_H
