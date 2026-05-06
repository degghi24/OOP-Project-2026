#ifndef TASKCREATIONWINDOW_H
#define TASKCREATIONWINDOW_H

#include <QDialog>

#include "../Pages/EditPage.h"

class TaskCreationWindow:public QDialog{
    Q_OBJECT

private:

    EditPage *form = nullptr;

public:
    TaskCreationWindow(QWidget *parent = nullptr);
    TaskCreationWindow(QString type, QWidget *parent = nullptr);
};

#endif // TASKCREATIONWINDOW_H
