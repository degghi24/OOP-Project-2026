#include "FilterWindow.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QSpacerItem>


FilterWindow::FilterWindow(QWidget *parent): QWidget(parent) {

    stardDateSelect = new QDateEdit();
    endDateSelect = new QDateEdit();
    typeSelect = new QComboBox();

    stardDateSelect->setCalendarPopup(true);
    endDateSelect->setCalendarPopup(true);
    typeSelect->addItem("All");
    typeSelect->addItem("Activity");
    typeSelect->addItem("Work");
    typeSelect->addItem("Bill");
    typeSelect->addItem("Project");
    typeSelect->addItem("Reminder");

    stardDateSelect->setMinimumSize(90,25);
    endDateSelect->setMinimumSize(90,25);
    typeSelect->setMinimumSize(80,25);

    stardDateSelect->setMaximumSize(90,25);
    endDateSelect->setMaximumSize(90,25);
    typeSelect->setMaximumSize(80,25);

    stardDateSelect->setDate(QDate(2026,1,1));
    endDateSelect->setDate(QDate(2026,12,31));

    QGridLayout *hGrid = new QGridLayout(this);

    QLabel *startDateLabel = new QLabel("Start Date :");
    QLabel *endDateLabel = new QLabel("End Date :");
    QLabel *typeLabel = new QLabel("Type :");

    QVBoxLayout *col1 = new QVBoxLayout();
    QVBoxLayout *col2 = new QVBoxLayout();
    QVBoxLayout *col3 = new QVBoxLayout();

    QHBoxLayout *merge = new QHBoxLayout();
    QCheckBox *end_check = new QCheckBox();
    merge->addWidget(end_check);
    merge->addWidget(endDateLabel);
    //connect checkBox with endDateSelect
    connect(end_check, &QCheckBox::checkStateChanged,this,&FilterWindow::toggleEndDateEdit);


    col1->addWidget(startDateLabel);
    col1->addWidget(stardDateSelect);

    col2->addLayout(merge);
    col2->addWidget(endDateSelect);

    col3->addWidget(typeLabel);
    col3->addWidget(typeSelect);

    hGrid->addLayout(col1,0,1);
    hGrid->addLayout(col2,0,2);
    hGrid->addLayout(col3,0,3);

    hGrid->setSpacing(0);

    setMinimumWidth(290);
}

void FilterWindow::toggleEndDateEdit(bool state){
    endDateSelect->setReadOnly(state);
    if(state){
        QPalette pal = endDateSelect->palette();
        pal.setColor(QPalette::Base, QColor(225, 225, 225));
        endDateSelect->setPalette(pal);
    }else{
        QPalette pal = endDateSelect->palette();
        pal.setColor(QPalette::Base, QColor(255, 255, 255));
        endDateSelect->setPalette(pal);
    }
}
