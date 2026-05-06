#ifndef EDITPAGE_H
#define EDITPAGE_H

#include "../../Model/Headers/Activity.h"
#include "../../Model/Headers/Reminder.h"
#include "../../Model/Headers/Work.h"
#include "../../Model/Headers/Bill.h"
#include "../../Model/Headers/Project.h"

#include <QWidget>
#include <QVBoxLayout>

class EditPage:public QWidget{
    Q_OBJECT

private:
    QStringList list{"Activity","Reminder","Bill","Project","Work"};

    void setUp(QString type);

    void abstractBase(AbstractTask *task = nullptr);
    void timedBase(TimedTask *task = nullptr);
    void repeatableBase(RepeatableTask *task = nullptr);
    void deadlineBase(Deadline *task = nullptr);

    QVBoxLayout *page = nullptr;


public:
    EditPage(QString type, QWidget *parent = nullptr);
    EditPage(Activity *Activity, QWidget *parent = nullptr);
    EditPage(Reminder *Reminder, QWidget *parent = nullptr);
    EditPage(Work *Work, QWidget *parent = nullptr);
    EditPage(Bill *Bill, QWidget *parent = nullptr);
    EditPage(Project *Project, QWidget *parent = nullptr);
};

#endif // EDITPAGEITPAGE_H
