#ifndef DEADLINEEDITPAGE_H
#define DEADLINEEDITPAGE_H

#include "AbstractEditPage.h"
#include "Model/Headers/Deadline.h"

#include <QWidget>
#include <QDateEdit>
#include <QComboBox>
#include <QRadioButton>

class DeadlineEditPage: public AbstractEditPage{
    Q_OBJECT

private:
    QDateEdit *dueDate = nullptr;
    QComboBox *prio = nullptr;
    QRadioButton *completed = nullptr;
    QRadioButton *skipped = nullptr;

    void setUp();

public:
    DeadlineEditPage(Deadline *task, QWidget *parent = nullptr);
    DeadlineEditPage(QWidget *parent = nullptr);

};

#endif // DEADLINEEDITPAGE_H
