#ifndef TASKBLOCK_H
#define TASKBLOCK_H

#include <QWidget>
#include <QLabel>

using namespace std;

class TaskBlock:public QWidget{
    Q_OBJECT

private:
    QLabel *startDate;
    QLabel *endDate = nullptr;
    QLabel *title;
    QLabel *type;


public:

    QString getStartDate();
    QString getEndDate();
    QString getTitle();
    QString getType();
    TaskBlock();
    TaskBlock(QString sDate, QString t, QString tp, QString eDate = nullptr);
};

#endif // TASKBLOCK_H
