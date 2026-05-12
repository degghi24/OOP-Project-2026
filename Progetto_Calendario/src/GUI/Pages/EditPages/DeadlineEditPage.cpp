#include "DeadlineEditPage.h"

DeadlineEditPage::DeadlineEditPage(Deadline *task, QWidget *parent): AbstractEditPage(task, parent) {
    setUp();

    if(task){
        QString dDate = task->getDueDate().c_str();
        dueDate->setDate(QDate(dDate.section("-",0,0).toInt(), dDate.section("-",1,1).toInt(),dDate.section("-",2,2).toInt()));
        prio->setCurrentIndex(task->getPriority());
        completed->setChecked(task->isCompleted());
        skipped->setChecked(task->isSkipped());
    }
}

DeadlineEditPage::DeadlineEditPage(QWidget *parent): AbstractEditPage(parent) {
    setUp();
}

void DeadlineEditPage::setUp(){
    dueDate = new QDateEdit();
    prio = new QComboBox();
    prio->addItem("Low");
    prio->addItem("Medium");
    prio->addItem("High");
    completed = new QRadioButton();
    skipped = new QRadioButton();

    page->addWidget(new QLabel("Due Date:"));
    page->addWidget(dueDate);
    page->addWidget(new QLabel("Priotity:"));
    page->addWidget(prio);
    page->addWidget(new QLabel("Is Completed:"));
    page->addWidget(completed);
    page->addWidget(new QLabel("Is Skipped:"));
    page->addWidget(skipped);
}
