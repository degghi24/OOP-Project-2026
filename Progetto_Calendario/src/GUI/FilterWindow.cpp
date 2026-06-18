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
    QCheckBox *start_check = new QCheckBox();
    merge->addWidget(start_check);
    merge->addWidget(startDateLabel);
    //connect checkBox with endDateSelect
    connect(start_check, &QCheckBox::checkStateChanged, this, &FilterWindow::toggleEndDateEdit);


    col1->addWidget(endDateLabel);
    col1->addWidget(endDateSelect);

    col2->addLayout(merge);
    col2->addWidget(stardDateSelect);

    col3->addWidget(typeLabel);
    col3->addWidget(typeSelect);

    hGrid->addLayout(col1,0,1);
    hGrid->addLayout(col2,0,2);
    hGrid->addLayout(col3,0,3);

    hGrid->setSpacing(0);

    setMinimumWidth(290);

    toggleEndDateEdit(false);
}

void FilterWindow::toggleEndDateEdit(bool state){
    stardDateSelect->setReadOnly(!state);
    if(!state){
        QPalette pal = stardDateSelect->palette();
        pal.setColor(QPalette::Base, QColor(225, 225, 225));
        stardDateSelect->setPalette(pal);
    }else{
        QPalette pal = stardDateSelect->palette();
        pal.setColor(QPalette::Base, QColor(255, 255, 255));
        stardDateSelect->setPalette(pal);
    }
}

QDate* FilterWindow::getStartDate(){
    if(stardDateSelect->isReadOnly()){
        return nullptr;
    }
    return new QDate(stardDateSelect->date());
}

QDate* FilterWindow::getEndDate(){
    return new QDate(endDateSelect->date());
}

int FilterWindow::getType(){
    return typeSelect->currentIndex();
}
