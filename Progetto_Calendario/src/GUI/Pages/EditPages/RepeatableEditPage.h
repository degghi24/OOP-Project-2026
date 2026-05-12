#ifndef REPEATABLEEDITPAGE_H
#define REPEATABLEEDITPAGE_H

#include "AbstractEditPage.h"
#include "Model/Headers/RepeatableTask.h"

#include <QWidget>
#include <QCheckBox>
#include <QSpinBox>
#include <QDateEdit>

class RepeatableEditPage: public AbstractEditPage{
    Q_OBJECT

private:

    QCheckBox *monday = nullptr;
    QCheckBox *tuesday = nullptr;
    QCheckBox *wednesday = nullptr;
    QCheckBox *thursday = nullptr;
    QCheckBox *friday = nullptr;
    QCheckBox *saturday = nullptr;
    QCheckBox *sunday = nullptr;

    QSpinBox *intervalDays = nullptr;
    QDateEdit *endDate = nullptr;
    QCheckBox *active = nullptr;

    void setUp();



public:
    RepeatableEditPage(RepeatableTask *task, QWidget *parent = nullptr);
    RepeatableEditPage(QWidget *parent = nullptr);
};

#endif // REPEATABLEEDITPAGE_H
