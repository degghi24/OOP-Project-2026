#ifndef TASKEDITWINDOW_H
#define TASKEDITWINDOW_H

#include "../GUI/GuiVisitors/EditVisitor.h"
#include "../Model/Headers/AbstractTask.h"

#include <QWidget>
#include <QPushButton>
#include <QScrollArea>

class TaskEditWindow: public QFrame{
    Q_OBJECT

private:
    AbstractTask *savedTask = nullptr;

    EditVisitor visitor;

    QFrame *frame = nullptr;
    QVBoxLayout *mainLayout = nullptr;
    QScrollArea *editScrollArea = nullptr;

    QHBoxLayout *lineForButtons = nullptr;

    void editButtonLine();

    void confirmSave();
    void confirmReset();

signals:
    void emitClose();
    void signalSave();
    void updateDetail(AbstractTask* taskToUpdate);

public slots:
    void showTask(AbstractTask* task);

public:
    TaskEditWindow(QWidget *parent = nullptr);
};

#endif // TASKEDITWINDOW_H
