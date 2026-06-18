#include "StackedWindow.h"

#include "Pages/DetailPage.h"

//#include "../Model/Headers/TaskListManager.h"

#include <QPushButton>
#include <QFrame>

StackedWindow::StackedWindow(QWidget *parent): QWidget(parent) {

    stack = new QStackedLayout(this);

    QFrame *first = new QFrame();

    auto *half = new QHBoxLayout(first);


    half->addWidget(calendar = new QCalendarWidget()); //index 0


    stack->addWidget(first);
}

void StackedWindow::showDetailWindow(AbstractTask* task){
    task->accept(detailVisitor);
    DetailPage *currentPage = detailVisitor.getDetailPage();
    stack->addWidget(currentPage);
    stack->setCurrentWidget(currentPage); //index 1
}
