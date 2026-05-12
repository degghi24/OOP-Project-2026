#include "ReminderEdit.h"

ReminderEdit::ReminderEdit(Reminder *task, QWidget *parent): TimedEditPage(task, parent) {
    setUp();

    if(task){
        notifyTime->setText(task->getNotifyTime().c_str());
        alertMessage->setText(task->getAlertMessage().c_str());
        snoozed->setChecked(task->isSnoozed());
        snoozeMinute->setValue(task->getSnoozeMinutes());
    }

}

ReminderEdit::ReminderEdit(QWidget *parent): TimedEditPage(parent) {
    setUp();
}

void ReminderEdit::setUp(){

    notifyTime = new QLineEdit();
    alertMessage = new QLineEdit();
    snoozed = new QRadioButton();
    snoozeMinute = new QSpinBox();

    page->addWidget(new QLabel("Time of Notificatoin:"));
    page->addWidget(notifyTime);
    page->addWidget(new QLabel("Alert Message:"));
    page->addWidget(alertMessage);
    page->addWidget(new QLabel("Is Snoozed:"));
    page->addWidget(snoozed);
    page->addWidget(new QLabel("Minute Before Time:"));
    page->addWidget(snoozeMinute);

}
