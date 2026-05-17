#include "TaskBlock.h"

#include <QGridLayout>
#include <QSplitter>

TaskBlock::TaskBlock(QWidget *parent): QWidget(parent) {}


TaskBlock::TaskBlock(QString *title_, QDate *startDate_, int *type_, QDate *endDate_):
    title(new QLabel(*title_)),
    startDate(startDate_),
    endDate(endDate_),
    type(new QComboBox())
{
    title->setAlignment(Qt::AlignCenter);

    type->addItem("Activity");
    type->addItem("Work");
    type->addItem("Bill");
    type->addItem("Project");
    type->addItem("Reminder");
    type->setEditable(false);

    QLabel *startDateLabel = new QLabel(startDate->toString("yyyy-MM-d"));

    QVBoxLayout *outerBox = new QVBoxLayout(this);

    block = new QFrame();
    block->setObjectName("TaskBlock");
    block->setFrameShape(QFrame::StyledPanel);
    block->setFrameShadow(QFrame::Plain);
    block->setStyleSheet("QFrame#TaskBlock { border: 1px solid #000000; border-radius: 3px; }");
    block->setMinimumWidth(270);
    block->setMaximumWidth(470);
    block->setMinimumHeight(75);
    block->setMaximumHeight(75);


    QGridLayout *box = new QGridLayout(block);
    box->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    if(endDate != nullptr){
        QLabel *endDateLabel = new QLabel(endDate->toString("yyyy-MM-d"));
        endDateLabel->setAlignment(Qt::AlignCenter);

        box->addWidget(title, 1, 1, 1, 2);
        box->addWidget(startDateLabel,2,1);

        box->addWidget(endDateLabel,2,2);
    }else{
        box->addWidget(title, 1, 1);
        box->addWidget(startDateLabel,2,1);
    }
    box->addWidget(type,3,1,1,2);

    outerBox->addWidget(block);

    outerBox->setContentsMargins(0,0,0,0);
    outerBox->setSpacing(0);

}

QDate TaskBlock::getStartDate() const {
    return *startDate;
}
QDate TaskBlock::getEndDate() const{
    return *endDate;
}
QString TaskBlock::getTitle() const{
    return title->text();
}
int TaskBlock::getType() const{
    return type->currentIndex();
}
