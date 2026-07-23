#include "StackedWindow.h"

#include "Pages/DetailPage.h"
#include <QScrollArea>

//#include "../Model/Headers/TaskListManager.h"

#include <QPushButton>
#include <QFrame>

StackedWindow::StackedWindow(QWidget *parent): QWidget(parent) {

    setUpDetailFrame();
    setUpEditFrame();

    stack = new QStackedLayout(this);

    QFrame *first = new QFrame();

    auto *half = new QHBoxLayout(first);


    half->addWidget(calendar = new QCalendarWidget()); //index 0


    stack->addWidget(first);
}

void StackedWindow::setUpDetailFrame(){
    detailFrame = new QFrame();
    QVBoxLayout *detailLayout = new QVBoxLayout(detailFrame);

    QHBoxLayout *lineForCloseButton = new QHBoxLayout();
    QPushButton *closeButton = new QPushButton("Close");
    lineForCloseButton->setAlignment(Qt::AlignRight);
    lineForCloseButton->addWidget(closeButton);

    detailLayout->addLayout(lineForCloseButton);

    detailScrollArea = new QScrollArea();
    detailLayout->addWidget(detailScrollArea);
    detailScrollArea->setWidgetResizable(true);

    QHBoxLayout *lineForEditRemoveButtons = new QHBoxLayout;
    QPushButton *editButton = new QPushButton("Edit");
    QPushButton *RemoveButton = new QPushButton("Remove");
    lineForEditRemoveButtons->setAlignment(Qt::AlignRight);
    lineForEditRemoveButtons->addWidget(editButton);
    lineForEditRemoveButtons->addWidget(RemoveButton);

    detailLayout->addLayout(lineForEditRemoveButtons);
}

void StackedWindow::setUpEditFrame(){

}

void StackedWindow::showDetailWindow(AbstractTask* task){
    task->accept(detailVisitor);
    DetailPage *detailPage = detailVisitor.getDetailPage();

    detailScrollArea->setWidget(detailPage);
    detailScrollArea->setWidgetResizable(true);

    stack->addWidget(detailFrame);
    stack->setCurrentWidget(detailFrame); //index 1
}
