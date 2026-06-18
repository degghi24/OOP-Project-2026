#include "EditVisitor.h"

EditPage* EditVisitor::getEditPage(){
    return page;
}

void EditVisitor::visit(Activity* a){
    page = new EditPage(a);
}

void EditVisitor::visit(Reminder* r){
    page = new EditPage(r);
}

void EditVisitor::visit(Work* w){
    page = new EditPage(w);
}

void EditVisitor::visit(Bill* b){
    page = new EditPage(b);
}

void EditVisitor::visit(Project* p){
    page = new EditPage(p);
}

