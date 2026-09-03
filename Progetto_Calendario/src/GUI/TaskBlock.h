#ifndef TASKBLOCK_H
#define TASKBLOCK_H

#include "../Model/Headers/Activity.h"
#include "../Model/Headers/Reminder.h"
#include "../Model/Headers/Work.h"
#include "../Model/Headers/Bill.h"
#include "../Model/Headers/Project.h"

#include <QWidget>
#include <QLabel>
#include <QDate>
#include <QComboBox>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QElapsedTimer>

using namespace std;

class TaskBlock:public QWidget{
    Q_OBJECT

private:

    QVBoxLayout *outerBox = nullptr;
    QFrame *block = nullptr;

    AbstractTask* taskStored;

    QLabel *title = nullptr;
    QDate *startDate = nullptr;
    QDate *endDate = nullptr;
    //per type si userà typeId siccome è soltanto grafico e non logico
    QLabel *type = nullptr;

    void setUp();

    void deleteThis();

protected:
    //virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;


signals:
    //void clicked(TaskBlock* taskBlock);
    void doubleClicked(TaskBlock* taskBlock);
    void doubleClicked(AbstractTask* taskStored);

public:

    QDate* getStartDate() const;
    QDate* getEndDate() const;
    QString getTitle() const;
    int extracted() const;
    int getType() const;

    AbstractTask* getSavedTask();

    void selected();
    void unselected();

    TaskBlock(Activity *task);
    TaskBlock(Reminder *task);
    TaskBlock(Work *task);
    TaskBlock(Bill *task);
    TaskBlock(Project *task);
};

#endif // TASKBLOCK_H
