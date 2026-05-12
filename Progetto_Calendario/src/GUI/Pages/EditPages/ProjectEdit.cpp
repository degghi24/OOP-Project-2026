#include "ProjectEdit.h"

ProjectEdit::ProjectEdit(Project *task, QWidget *parent): DeadlineEditPage(task,parent) {
    setUp();

    if(task){
        milestone->setText(task->getMilestone().c_str());
        team->setText(task->getTeam().join(" "));
        budget->setValue(task->getBudget());
        status->setText(task->getStatus().c_str());
        tags->setText(task->getTags().join(" "));
    }
}

ProjectEdit::ProjectEdit(QWidget *parent): DeadlineEditPage(parent) {
    setUp();
}

void ProjectEdit::setUp(){
    QLineEdit *milestone = new QLineEdit();
    QLineEdit *team = new QLineEdit(); // multi insert
    QSpinBox *budget = new QSpinBox();
    QLineEdit *status = new QLineEdit();
    QLineEdit *tags = new QLineEdit(); // multi insert

    page->addWidget(new QLabel("Milestone:"));
    page->addWidget(milestone);
    page->addWidget(new QLabel("Team:"));
    page->addWidget(team);
    page->addWidget(new QLabel("Budget:"));
    page->addWidget(budget);
    page->addWidget(new QLabel("Status:"));
    page->addWidget(status);
    page->addWidget(new QLabel("Tags:"));
    page->addWidget(tags);
}
