#include "TaskBlock.h"

#include <QGridLayout>
#include <QSplitter>
#include <QEvent>
#include <QPropertyAnimation>

QStringList types{"Activity", "Work", "Bill", "Project", "Reminder"};

//TaskBlock::TaskBlock(QWidget *parent): QWidget(parent) {}

TaskBlock::TaskBlock(Activity *task):
    title(new QLabel(task->getTitle().c_str())),
    startDate(new QDate(task->getStartDate())),
    endDate(new QDate(task->getEndDate())),
    type(new QLabel("Activity"))
{
    taskStored = task;
    setUp();

    QGridLayout *innerBox = new QGridLayout(block);
    innerBox->setAlignment(Qt::AlignHCenter);

    QLabel *startDateLabel = new QLabel(endDate->toString("yyyy-MM-d"));
    startDateLabel->setAlignment(Qt::AlignCenter);

    QLabel *endDateLabel = new QLabel(endDate->toString("yyyy-MM-d"));
    endDateLabel->setAlignment(Qt::AlignCenter);

    innerBox->addWidget(title, 0, 0, 1, 2);

    QLabel *data_i = new QLabel("Start Date: ");
    innerBox->addWidget(data_i,1,0);
    innerBox->addWidget(startDateLabel,1,1);

    QLabel *data_f = new QLabel("End Date: ");
    innerBox->addWidget(data_f,2,0);
    innerBox->addWidget(endDateLabel,2,1);

    QLabel *tipo = new QLabel("Type: ");
    innerBox->addWidget(tipo,3,0);
    innerBox->addWidget(type,3,1);

    outerBox->addWidget(block);

    outerBox->setContentsMargins(1,1,1,1);
    outerBox->setSpacing(0);
}

TaskBlock::TaskBlock(Reminder *task):
    title(new QLabel(task->getTitle().c_str())),
    startDate(new QDate(task->getStartDate())),
    endDate(new QDate(task->getEndDate())),
    type(new QLabel("Reminder"))
{
    taskStored = task;
    setUp();

    QGridLayout *innerBox = new QGridLayout(block);
    innerBox->setAlignment(Qt::AlignHCenter);

    QLabel *startDateLabel = new QLabel(endDate->toString("yyyy-MM-d"));
    startDateLabel->setAlignment(Qt::AlignCenter);

    QLabel *endDateLabel = new QLabel(endDate->toString("yyyy-MM-d"));
    endDateLabel->setAlignment(Qt::AlignCenter);

    innerBox->addWidget(title, 0, 0, 1, 2);

    QLabel *data_i = new QLabel("Start Date: ");
    innerBox->addWidget(data_i,1,0);
    innerBox->addWidget(startDateLabel,1,1);

    QLabel *data_f = new QLabel("End Date: ");
    innerBox->addWidget(data_f,2,0);
    innerBox->addWidget(endDateLabel,2,1);

    QLabel *tipo = new QLabel("Type: ");
    innerBox->addWidget(tipo,3,0);
    innerBox->addWidget(type,3,1);

    outerBox->addWidget(block);

    outerBox->setContentsMargins(1,1,1,1);
    outerBox->setSpacing(0);
}

TaskBlock::TaskBlock(Work *task):
    title(new QLabel(task->getTitle().c_str())),
    endDate(new QDate(task->getRepeatEndDate())),
    type(new QLabel("Work"))
{
    taskStored = task;
    setUp();

    QGridLayout *innerBox = new QGridLayout(block);
    innerBox->setAlignment(Qt::AlignHCenter);

    QLabel *endDateLabel = new QLabel(endDate->toString("yyyy-MM-d"));
    endDateLabel->setAlignment(Qt::AlignCenter);

    innerBox->addWidget(title, 0, 0, 1, 2);

    QLabel *data_f = new QLabel("End Date: ");
    innerBox->addWidget(data_f,1,0);
    innerBox->addWidget(endDateLabel,1,1);

    QLabel *tipo = new QLabel("Type: ");
    innerBox->addWidget(tipo,2,0);
    innerBox->addWidget(type,2,1,1,2);

    outerBox->addWidget(block);

    outerBox->setContentsMargins(1,1,1,1);
    outerBox->setSpacing(0);
}

TaskBlock::TaskBlock(Bill *task):
    title(new QLabel(task->getTitle().c_str())),
    endDate(new QDate(task->getDueDate())),
    type(new QLabel("Bill"))
{
    taskStored = task;
    setUp();

    QGridLayout *innerBox = new QGridLayout(block);
    innerBox->setAlignment(Qt::AlignHCenter);

    QLabel *endDateLabel = new QLabel(endDate->toString("yyyy-MM-d"));
    endDateLabel->setAlignment(Qt::AlignCenter);

    innerBox->addWidget(title, 0, 0, 1, 2);

    QLabel *data_f = new QLabel("Due Date: ");
    innerBox->addWidget(data_f,1,0);
    innerBox->addWidget(endDateLabel,1,1);

    QLabel *tipo = new QLabel("Type: ");
    innerBox->addWidget(tipo,2,0);
    innerBox->addWidget(type,2,1,1,2);

    outerBox->addWidget(block);

    outerBox->setContentsMargins(1,1,1,1);
    outerBox->setSpacing(0);

}

TaskBlock::TaskBlock(Project *task):
    title(new QLabel(task->getTitle().c_str())),
    endDate(new QDate(task->getDueDate())),
    type(new QLabel("Project"))
{
    taskStored = task;
    setUp();

    QGridLayout *innerBox = new QGridLayout(block);
    innerBox->setAlignment(Qt::AlignHCenter);

    QLabel *endDateLabel = new QLabel(endDate->toString("yyyy-MM-d"));
    endDateLabel->setAlignment(Qt::AlignCenter);

    innerBox->addWidget(title, 0, 0, 1, 2);

    QLabel *data_f = new QLabel("Due Date: ");
    innerBox->addWidget(data_f,1,0);
    innerBox->addWidget(endDateLabel,1,1);

    QLabel *tipo = new QLabel("Type: ");
    innerBox->addWidget(tipo,2,0);
    innerBox->addWidget(type,2,1,1,2);

    outerBox->addWidget(block);

    outerBox->setContentsMargins(1,1,1,1);
    outerBox->setSpacing(0);
}

void TaskBlock::setUp(){
    outerBox = new QVBoxLayout(this);

    title->setAlignment(Qt::AlignCenter);
    title->setObjectName("Title");
    title->setStyleSheet("QLabel#Title {font-weight: bold; font-size: 16px;}");

    type->setAlignment(Qt::AlignCenter);

    block = new QFrame();
    block->setObjectName("TaskBlock");
    block->setFrameShape(QFrame::StyledPanel);
    block->setFrameShadow(QFrame::Plain);
    block->setStyleSheet("QFrame#TaskBlock { border: 1px solid #000000; border-radius: 3px;}"
                         "QFrame#TaskBlock:hover { border: 2px solid; border-color: #3498db;}");
    block->setMinimumWidth(270);
    block->setMaximumWidth(470);
    block->setMinimumHeight(100);
    block->setMaximumHeight(105);

}

void TaskBlock::mouseReleaseEvent(QMouseEvent *event){
    emit clicked(this);
}

void TaskBlock::mouseDoubleClickEvent(QMouseEvent *event){
    emit doubleClicked(taskStored);
}

void TaskBlock::selected(){

    auto *sizeAnimation = new QPropertyAnimation(block, "size", this);
    block->setStyleSheet("QFrame#TaskBlock { border: 2px solid #3498db; border-radius: 3px;}");
    sizeAnimation->setDuration(100);
    sizeAnimation->setEasingCurve(QEasingCurve::OutQuart);
    sizeAnimation->setStartValue(sizeAnimation->targetObject()->property("size").toSize());
    block->setMaximumHeight(block->height()+5);
    sizeAnimation->setEndValue(QSize(block->width(),block->height()+5));
    block->setMinimumSize(block->width(),block->height()+5);
    sizeAnimation->start();

}

void TaskBlock::unselected(){
    block->setStyleSheet("QFrame#TaskBlock { border: 1px solid #000000; border-radius: 3px;}"
                         "QFrame#TaskBlock:hover { border: 2px solid; border-color: #3498db;}");
    block->setMinimumWidth(270);
    block->setMaximumWidth(470);
    block->setMinimumHeight(100);
    block->setMaximumHeight(105);
}

QDate* TaskBlock::getStartDate() const {
    return startDate;
}

QDate* TaskBlock::getEndDate() const{
    return endDate;
}

QString TaskBlock::getTitle() const{
    return title->text();
}
int TaskBlock::getType() const{
    return types.indexOf(type->text());
}
