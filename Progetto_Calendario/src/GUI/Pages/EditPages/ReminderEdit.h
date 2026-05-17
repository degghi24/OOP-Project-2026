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

public slots:
    void createTask();

signals:
    void returnTask(Reminder *task);

public:
    std::string getNotifyTime() const;
    std::string getalertMessage() const;
    bool isSnoozed() const;
    int getSnoozeMinute() const;

    ReminderEdit(Reminder *task, QWidget *parent = nullptr);
    ReminderEdit(QWidget *parent = nullptr);
};

#endif // REMINDEREDIT_H
