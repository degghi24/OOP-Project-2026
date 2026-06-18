#ifndef DETAILVISITOR_H
#define DETAILVISITOR_H

#include "GUI/Pages/DetailPage.h"
#include "Visitor.h"
#include "Model/Headers/Activity.h"
#include "Model/Headers/Reminder.h"
#include "Model/Headers/Work.h"
#include "Model/Headers/Bill.h"
#include "Model/Headers/Project.h"

class DetailVisitor: public Visitor{

private:
    DetailPage *page;

public:

    DetailPage* getDetailPage();
    void visit(Activity* a);
    void visit(Reminder* r);
    void visit(Work* w);
    void visit(Bill* b);
    void visit(Project* p);

};

#endif // DETAILVISITOR_H
