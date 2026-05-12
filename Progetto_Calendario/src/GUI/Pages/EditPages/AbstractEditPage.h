#ifndef ABSTRACTEDITPAGE_H
#define ABSTRACTEDITPAGE_H

#include "Model/Headers/AbstractTask.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>

class AbstractEditPage: public QWidget{
    Q_OBJECT

private:

    QLineEdit *title = nullptr;
    QTextEdit *description = nullptr;
    QLineEdit *assignee = nullptr;

protected:

    QVBoxLayout *page = nullptr;

    //ID is auto assigned by the listManager
    //QDateEdit *creationDate = new QDateEdit();

public:
    AbstractEditPage(AbstractTask *task, QWidget *parent = nullptr);
    AbstractEditPage(QWidget *parent = nullptr);
};

#endif // ABSTRACTEDITPAGE_H
