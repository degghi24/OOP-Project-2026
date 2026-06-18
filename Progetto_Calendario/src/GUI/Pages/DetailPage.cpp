#include "DetailPage.h"

#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QRadioButton>
#include <QComboBox>

DetailPage::DetailPage(const Activity *Activity, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

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

DetailPage::DetailPage(const Reminder *Reminder, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

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

DetailPage::DetailPage(const Work *Work, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

    repeatableBase(Work);

    //QLineEdit *subTask = new QLineEdit(); //need add button
    QSpinBox *progress = new QSpinBox();
    QLineEdit *client = new QLineEdit();
    QLineEdit *category = new QLineEdit();
    QLineEdit *notes = new QLineEdit();

    //subTask->setText(Work->getSubTasks().join(" "));
    progress->setValue(Work->getProgress());
    client->setText(Work->getClient().c_str());
    category->setText(Work->getCategory().c_str());
    notes->setText(Work->getNotes().c_str());

    /*page->addWidget(new QLabel("Subtasks:"));
    page->addWidget(subTaskToAdd);*/
    page->addWidget(new QLabel("Progress:"));
    page->addWidget(progress);
    page->addWidget(new QLabel("Client:"));
    page->addWidget(client);
    page->addWidget(new QLabel("Category:"));
    page->addWidget(category);
    page->addWidget(new QLabel("Notes:"));
    page->addWidget(notes);
}

DetailPage::DetailPage(const Bill *Bill, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

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

DetailPage::DetailPage(const Project *Project, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

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


void DetailPage::abstractBase(const AbstractTask *task){

    //ID is auto assigned by the listManager
    QLabel *title = new QLabel(task->getTitle().c_str());
    QLabel *description = new QLabel(task->getDescription().c_str());
    QLabel *assignee = new QLabel(task->getAssignee().c_str());
    QLabel *creationDate = new QLabel(task->getCreationDate().toString("yyyy-MM-d"));

    page->addWidget(title);
    page->addWidget(new QLabel("Description"));
    page->addWidget(description);
    QHBoxLayout *line = new QHBoxLayout();
    line->addWidget(new QLabel("Assignee"));
    line->addWidget(assignee);
    page->addLayout(line);
    page->addWidget(new QLabel("Creation Date")); //outo-assigned
    page->addWidget(creationDate);

}

void DetailPage::timedBase(const TimedTask *task){
    abstractBase(task);

    QLabel *startDate = new QLabel(task->getStartDate().toString());
    QLabel *endDate = new QLabel(task->getEndDate().toString());
    QLabel *starTime = new QLabel(task->getStartTime().c_str());
    QLabel *duration = new QLabel(QString::number(task->getTotalDuration()));

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

void DetailPage::repeatableBase(const RepeatableTask *task){
    abstractBase(task);

    QHBoxLayout *weekDays = new QHBoxLayout();
    QStringList daysNames{"Monday", "Tuesday", "Wednesday", "Thurday", "Friday", "Saturday", "Sunday"};

    QLabel *intervalDays = new QLabel(QString::number(task->getIntervalDays()));
    QLabel *endDate = new QLabel(task->getRepeatEndDate().toString());
    QLabel *active = new QLabel(task->isActive() ? "True" : "False" );

    page->addWidget(new QLabel("Work Days:"));
    for(int i = 0; i < 7; ++i){
        QCheckBox *day = new QCheckBox(daysNames[i]);
        day->setChecked(task->getWeekDays()[i]);
        weekDays->addWidget(day);
        day->setCheckable(false);
    }
    page->addLayout(weekDays);
    page->addWidget(new QLabel("Interval:"));
    page->addWidget(intervalDays);
    page->addWidget(new QLabel("End Date:"));
    page->addWidget(endDate);
    page->addWidget(new QLabel("Is Active:"));
    page->addWidget(active);

}

void DetailPage::deadlineBase(const Deadline *task){
    abstractBase(task);

    QLabel *dueDate = new QLabel(task->getDueDate().toString());
    QLabel *completed = new QLabel(task->isCompleted() ? "True" : "False" );
    QLabel *skipped = new QLabel(task->isSkipped() ? "True" : "False" );

    page->addWidget(new QLabel("Due Date:"));
    page->addWidget(dueDate);
    page->addWidget(new QLabel("Priotity:"));
    switch (task->getPriority()) {
    case 0:
        page->addWidget(new QLabel("Low"));
        break;
    case 1:
        page->addWidget(new QLabel("Medium"));
        break;
    case 2:
        page->addWidget(new QLabel("High"));
        break;
    default:
        page->addWidget(new QLabel("Error"));
        break;
    }
    page->addWidget(new QLabel("Is Completed:"));
    page->addWidget(completed);
    page->addWidget(new QLabel("Is Skipped:"));
    page->addWidget(skipped);

}
