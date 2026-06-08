#include "StackedWindow.h"
#include "../Model/Headers/TaskListManager.h"

//#include "../Model/Headers/TaskListManager.h"

#include <QPushButton>
#include <QFrame>

StackedWindow::StackedWindow(QWidget *parent): QWidget(parent) {

    stack = new QStackedLayout(this);

    QFrame *first = new QFrame();

    auto *half = new QHBoxLayout(first);


    half->addWidget(calendar = new QCalendarWidget());


    stack->addWidget(first);
}
