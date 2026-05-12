#include "WorkEdit.h"

WorkEdit::WorkEdit(Work *task, QWidget *parent): RepeatableEditPage(task, parent) {
    setUp();

    if(task){
        subTaskToAdd->setText(task->getSubTasks().join(" "));
        progress->setValue(task->getProgress());
        client->setText(task->getClient().c_str());
        category->setText(task->getCategory().c_str());
        notes->setText(task->getNotes().c_str());
    }
}

WorkEdit::WorkEdit(QWidget *parent): RepeatableEditPage(parent) {
    setUp();
}


void WorkEdit::setUp(){

    subTaskToAdd = new QLineEdit(); //need add button
    progress = new QSpinBox();
    client = new QLineEdit();
    category = new QLineEdit();
    notes = new QLineEdit();

    page->addWidget(new QLabel("Subtasks:"));
    page->addWidget(subTaskToAdd);
    page->addWidget(new QLabel("Progress:"));
    page->addWidget(progress);
    page->addWidget(new QLabel("Client:"));
    page->addWidget(client);
    page->addWidget(new QLabel("Category:"));
    page->addWidget(category);
    page->addWidget(new QLabel("Notes:"));
    page->addWidget(notes);
}
