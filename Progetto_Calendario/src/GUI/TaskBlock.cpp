#include "TaskBlock.h"

#include <QGridLayout>
#include <QSplitter>

TaskBlock::TaskBlock(QWidget *parent): QWidget(parent) {}


TaskBlock::TaskBlock(QString sDate, QString t, QString tp, QString eDate):
    startDate(new QLabel(sDate)),
    title(new QLabel(t)),
    type(new QLabel(tp))
{
    startDate->setAlignment(Qt::AlignCenter);
    title->setAlignment(Qt::AlignCenter);
    type->setAlignment(Qt::AlignCenter);

    QVBoxLayout *outerBox = new QVBoxLayout(this);

    block = new QFrame();
    block->setObjectName("TaskBlock");
    block->setFrameShape(QFrame::StyledPanel);
    block->setFrameShadow(QFrame::Plain);
    block->setStyleSheet("QFrame#TaskBlock { border: 1px solid #000000; border-radius: 3px; }");
    block->setMinimumWidth(270);

    QGridLayout *box = new QGridLayout(block);
    box->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    if(eDate != nullptr){
        endDate = new QLabel(eDate);
        endDate->setAlignment(Qt::AlignCenter);

        box->addWidget(title, 1, 1, 1, 2);
        box->addWidget(startDate,2,1);

        box->addWidget(endDate,2,2);
    }else{
        box->addWidget(title, 1, 1);
        box->addWidget(startDate,2,1);
    }
    box->addWidget(type,3,1,1,2);

    outerBox->addWidget(block);

    outerBox->setContentsMargins(0,0,0,0);
    outerBox->setSpacing(0);

}

QString TaskBlock::getStartDate() const {
    return startDate->text();
}
QString TaskBlock::getEndDate() const{
    return endDate->text();
}
QString TaskBlock::getTitle() const{
    return title->text();
}
QString TaskBlock::getType() const{
    return type->text();
}

void TaskBlock::setStartDate(QString sDate){
    startDate->setText(sDate);
}

void TaskBlock::setEndDate(QString eDate){
    endDate->setText(eDate);
}

void TaskBlock::setTitle(QString titleS){
    title->setText(titleS);
}

void TaskBlock::setType(QString typeS){
    type->setText(typeS);
}
