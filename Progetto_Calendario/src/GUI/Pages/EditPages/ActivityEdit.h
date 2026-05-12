#ifndef ACTIVITYEDIT_H
#define ACTIVITYEDIT_H

#include "TimedEditPage.h"
#include "Model/Headers/Activity.h"

#include <QWidget>
#include <QCheckBox>

class ActivityEdit: public TimedEditPage{
    Q_OBJECT

private:
    QLineEdit *location = nullptr;
    QSpinBox *partecipationCount = nullptr;
    QLineEdit *eventType = nullptr;
    QCheckBox *isOnline = nullptr;
    QLineEdit *meetingLink = nullptr;

    void setUp();

public:
    ActivityEdit(Activity *task, QWidget *parent = nullptr);
    ActivityEdit(QWidget *parent = nullptr);
};

#endif // ACTIVITYEDIT_H
