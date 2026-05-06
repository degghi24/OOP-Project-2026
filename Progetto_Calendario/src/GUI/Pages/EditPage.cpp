#include "EditPage.h"

#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QRadioButton>
#include <QComboBox>


EditPage::EditPage(QString type,QWidget *parent):QWidget(parent), page(new QVBoxLayout(this)){
    setWindowTitle(type);

    setUp(type);
}

EditPage::EditPage(Activity *Activity, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

    timedBase(Activity);

    QLineEdit *location = new QLineEdit();
    QSpinBox *partecipationCount = new QSpinBox();
    QLineEdit *eventType = new QLineEdit();
    QCheckBox *isOnline = new QCheckBox();
    QLineEdit *meetingLink = new QLineEdit();

    location->setText(Activity->getLocation().c_str());
    partecipationCount->setValue(Activity->getParticipantCount());
    eventType->setText(Activity->getEventType().c_str());
    isOnline->setChecked(Activity->isOnline());
    meetingLink->setText(Activity->getMeetingLink().c_str());

    page->addWidget(new QLabel("Location:"));
    page->addWidget(location);
    page->addWidget(new QLabel("Number of Partecipants:"));
    page->addWidget(partecipationCount);
    page->addWidget(new QLabel("Type of Event:"));
    page->addWidget(eventType);
    page->addWidget(new QLabel("Is Online:"));
    page->addWidget(isOnline);
    page->addWidget(new QLabel("Meeting Link:"));
    page->addWidget(meetingLink);
}

EditPage::EditPage(Reminder *Reminder, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

    timedBase(Reminder);

    QLineEdit *notifyTime = new QLineEdit();
    QLineEdit *alertMessage = new QLineEdit();
    QRadioButton *snoozed = new QRadioButton();
    QSpinBox *snoozeMinute = new QSpinBox();

    notifyTime->setText(Reminder->getNotifyTime().c_str());
    alertMessage->setText(Reminder->getAlertMessage().c_str());
    snoozed->setChecked(Reminder->isSnoozed());
    snoozeMinute->setValue(Reminder->getSnoozeMinutes());

    page->addWidget(new QLabel("Time of Notificatoin:"));
    page->addWidget(notifyTime);
    page->addWidget(new QLabel("Alert Message:"));
    page->addWidget(alertMessage);
    page->addWidget(new QLabel("Is Snoozed:"));
    page->addWidget(snoozed);
    page->addWidget(new QLabel("Minute Before Time:"));
    page->addWidget(snoozeMinute);
}

EditPage::EditPage(Work *Work, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

    repeatableBase(Work);

    QLineEdit *subTaskToAdd = new QLineEdit(); //need add button
    QSpinBox *progress = new QSpinBox();
    QLineEdit *client = new QLineEdit();
    QLineEdit *category = new QLineEdit();
    QLineEdit *notes = new QLineEdit();

    subTaskToAdd->setText(Work->getSubTasks().join(" "));
    progress->setValue(Work->getProgress());
    client->setText(Work->getClient().c_str());
    category->setText(Work->getCategory().c_str());
    notes->setText(Work->getNotes().c_str());

    page->addWidget(new QLabel("Subtasks:"));
    page->addWidget(subTaskToAdd);
    page->addWidget(new QLabel("Progress:"));
    page->addWidget(progress);
    page->addWidget(new QLabel("Client:"));
    page->addWidget(client);
    page->addWidget(new QLabel("Category:"));
    page->addWidget(category);
    page->addWidget(new QLabel("Notes:"));
    page->addWidget(notes);
}

EditPage::EditPage(Bill *Bill, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

    deadlineBase(Bill);

    QSpinBox *amount = new QSpinBox();
    QRadioButton *paid = new QRadioButton();
    QLineEdit *provider = new QLineEdit();
    QLineEdit *iban = new QLineEdit();
    QRadioButton *recurring = new QRadioButton();

    amount->setValue(Bill->getAmount());
    paid->setChecked(Bill->isPaid());
    provider->setText(Bill->getProvider().c_str());
    iban->setText(Bill->getIBAN().c_str());
    recurring->setChecked(Bill->isRecurring());

    page->addWidget(new QLabel("Amount:"));
    page->addWidget(amount);
    page->addWidget(new QLabel("Is Paid:"));
    page->addWidget(paid);
    page->addWidget(new QLabel("Provider:"));
    page->addWidget(provider);
    page->addWidget(new QLabel("Iban:"));
    page->addWidget(iban);
    page->addWidget(new QLabel("Is Recurring:"));
    page->addWidget(recurring);
}

EditPage::EditPage(Project *Project, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

    deadlineBase(Project);

    QLineEdit *milestone = new QLineEdit(this);
    QLineEdit *team = new QLineEdit(this); // multi insert
    QSpinBox *budget = new QSpinBox(this);
    QLineEdit *status = new QLineEdit(this);
    QLineEdit *tags = new QLineEdit(this); // multi insert

    milestone->setText(Project->getMilestone().c_str());
    team->setText(Project->getTeam().join(" "));
    budget->setValue(Project->getBudget());
    status->setText(Project->getStatus().c_str());
    tags->setText(Project->getTags().join(" "));

    page->addWidget(new QLabel("Milestone:"));
    page->addWidget(milestone);
    page->addWidget(new QLabel("Team:"));
    page->addWidget(team);
    page->addWidget(new QLabel("Budget:"));
    page->addWidget(budget);
    page->addWidget(new QLabel("Status:"));
    page->addWidget(status);
    page->addWidget(new QLabel("Tags:"));
    page->addWidget(tags);
}



void EditPage::setUp(QString type){

    if(type == "Activity"){
        timedBase();
        QLineEdit *location = new QLineEdit();
        QSpinBox *partecipationCount = new QSpinBox();
        QLineEdit *eventType = new QLineEdit();
        QCheckBox *isOnline = new QCheckBox();
        QLineEdit *meetingLink = new QLineEdit();

        page->addWidget(new QLabel("Location:"));
        page->addWidget(location);
        QHBoxLayout *line1 = new QHBoxLayout();
        line1->addWidget(new QLabel("Number of Partecipants:"));
        line1->addWidget(partecipationCount);
        page->addLayout(line1);
        page->addWidget(new QLabel("Type of Event:"));
        page->addWidget(eventType);
        QHBoxLayout *line2 = new QHBoxLayout();
        line2->addWidget(new QLabel("Is Online:"));
        line2->addWidget(isOnline);
        page->addLayout(line2);
        page->addWidget(new QLabel("Meeting Link:"));
        page->addWidget(meetingLink);

    }else if(type == ("Reminder")){
        timedBase();
        QLineEdit *notifyTime = new QLineEdit();
        QLineEdit *alertMessage = new QLineEdit();
        QRadioButton *snoozed= new QRadioButton();
        QSpinBox *snoozeMinute = new QSpinBox();

        QHBoxLayout *line1 = new QHBoxLayout();
        line1->addWidget(new QLabel("Time of Notificatoin:"));
        line1->addWidget(notifyTime);
        page->addLayout(line1);
        page->addWidget(new QLabel("Alert Message:"));
        page->addWidget(alertMessage);
        QHBoxLayout *line2 = new QHBoxLayout();
        line2->addWidget(new QLabel("Is Snoozed:"));
        line2->addWidget(snoozed);
        page->addLayout(line2);
        QHBoxLayout *line3 = new QHBoxLayout();
        line3->addWidget(new QLabel("Minute Before Time:"));
        line3->addWidget(snoozeMinute);
        page->addLayout(line3);

    }else if(type == ("Bill")){
        deadlineBase();

        QSpinBox *amount = new QSpinBox();
        QRadioButton *paid = new QRadioButton();
        QLineEdit *provider = new QLineEdit();
        QLineEdit *iban = new QLineEdit();
        QRadioButton *recurring = new QRadioButton();

        page->addWidget(new QLabel("Amount:"));
        page->addWidget(amount);
        page->addWidget(new QLabel("Is Paid:"));
        page->addWidget(paid);
        page->addWidget(new QLabel("Provider:"));
        page->addWidget(provider);
        page->addWidget(new QLabel("Iban:"));
        page->addWidget(iban);
        page->addWidget(new QLabel("Is Recurring:"));
        page->addWidget(recurring);

    }else if(type == ("Project")){
        deadlineBase();

        QLineEdit *milestone = new QLineEdit(this);
        QLineEdit *team = new QLineEdit(this); // multi insert
        QSpinBox *budget = new QSpinBox(this);
        QLineEdit *status = new QLineEdit(this);
        QLineEdit *tags = new QLineEdit(this); // multi insert

        page->addWidget(new QLabel("Milestone:"));
        page->addWidget(milestone);
        page->addWidget(new QLabel("Team:"));
        page->addWidget(team);
        page->addWidget(new QLabel("Budget:"));
        page->addWidget(budget);
        page->addWidget(new QLabel("Status:"));
        page->addWidget(status);
        page->addWidget(new QLabel("Tags:"));
        page->addWidget(tags);

    }else if(type == ("Work")){
        repeatableBase();

        QLineEdit *subTaskToAdd = new QLineEdit(); //need add button
        QSpinBox *progress = new QSpinBox();
        QLineEdit *client = new QLineEdit();
        QLineEdit *category = new QLineEdit();
        QLineEdit *notes = new QLineEdit();

        page->addWidget(new QLabel("Subtasks:"));
        page->addWidget(subTaskToAdd);
        page->addWidget(new QLabel("Progress:"));
        page->addWidget(progress);
        page->addWidget(new QLabel("Client:"));
        page->addWidget(client);
        page->addWidget(new QLabel("Category:"));
        page->addWidget(category);
        page->addWidget(new QLabel("Notes:"));
        page->addWidget(notes);

    }else{

    }
}


void EditPage::abstractBase(AbstractTask *task){

    //ID is auto assigned by the listManager
    QLineEdit *title = new QLineEdit();
    QTextEdit *description = new QTextEdit();
    QLineEdit *assignee = new QLineEdit();
    //QDateEdit *creationDate = new QDateEdit();

    page->addWidget(new QLabel("Title"));
    page->addWidget(title);
    page->addWidget(new QLabel("Description"));
    page->addWidget(description);
    QHBoxLayout *line = new QHBoxLayout();
    line->addWidget(new QLabel("Assignee"));
    line->addWidget(assignee);
    page->addLayout(line);
    //page->addWidget(new QLabel("Creation Date")); //outo-assigned
    //page->addWidget(creationDate);
    if(task){
        title->setText(task->getTitle().c_str());
        description->setText(task->getDescription().c_str());
        assignee->setText(task->getAssignee().c_str());
    }

}

void EditPage::timedBase(TimedTask *task){
    abstractBase(task);

    QDateEdit *startDate = new QDateEdit();
    QDateEdit *endDate = new QDateEdit();
    QLineEdit *starTime = new QLineEdit();
    QSpinBox *duration = new QSpinBox();
    startDate->setCalendarPopup(true);
    endDate->setCalendarPopup(true);

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

    if(task){
        QString sDate = task->getStartDate().c_str();
        startDate->setDate(QDate(sDate.section("-",0,0).toInt(), sDate.section("-",1,1).toInt(),sDate.section("-",2,2).toInt()));
        QString eDate = task->getEndDate().c_str();
        endDate->setDate(QDate(eDate.section("-",0,0).toInt(), eDate.section("-",1,1).toInt(),eDate.section("-",2,2).toInt()));
        starTime->setText(task->getStartTime().c_str());
        duration->setValue(task->getTotalDuration());
    }

}

void EditPage::repeatableBase(RepeatableTask *task){
    abstractBase(task);

    //QHBoxLayout *weekDays = new QHBoxLayout()
    //QCheckBox *monday = new QCheckBox();
    //QCheckBox *tuesday = new QCheckBox();
    //QCheckBox *wednesday = new QCheckBox();
    //QCheckBox *thursday = new QCheckBox();
    //QCheckBox *friday = new QCheckBox();
    //QCheckBox *saturday = new QCheckBox();
    //QCheckBox *sunday = new QCheckBox();

    QCheckBox *weekDays = new QCheckBox(); //list of QCheckBoxs
    QSpinBox *intervalDays = new QSpinBox();
    QDateEdit *endDate = new QDateEdit();
    QCheckBox *active = new QCheckBox();

    page->addWidget(new QLabel("Work Days:"));
    page->addWidget(weekDays);
    page->addWidget(new QLabel("Interval:"));
    page->addWidget(intervalDays);
    page->addWidget(new QLabel("End Date:"));
    page->addWidget(endDate);
    page->addWidget(new QLabel("Is Active:"));
    page->addWidget(active);
    if(task){
        for(int i = 0; i < 7; ++i){
            //weekDays[i].setChecked(task->getWeekDays()[i]);
        }
        //weekDays->setChecked();
        QString eDate = task->getRepeatEndDate().c_str();
        intervalDays->setValue(task->getIntervalDays());
        endDate->setDate(QDate(eDate.section("-",0,0).toInt(), eDate.section("-",1,1).toInt(),eDate.section("-",2,2).toInt()));
        active->setChecked(task->isActive());
    }

}

void EditPage::deadlineBase(Deadline *task){
    abstractBase(task);

    QDateEdit *dueDate = new QDateEdit();
    QComboBox *prio = new QComboBox();
    prio->addItem("Low");
    prio->addItem("Medium");
    prio->addItem("High");
    QRadioButton *completed = new QRadioButton();
    QRadioButton *skipped = new QRadioButton();

    page->addWidget(new QLabel("Due Date:"));
    page->addWidget(dueDate);
    page->addWidget(new QLabel("Priotity:"));
    page->addWidget(prio);
    page->addWidget(new QLabel("Is Completed:"));
    page->addWidget(completed);
    page->addWidget(new QLabel("Is Skipped:"));
    page->addWidget(skipped);
    if(task){
        QString dDate = task->getDueDate().c_str();
        dueDate->setDate(QDate(dDate.section("-",0,0).toInt(), dDate.section("-",1,1).toInt(),dDate.section("-",2,2).toInt()));
        prio->setCurrentIndex(task->getPriority());
        completed->setChecked(task->isCompleted());
        skipped->setChecked(task->isSkipped());
    }

}
