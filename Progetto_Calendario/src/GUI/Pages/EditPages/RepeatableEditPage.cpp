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

    QHBoxLayout *weekDays = new QHBoxLayout();

    QCheckBox *monday = new QCheckBox;
    QCheckBox *tuesday = new QCheckBox;
    QCheckBox *wednesday = new QCheckBox;
    QCheckBox *thursday = new QCheckBox;
    QCheckBox *friday = new QCheckBox;
    QCheckBox *saturday = new QCheckBox;
    QCheckBox *sunday = new QCheckBox;

    weekDays->addWidget(monday);
    weekDays->addWidget(tuesday);
    weekDays->addWidget(wednesday);
    weekDays->addWidget(thursday);
    weekDays->addWidget(friday);
    weekDays->addWidget(saturday);
    weekDays->addWidget(sunday);

    QSpinBox *intervalDays = new QSpinBox();
    QDateEdit *endDate = new QDateEdit();
    QCheckBox *active = new QCheckBox();

    page->addWidget(new QLabel("Work Days:"));
    page->addLayout(weekDays);
    page->addWidget(new QLabel("Interval:"));
    page->addWidget(intervalDays);
    page->addWidget(new QLabel("End Date:"));
    page->addWidget(endDate);
    page->addWidget(new QLabel("Is Active:"));
    page->addWidget(active);

}
