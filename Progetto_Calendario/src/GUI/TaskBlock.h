#ifndef TASKBLOCK_H
#define TASKBLOCK_H

#include <QWidget>
#include <QLabel>

using namespace std;

class TaskBlock:public QWidget{
    Q_OBJECT

private:

    QFrame *block = nullptr;
    QLabel *startDate = nullptr;
    QLabel *endDate = nullptr;
    QLabel *title = nullptr;
    QLabel *type = nullptr;


public:

    QString getStartDate() const;
    QString getEndDate() const;
    QString getTitle() const;
    QString getType() const;

    void setStartDate(QString sDate);
    void setEndDate(QString eDate);
    void setTitle(QString titleS);
    void setType(QString typeS);

    TaskBlock(QWidget *parent = nullptr);
    TaskBlock(QString sDate, QString t, QString tp, QString eDate = nullptr);
};

#endif // TASKBLOCK_H
