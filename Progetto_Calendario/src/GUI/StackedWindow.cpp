#include "StackedWindow.h"
#include "AddTask/TypeSelectionPopup.h"
#include "AddTask/TaskCreationWindow.h"

//#include "../Model/Headers/TaskListManager.h"

#include <QPushButton>
#include <QFrame>

StackedWindow::StackedWindow(QWidget *parent): QWidget(parent) {

    stack = new QStackedLayout(this);

    QFrame *first = new QFrame();

    auto *half = new QHBoxLayout(first);

    QPushButton *add = new QPushButton("Add");
    connect(add, &QPushButton::clicked, this, &StackedWindow::showTypeSelect);


    half->addWidget(calendar = new QCalendarWidget());
    half->addWidget(add);


    stack->addWidget(first);
}

void StackedWindow::showTypeSelect(){
    TypeSelectionPopup *typePopup = new TypeSelectionPopup(this);
    typePopup->setAttribute(Qt::WA_DeleteOnClose, true);
    connect(typePopup, &TypeSelectionPopup::sendType, this, &StackedWindow::showTaskCreation); //showTaskCreation(QString type)
    if (typePopup->exec() == QDialog::Accepted){
        qDebug()<<"Accepted";
        //connect(typePopup, &TypeSelectionPopup::createTaskSignal, TaskCreationWindowObject, &TaskCreationWindow::createTask);
    }
}

void StackedWindow::showTaskCreation(QString type){
    TaskCreationWindow *creationWindow = new TaskCreationWindow(type, this);
    creationWindow->exec();
}

//TaskDetailWindow *detail = nullptr
//TaskEditWindow *edit = nullptr
