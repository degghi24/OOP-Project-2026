#include "ReminderEdit.h"

ReminderEdit::ReminderEdit(Reminder *task, QWidget *parent): TimedEditPage(task, parent) {

    savedReminder = task;

    setUp();

    if(task){
        notifyTime->setText(task->getNotifyTime());
        alertMessage->setText(task->getAlertMessage());
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
    QHBoxLayout *line = new QHBoxLayout();
    line->setAlignment(Qt::AlignLeft);
    line->addWidget(new QLabel("Is Snoozed:"));
    line->addWidget(snoozed);
    page->addLayout(line);
    page->addWidget(new QLabel("Minute Before Time:"));
    page->addWidget(snoozeMinute);

}

QString ReminderEdit::getNotifyTime() const{
    return notifyTime->text();
}
QString ReminderEdit::getalertMessage() const{
    return alertMessage->text();
}
bool ReminderEdit::isSnoozed() const{
    return snoozed->isChecked();
}
int ReminderEdit::getSnoozeMinute() const{
    return snoozeMinute->value();
}

void ReminderEdit::createTask(){
    Reminder *newReminder = new Reminder(getTitle(),getDescription(),getAssignee(), QDate::currentDate(),
                                         getStartDate(),getEndDate(),getStartTime(),getDuration(),
                                         getNotifyTime(),getalertMessage(),isSnoozed(),getSnoozeMinute());
    emit returnTask(newReminder);
}

void ReminderEdit::saveEdit(){
    savedReminder->setTitle(getTitle());
    savedReminder->setDescription(getDescription());
    savedReminder->setAssignee(getAssignee());
    savedReminder->setStartDate(getStartDate());
    savedReminder->setEndDate(getEndDate());
    savedReminder->setStartTime(getStartTime());
    savedReminder->setDuration(getDuration());
    savedReminder->setNotifyTime(getNotifyTime());
    savedReminder->setAlertMessage(getalertMessage());
    savedReminder->setSnoozed(isSnoozed());
    savedReminder->setSnoozeMinutes(getSnoozeMinute());
}
