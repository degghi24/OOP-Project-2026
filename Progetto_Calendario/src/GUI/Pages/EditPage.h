#ifndef EDITPAGE_H
#define EDITPAGE_H

#include "EditPages/ActivityEdit.h"
#include "EditPages/ReminderEdit.h"
#include "EditPages/WorkEdit.h"
#include "EditPages/BillEdit.h"
#include "EditPages/ProjectEdit.h"

#include <QWidget>
#include <QStackedLayout>

class EditPage:public QWidget{
    Q_OBJECT

private:

    QStackedLayout *layout = nullptr;

    void setUpActivityEdit();
    void setUpReminderEdit();
    void setUpBillEdit();
    void setUpProjectEdit();
    void setUpWorkEdit();

public slots:
    void confirmCreation();
    //void receiveTask(AbstractTask *task);

signals:
    void createTask();
    void sendTask(AbstractTask *task);

public:
    EditPage(QString type, QWidget *parent = nullptr);

    EditPage(Activity *Activity, QWidget *parent = nullptr);
    EditPage(Reminder *Reminder, QWidget *parent = nullptr);
    EditPage(Work *Work, QWidget *parent = nullptr);
    EditPage(Bill *Bill, QWidget *parent = nullptr);
    EditPage(Project *Project, QWidget *parent = nullptr);
};

#endif // EDITPAGEITPAGE_H
