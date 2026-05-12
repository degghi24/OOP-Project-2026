#ifndef WORKEDIT_H
#define WORKEDIT_H

#include "RepeatableEditPage.h"
#include "Model/Headers/Work.h"

#include <QWidget>

class WorkEdit: public RepeatableEditPage{
    Q_OBJECT

private:
    QLineEdit *subTaskToAdd = nullptr;
    QSpinBox *progress = nullptr;
    QLineEdit *client = nullptr;
    QLineEdit *category = nullptr;
    QLineEdit *notes = nullptr;

    void setUp();

public:
    WorkEdit(Work *task, QWidget *parent = nullptr);
    WorkEdit(QWidget *parent = nullptr);
};

#endif // WORKEDIT_H
