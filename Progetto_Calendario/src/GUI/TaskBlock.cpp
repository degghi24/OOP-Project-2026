#include "TaskBlock.h"

#include <QGridLayout>
#include <QSplitter>

TaskBlock::TaskBlock() {}


TaskBlock::TaskBlock(QString sDate, QString t, QString tp, QString eDate):
    startDate(new QLabel(sDate)),
    title(new QLabel(t)),
    type(new QLabel(tp))
{

    startDate->setAlignment(Qt::AlignCenter);
    title->setAlignment(Qt::AlignCenter);

    QGridLayout *box = new QGridLayout(this);
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
}

QString TaskBlock::getStartDate(){
    return startDate->text();
}
QString TaskBlock::getEndDate(){
    return endDate->text();
}
QString TaskBlock::getTitle(){
    return title->text();
}
QString TaskBlock::getType(){
    return type->text();
}
