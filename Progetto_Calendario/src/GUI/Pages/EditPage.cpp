#include "EditPage.h"

#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QRadioButton>
#include <QComboBox>

QStringList list{"Activity","Reminder","Bill","Project","Work"};

EditPage::EditPage(Activity *Activity, QWidget *parent): QWidget(parent), layout(new QStackedLayout(this)){

    ActivityEdit *activityPage = new ActivityEdit(Activity);
    layout->addWidget(activityPage);

    //SAVE EDIT
    //connect(this, &EditPage::confirmSave, activityPage, &ActivityEdit::saveEdit)

    /*connect(this, &EditPage::createTask, activityPage, &ActivityEdit::createTask); WRONG
    connect(activityPage, &ActivityEdit::returnTask, this, &EditPage::sendTask);*/
}

EditPage::EditPage(Reminder *Reminder, QWidget *parent): QWidget(parent), layout(new QStackedLayout(this)){

    ReminderEdit *reminderPage = new ReminderEdit(Reminder);
    layout->addWidget(reminderPage);

}

EditPage::EditPage(Work *Work, QWidget *parent): QWidget(parent), layout(new QStackedLayout(this)){

    WorkEdit *workPage = new WorkEdit(Work);
    layout->addWidget(workPage);

}

EditPage::EditPage(Bill *Bill, QWidget *parent): QWidget(parent), layout(new QStackedLayout(this)){

    BillEdit *billPage = new BillEdit(Bill);
    layout->addWidget(billPage);

}

EditPage::EditPage(Project *Project, QWidget *parent): QWidget(parent), layout(new QStackedLayout(this)){

    ProjectEdit *projectPage = new ProjectEdit(Project);
    layout->addWidget(projectPage);

}

EditPage::EditPage(QString type, QWidget *parent): QWidget(parent), layout(new QStackedLayout(this)){

    switch (list.indexOf(type)) {
    case 0:
        setUpActivityEdit();
        break;
    case 1:
        setUpReminderEdit();
        break;
    case 2:
        setUpBillEdit();
        break;
    case 3:
        setUpProjectEdit();
        break;
    case 4:
        setUpWorkEdit();
        break;
    default:
        qDebug()<<"Nothing";
        break;
    }

}

void EditPage::setUpActivityEdit(){
    ActivityEdit *activityPage = new ActivityEdit();
    layout->addWidget(activityPage);

    connect(this, &EditPage::createTask, activityPage, &ActivityEdit::createTask);
    connect(activityPage, &ActivityEdit::returnTask, this, &EditPage::sendTask);
}
void EditPage::setUpReminderEdit(){
    ReminderEdit *reminderPage = new ReminderEdit();
    layout->addWidget(reminderPage);

    connect(this, &EditPage::createTask, reminderPage, &ReminderEdit::createTask);
    connect(reminderPage, &ReminderEdit::returnTask, this, &EditPage::sendTask);
}
void EditPage::setUpBillEdit(){
    BillEdit *billPage = new BillEdit();
    layout->addWidget(billPage);

    connect(this, &EditPage::createTask, billPage, &BillEdit::createTask);
    connect(billPage, &BillEdit::returnTask, this, &EditPage::sendTask);
}
void EditPage::setUpProjectEdit(){
    ProjectEdit *projectPage = new ProjectEdit();
    layout->addWidget(projectPage);

    connect(this, &EditPage::createTask, projectPage, &ProjectEdit::createTask);
    connect(projectPage, &ProjectEdit::returnTask, this, &EditPage::sendTask);
}
void EditPage::setUpWorkEdit(){
    WorkEdit *workPage = new WorkEdit();
    layout->addWidget(workPage);

    connect(this, &EditPage::createTask, workPage, &WorkEdit::createTask);
    connect(workPage, &WorkEdit::returnTask, this, &EditPage::sendTask);
}

void EditPage::confirmCreation(){
    //! controllo correzione sei dati inseriti
    emit createTask();
}
