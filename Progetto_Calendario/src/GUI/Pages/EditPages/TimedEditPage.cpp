#include "TimedEditPage.h"

TimedEditPage::TimedEditPage(TimedTask *task,  QWidget *parent): AbstractEditPage(task,parent) {
    setUp();

    if(task){
        QString sDate = task->getStartDate().c_str();
        QString eDate = task->getEndDate().c_str();
        QString time = task->getStartTime().c_str();

        startDate = new QDateEdit(QDate(sDate.section("-",0,0).toInt(), sDate.section("-",1,1).toInt(),sDate.section("-",2,2).toInt()));
        endDate = new QDateEdit(QDate(eDate.section("-",0,0).toInt(), eDate.section("-",1,1).toInt(),eDate.section("-",2,2).toInt()));
        starTime = new QTimeEdit(QTime(time.section(":",0,0).toInt(), time.section(":",1,1).toInt(),time.section(":",2,2).toInt()));
        duration = new QSpinBox();
        duration->setValue(task->getTotalDuration());
    }

}

TimedEditPage::TimedEditPage(QWidget *parent): AbstractEditPage(parent) {
    setUp();
}

void TimedEditPage::setUp(){

    startDate = new QDateEdit();
    endDate = new QDateEdit();
    starTime = new QTimeEdit();
    duration = new QSpinBox();

    QGridLayout *innerBox = new QGridLayout();
    innerBox->addWidget(new QLabel("Start Date:"),0,0);
    innerBox->addWidget(startDate,1,0);
    innerBox->addWidget(new QLabel("End Date:"),0,1);
    innerBox->addWidget(endDate,1,1);
    page->addLayout(innerBox);
    QHBoxLayout *line1 = new QHBoxLayout();
    line1->addWidget(new QLabel("Start Time:"));
    line1->addWidget(starTime);
    page->addLayout(line1);
    QHBoxLayout *line2 = new QHBoxLayout();
    line2->addWidget(new QLabel("Duration"));
    line2->addWidget(duration);
    page->addLayout(line2);

}

std::string TimedEditPage::getStartDate() const{
    return startDate->date().toString("yyyy-MM-d").toStdString();
}
std::string TimedEditPage::getEndDate() const{
    return endDate->date().toString("yyyy-MM-d").toStdString();
}
std::string TimedEditPage::getStartTime() const{
    return starTime->time().toString("H-m-s").toStdString();
}
int TimedEditPage::getDuration() const{
    return duration->value();
}
