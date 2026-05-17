#include "RepeatableEditPage.h"

RepeatableEditPage::RepeatableEditPage(RepeatableTask *task, QWidget *parent): AbstractEditPage(task, parent) {
    setUp();

    if(task){
        monday->setChecked(task->getWeekDays()[0]);
        tuesday->setChecked(task->getWeekDays()[1]);
        wednesday->setChecked(task->getWeekDays()[2]);
        thursday->setChecked(task->getWeekDays()[3]);
        friday->setChecked(task->getWeekDays()[4]);
        saturday->setChecked(task->getWeekDays()[5]);
        sunday->setChecked(task->getWeekDays()[6]);

        QString eDate = task->getRepeatEndDate().c_str();
        intervalDays->setValue(task->getIntervalDays());
        endDate->setDate(QDate(eDate.section("-",0,0).toInt(), eDate.section("-",1,1).toInt(),eDate.section("-",2,2).toInt()));
        active->setChecked(task->isActive());
    }

}

RepeatableEditPage::RepeatableEditPage(QWidget *parent): AbstractEditPage(parent) {
    setUp();
}

void RepeatableEditPage::setUp(){

    QGridLayout *weekDays = new QGridLayout();

    monday = new QCheckBox;
    tuesday = new QCheckBox;
    wednesday = new QCheckBox;
    thursday = new QCheckBox;
    friday = new QCheckBox;
    saturday = new QCheckBox;
    sunday = new QCheckBox;

    weekDays->addWidget(new QLabel("Mon"),0,0);
    weekDays->addWidget(new QLabel("Tue"),0,1);
    weekDays->addWidget(new QLabel("Wed"),0,2);
    weekDays->addWidget(new QLabel("Thu"),0,3);
    weekDays->addWidget(new QLabel("Fri"),0,4);
    weekDays->addWidget(new QLabel("Sat"),0,5);
    weekDays->addWidget(new QLabel("Sun"),0,6);

    weekDays->addWidget(monday,1,0);
    weekDays->addWidget(tuesday,1,1);
    weekDays->addWidget(wednesday,1,2);
    weekDays->addWidget(thursday,1,3);
    weekDays->addWidget(friday,1,4);
    weekDays->addWidget(saturday,1,5);
    weekDays->addWidget(sunday,1,6);

    intervalDays = new QSpinBox();
    endDate = new QDateEdit();
    active = new QCheckBox();

    page->addWidget(new QLabel("Work Days:"));
    page->addLayout(weekDays);
    QHBoxLayout *lineInterval = new QHBoxLayout();
    lineInterval->setAlignment(Qt::AlignLeft | Qt::AlignJustify);
    lineInterval->addWidget(new QLabel("Interval:"));
    lineInterval->addWidget(intervalDays);
    page->addLayout(lineInterval);
    QHBoxLayout *lineEDate = new QHBoxLayout();
    lineEDate->setAlignment(Qt::AlignLeft| Qt::AlignJustify);
    lineEDate->addWidget(new QLabel("End Date:"));
    lineEDate->addWidget(endDate);
    page->addLayout(lineEDate);
    QHBoxLayout *line = new QHBoxLayout();
    line->setAlignment(Qt::AlignLeft);
    line->addWidget(new QLabel("Is Active:"));
    line->addWidget(active);
    page->addLayout(line);

}

QBitArray RepeatableEditPage::getWorkDays() const{
    QBitArray workDays(7);
    workDays[0] = monday->isChecked();
    workDays[1] = tuesday->isChecked();
    workDays[2] = wednesday->isChecked();
    workDays[3] = thursday->isChecked();
    workDays[4] = friday->isChecked();
    workDays[5] = saturday->isChecked();
    workDays[6] = sunday->isChecked();

    return workDays;
}
int RepeatableEditPage::getIntervalDays() const{
    return intervalDays->value();
}
std::string RepeatableEditPage::getEndDate() const{
    return endDate->date().toString("yyyy-MM-d").toStdString();
}
bool RepeatableEditPage::isActive() const{
    return active->isChecked();
}

