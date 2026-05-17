#ifndef TASKBLOCK_H
#define TASKBLOCK_H

#include "Model/Headers/AbstractTask.h"
#include <QWidget>
#include <QLabel>
#include <QDate>
#include <QComboBox>

using namespace std;

class TaskBlock:public QWidget{
    Q_OBJECT

private:

    QFrame *block = nullptr;
    QLabel *title = nullptr;
    QDate *startDate = nullptr;
    QDate *endDate = nullptr;
    QComboBox *type = nullptr;


public:

    QDate getStartDate() const;
    QDate getEndDate() const;
    QString getTitle() const;
    int getType() const;

    void setStartDate(QString &sDate);
    void setEndDate(QString &eDate);
    void setTitle(QString &titleS);
    void setType(QString &typeS);

    TaskBlock(QWidget *parent = nullptr);
    TaskBlock(QString *title_, QDate *startDate_, int *type_, QDate *eDate = nullptr);
    TaskBlock(AbstractTask &task);
};

#endif // TASKBLOCK_H
