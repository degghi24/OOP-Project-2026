#ifndef TIMEDEDITPAGE_H
#define TIMEDEDITPAGE_H

#include "AbstractEditPage.h"
#include "Model/Headers/TimedTask.h"

#include <QDateEdit>
#include <QTimeEdit>
#include <QSpinBox>

class TimedEditPage: public AbstractEditPage{
    Q_OBJECT

private:

    QDateEdit *startDate = nullptr;
    QDateEdit *endDate = nullptr;
    QTimeEdit *starTime = nullptr;
    QSpinBox *duration = nullptr;

    void setUp();


protected:

public:

    std::string getStartDate() const;
    std::string getEndDate() const;
    std::string getStartTime() const;
    int getDuration() const;

    TimedEditPage(TimedTask *task, QWidget *parent = nullptr);
    TimedEditPage(QWidget *parent = nullptr);
};

#endif // TIMEDEDITPAGE_H
