#ifndef PROJECTEDIT_H
#define PROJECTEDIT_H

#include "DeadlineEditPage.h"
#include "Model/Headers/Project.h"

#include <QWidget>
#include <QSpinBox>

class ProjectEdit: public DeadlineEditPage{
    Q_OBJECT

private:
    QLineEdit *milestone = nullptr;
    QLineEdit *team = nullptr;
    QSpinBox *budget = nullptr;
    QLineEdit *status = nullptr;
    QLineEdit *tags = nullptr;

    void setUp();

public:
    ProjectEdit(Project *task, QWidget *parent = nullptr);
    ProjectEdit(QWidget *parent = nullptr);
};

#endif // PROJECTEDIT_H
