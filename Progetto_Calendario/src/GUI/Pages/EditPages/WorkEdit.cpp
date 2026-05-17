#include "WorkEdit.h"
#include "LabelBlock.h"

#include <QPushButton>
#include <QScrollArea>

WorkEdit::WorkEdit(Work *task, QWidget *parent): RepeatableEditPage(task, parent) {
    setUp();

    if(task){
        for(const auto &it : task->getSubTasks()){
            subTaskToAdd->setText(it);
            addSubTask();
        }
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

    subTasksScrollAreaLayout = new QVBoxLayout();

    QHBoxLayout *lineSubTask = new QHBoxLayout();
    lineSubTask->setAlignment(Qt::AlignLeft);
    lineSubTask->addWidget(new QLabel("Subtask:"));
    lineSubTask->addWidget(subTaskToAdd);
    QPushButton *addSubTaskButton = new QPushButton();
    addSubTaskButton->setText("Add");
    addSubTaskButton->setFixedSize(40,20);
    connect(addSubTaskButton, &QPushButton::clicked, this, &WorkEdit::addSubTask);
    lineSubTask->addWidget(addSubTaskButton);
    page->addLayout(lineSubTask);

    //scroll area for Team list
    QScrollArea *subTasksScrollArea = new QScrollArea();
    subTasksScrollArea->setWidgetResizable(true);
    page->addWidget(subTasksScrollArea);
    QWidget *teamList = new QWidget();
    subTasksScrollArea->setWidget(teamList);
    subTasksScrollAreaLayout = new QVBoxLayout(teamList);
    subTasksScrollAreaLayout->setAlignment(Qt::AlignTop);
    subTasksScrollAreaLayout->setContentsMargins(1,1,1,1);
    subTasksScrollAreaLayout->setSpacing(1);

    page->addWidget(new QLabel("Progress:"));
    page->addWidget(progress);
    page->addWidget(new QLabel("Client:"));
    page->addWidget(client);
    page->addWidget(new QLabel("Category:"));
    page->addWidget(category);
    page->addWidget(new QLabel("Notes:"));
    page->addWidget(notes);
}


void WorkEdit::addSubTask(){
    subTasksScrollAreaLayout->addWidget(new LabelBlock(subTaskToAdd->text()));
    subTaskToAdd->clear();
}



QStringList WorkEdit::getSubTasks(){
    QStringList subTaskList;
    for(int i = 0; i < subTasksScrollAreaLayout->count(); ++i){
        subTaskList.append((static_cast<LabelBlock*>(subTasksScrollAreaLayout->itemAt(i)->widget()))->getText());
    }
    return subTaskList;
}

int WorkEdit::getProgress() const{
    return progress->value();
}
std::string WorkEdit::getClient() const{
    return client->text().toStdString();
}
std::string WorkEdit::getCategory() const{
    return category->text().toStdString();
}
std::string WorkEdit::getNotes() const{
    return notes->text().toStdString();
}

void WorkEdit::createTask(){
    Work *newWork = new Work(getTitle(),getDescription(),getAssignee(), QDate::currentDate().toString("yyyy-MM-d").toStdString(),
                             getWorkDays(),getIntervalDays(),getEndDate(),isActive(),
                             getSubTasks(), getProgress(),getClient(),getCategory(),getNotes());
    emit returnTask(newWork);
}
