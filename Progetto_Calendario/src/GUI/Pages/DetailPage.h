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

    void abstractBase(const AbstractTask *task = nullptr);
    void timedBase(const  TimedTask *task = nullptr);
    void repeatableBase(const RepeatableTask *task = nullptr);
    void deadlineBase(const Deadline *task = nullptr);

    QVBoxLayout *page = nullptr;


public:
    DetailPage(const Activity *Activity, QWidget *parent = nullptr);
    DetailPage(const Reminder *Reminder, QWidget *parent = nullptr);
    DetailPage(const Work *Work, QWidget *parent = nullptr);
    DetailPage(const Bill *Bill, QWidget *parent = nullptr);
    DetailPage(const Project *Project, QWidget *parent = nullptr);
};

#endif // DETAILPAGE_H
