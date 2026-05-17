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
    QCheckBox *online = nullptr;
    QLineEdit *meetingLink = nullptr;

    void setUp();

public slots:
    void createTask();

signals:
    void returnTask(Activity *task);

public:
    std::string getLocation() const;
    int getPartecipationCount() const;
    std::string getEventType() const;
    bool isOnline() const;
    std::string getMeetingLink() const;

    ActivityEdit(Activity *task, QWidget *parent = nullptr);
    ActivityEdit(QWidget *parent = nullptr);
};

#endif // ACTIVITYEDIT_H
