#ifndef DETAILPAGE_H
#define DETAILPAGE_H

#include "../../Model/Headers/Activity.h"
#include "../../Model/Headers/Reminder.h"
#include "../../Model/Headers/Work.h"
#include "../../Model/Headers/Bill.h"
#include "../../Model/Headers/Project.h"

#include <QWidget>
#include <QVBoxLayout>

class DetailPage: public QWidget{
    Q_OBJECT

private:
    QStringList list{"Activity","Reminder","Bill","Project","Work"};

    void abstractBase(AbstractTask *task = nullptr);
    void timedBase(TimedTask *task = nullptr);
    void repeatableBase(RepeatableTask *task = nullptr);
    void deadlineBase(Deadline *task = nullptr);

    QVBoxLayout *page = nullptr;


public:
    DetailPage(Activity *Activity, QWidget *parent = nullptr);
    DetailPage(Reminder *Reminder, QWidget *parent = nullptr);
    DetailPage(Work *Work, QWidget *parent = nullptr);
    DetailPage(Bill *Bill, QWidget *parent = nullptr);
    DetailPage(Project *Project, QWidget *parent = nullptr);
};

#endif // DETAILPAGE_H
