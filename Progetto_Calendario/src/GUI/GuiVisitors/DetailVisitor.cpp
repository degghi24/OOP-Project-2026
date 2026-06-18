#include "DetailVisitor.h"

DetailPage* DetailVisitor::getDetailPage(){
    return page;
}

void DetailVisitor::visit(Activity* a){
    page = new DetailPage(a);
}

void DetailVisitor::visit(Reminder* r){
    page = new DetailPage(r);
}

void DetailVisitor::visit(Work* w){
    page = new DetailPage(w);
}

void DetailVisitor::visit(Bill* b){
    page = new DetailPage(b);
}

void DetailVisitor::visit(Project* p){
    page = new DetailPage(p);
}
