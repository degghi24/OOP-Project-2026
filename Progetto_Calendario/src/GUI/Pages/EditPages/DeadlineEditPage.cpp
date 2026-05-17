#include "DeadlineEditPage.h"
#include <QButtonGroup>

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

    QHBoxLayout *lineDueDate = new QHBoxLayout();
    lineDueDate->setAlignment(Qt::AlignLeft | Qt::AlignJustify);
    lineDueDate->addWidget(new QLabel("Due Date:"));
    lineDueDate->addWidget(dueDate);
    page->addLayout(lineDueDate);

    QHBoxLayout *linePrio = new QHBoxLayout();
    linePrio->setAlignment(Qt::AlignLeft | Qt::AlignJustify);
    linePrio->addWidget(new QLabel("Priotity:"));
    linePrio->addWidget(prio);
    page->addLayout(linePrio);

    QHBoxLayout *lineCompleted = new QHBoxLayout();
    lineCompleted->setAlignment(Qt::AlignLeft);
    lineCompleted->addWidget(new QLabel("Is Completed:"));
    lineCompleted->addWidget(completed);
    page->addLayout(lineCompleted);

    QHBoxLayout *lineSkipped = new QHBoxLayout();
    lineSkipped->setAlignment(Qt::AlignLeft);
    lineSkipped->addWidget(new QLabel("Is Skipped:"));
    lineSkipped->addWidget(skipped);
    page->addLayout(lineSkipped);

    QButtonGroup *completedOrSkipped = new QButtonGroup(this);
    completedOrSkipped->addButton(completed);
    completedOrSkipped->addButton(skipped);

}

std::string DeadlineEditPage::getDueDate() const{
    return dueDate->date().toString("yyyy-MM-d").toStdString();
}
int DeadlineEditPage::getPriority() const{
    return prio->currentIndex();
}
bool DeadlineEditPage::isCompleted() const{
    return completed->isChecked();
}
bool DeadlineEditPage::isSkipped() const{
    return skipped->isChecked();
}
