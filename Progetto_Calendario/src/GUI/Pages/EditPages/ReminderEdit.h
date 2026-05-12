#ifndef REMINDEREDIT_H
#define REMINDEREDIT_H

#include "TimedEditPage.h"
#include "Model/Headers/Reminder.h"

#include <QWidget>
#include <QRadioButton>

class ReminderEdit: public TimedEditPage{
    Q_OBJECT

private:
    QLineEdit *notifyTime = nullptr;
    QLineEdit *alertMessage = nullptr;
    QRadioButton *snoozed = nullptr;
    QSpinBox *snoozeMinute = nullptr;

    void setUp();

public:
    ReminderEdit(Reminder *task, QWidget *parent = nullptr);
    ReminderEdit(QWidget *parent = nullptr);
};

#endif // REMINDEREDIT_H
