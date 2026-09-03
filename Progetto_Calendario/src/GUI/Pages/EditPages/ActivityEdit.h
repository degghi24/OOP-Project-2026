#ifndef ACTIVITYEDIT_H
#define ACTIVITYEDIT_H

#include "TimedEditPage.h"
#include "../../../Model/Headers/Activity.h"

#include <QWidget>
#include <QCheckBox>

class ActivityEdit: public TimedEditPage{
    Q_OBJECT

private:

    Activity *savedActivity = nullptr;

    QLineEdit *location = nullptr;
    QSpinBox *partecipationCount = nullptr;
    QLineEdit *eventType = nullptr;
    QCheckBox *online = nullptr;
    QLineEdit *meetingLink = nullptr;

    void setUp();

public slots:
    void createTask();
    void saveEdit();

signals:
    void returnTask(Activity *task);

public:
    QString getLocation() const;
    int getPartecipationCount() const;
    QString getEventType() const;
    bool isOnline() const;
    QString getMeetingLink() const;

    ActivityEdit(Activity *task, QWidget *parent = nullptr);
    ActivityEdit(QWidget *parent = nullptr);
};

#endif // ACTIVITYEDIT_H
