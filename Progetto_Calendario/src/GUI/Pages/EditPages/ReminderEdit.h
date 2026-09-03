#ifndef REMINDEREDIT_H
#define REMINDEREDIT_H

#include "TimedEditPage.h"
#include "../../../Model/Headers/Reminder.h"

#include <QWidget>
#include <QRadioButton>

class ReminderEdit: public TimedEditPage{
    Q_OBJECT

private:
    Reminder *savedReminder = nullptr;

    QLineEdit *notifyTime = nullptr;
    QLineEdit *alertMessage = nullptr;
    QRadioButton *snoozed = nullptr;
    QSpinBox *snoozeMinute = nullptr;

    void setUp();

public slots:
    void createTask();
    void saveEdit();

signals:
    void returnTask(Reminder *task);

public:
    QString getNotifyTime() const;
    QString getalertMessage() const;
    bool isSnoozed() const;
    int getSnoozeMinute() const;

    ReminderEdit(Reminder *task, QWidget *parent = nullptr);
    ReminderEdit(QWidget *parent = nullptr);
};

#endif // REMINDEREDIT_H
