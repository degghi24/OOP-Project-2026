#include "BlankPage.h"

#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QRadioButton>

BlankPage::BlankPage(QString &type, bool isEditable, QWidget *parent): QWidget(parent), page(new QVBoxLayout(this)){

    switch (list.indexOf(type)){
    case 0: //"Activity"
        if(isEditable){
            timedBase(isEditable);

            QLineEdit *location = new QLineEdit();
            QSpinBox *partecipationCount = new QSpinBox();
            QLineEdit *eventType = new QLineEdit();
            QCheckBox *isOnline = new QCheckBox();
            QLineEdit *meetingLink = new QLineEdit();

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

        break;
    case 1: //"Reminder"
        if(isEditable){
            timedBase(isEditable);

            QLineEdit *notifyTime = new QLineEdit();
            QLineEdit *alertMessage = new QLineEdit();
            QSpinBox *snoozed = new QSpinBox();
            QRadioButton *snoozeMinute = new QRadioButton();

            page->addWidget(new QLabel("Time of Notificatoin:"));
            page->addWidget(notifyTime);
            page->addWidget(new QLabel("Alert Message:"));
            page->addWidget(alertMessage);
            page->addWidget(new QLabel("Is Snoozed:"));
            page->addWidget(snoozed);
            page->addWidget(new QLabel("Minute Before Time:"));
            page->addWidget(snoozeMinute);
        }

        break;
    case 2: //"Bill"
        if(isEditable){
            timedBase(isEditable);

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
        }

        break;
    case 3: //"Project"
        if(isEditable){
            timedBase(isEditable);

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
        }

        break;
    case 4: //"Work"
        if(isEditable){
            timedBase(isEditable);

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
        }

        break;
    default:
        qDebug()<<"Default";
        break;
    };

}

void BlankPage::abstractBase(bool isEditable){

    //ID is auto assigned by the listManager
    if(isEditable){
        QLineEdit *title = new QLineEdit();
        QTextEdit *description = new QTextEdit();
        QLineEdit *assignee = new QLineEdit();
        //QDateEdit *creationDate = new QDateEdit();

        page->addWidget(new QLabel("Title"));
        page->addWidget(title);
        page->addWidget(new QLabel("Description"));
        page->addWidget(description);
        page->addWidget(new QLabel("Assignee"));
        page->addWidget(assignee);
        //page->addWidget(new QLabel("Creation Date")); //outo-assigned
        //page->addWidget(creationDate);
    }

}

void BlankPage::timedBase(bool isEditable){
    abstractBase(isEditable);

    if(isEditable){
        QDateEdit *startDate = new QDateEdit();
        QDateEdit *endDate = new QDateEdit();
        QLineEdit *starTime = new QLineEdit();
        QSpinBox *duration = new QSpinBox();

        page->addWidget(new QLabel("Start Date:"));
        page->addWidget(startDate);
        page->addWidget(new QLabel("End Date:"));
        page->addWidget(endDate);
        page->addWidget(new QLabel("Start Time:"));
        page->addWidget(starTime);
        page->addWidget(new QLabel("Duration"));
        page->addWidget(duration);
    }

}

void BlankPage::repeatableBase(bool isEditable){
    abstractBase(isEditable);

    if(isEditable){
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
    }

}

void BlankPage::deadlineBase(bool isEditable){
    abstractBase(isEditable);

    if(isEditable){
        QDateEdit *dueDate = new QDateEdit();
        QRadioButton *prio = new QRadioButton(); //list of Radio Buttons //SELECT SELECT BOX
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
    }

}

