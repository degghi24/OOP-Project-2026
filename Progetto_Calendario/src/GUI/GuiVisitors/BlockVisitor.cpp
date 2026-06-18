#include "BlockVisitor.h"

TaskBlock* BlockVisitor::getTaskBlock(){
    return taskBlock;
}

void BlockVisitor::visit(Activity* a){
    taskBlock = new TaskBlock(a);
}

void BlockVisitor::visit(Reminder* r){
    taskBlock = new TaskBlock(r);
}

void BlockVisitor::visit(Work* w){
    taskBlock = new TaskBlock(w);
}

void BlockVisitor::visit(Bill* b){
    taskBlock = new TaskBlock(b);
}

void BlockVisitor::visit(Project* p){
    taskBlock = new TaskBlock(p);
}
