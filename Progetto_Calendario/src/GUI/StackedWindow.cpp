#include "StackedWindow.h"

#include <QScrollArea>
#include <QPushButton>
#include <QFrame>


StackedWindow::StackedWindow(QWidget *parent): QWidget(parent) {

    stack = new QStackedLayout(this);

    QFrame *first = new QFrame();

    auto *layout = new QHBoxLayout(first);


    layout->addWidget(calendar = new QCalendarWidget()); //index 0

    connect(calendar, &QCalendarWidget::clicked, this, &StackedWindow::selectedFilterDate);

    stack->addWidget(first); // index 0

    detail = new TaskDetailWindow(this);
    edit = new TaskEditWindow(this);
    connect(detail, &TaskDetailWindow::emitClose, this, &StackedWindow::close);
    connect(detail, &TaskDetailWindow::editTask, this, &StackedWindow::showEditWindow);
    connect(detail, &TaskDetailWindow::removeTask, this, &StackedWindow::removeTask);
    connect(edit, &TaskEditWindow::emitClose, this, &StackedWindow::close);
    connect(edit, &TaskEditWindow::updateDetail, this, &StackedWindow::updateDetailPage);
    connect(edit, &TaskEditWindow::updateDetail, this, &StackedWindow::updateTaskBlock);

    stack->addWidget(detail); //index 1
    stack->addWidget(edit); //index 2
}

void StackedWindow::showDetailWindow(AbstractTask* task){
    detail->showTask(task);
    stack->setCurrentIndex(1);
}

void StackedWindow::showEditWindow(AbstractTask* task){
    edit->showTask(task);
    stack->setCurrentIndex(2);
}

void StackedWindow::close(){
    stack->setCurrentIndex(stack->currentIndex()-1);
    if(stack->currentIndex() == 0){
        emit unselectTaskBlock();
    }
}

void StackedWindow::toHomePage(){
    stack->setCurrentIndex(0);
}

void StackedWindow::updateDetailPage(AbstractTask *taskToUpdate){
    detail->showTask(taskToUpdate);

    stack->setCurrentIndex(1);
}


