#ifndef TASKDETAILWINDOW_H
#define TASKDETAILWINDOW_H

#include "../GUI/GuiVisitors/DetailVisitor.h"
#include "../Model/Headers/AbstractTask.h"

#include <QWidget>
#include <QPushButton>
#include <QScrollArea>


class TaskDetailWindow: public QFrame{
    Q_OBJECT

private:
    DetailVisitor visitor;

    AbstractTask* savedTask = nullptr;

    QVBoxLayout *mainLayout = nullptr;
    QScrollArea *detailScrollArea = nullptr;

    QHBoxLayout *lineForButtons = nullptr;

    void detailButtonLine();

    void showEditWindow();

    void confirmRemove();

signals:
    void emitClose();
    void removeTask(AbstractTask* task);
    void editTask(AbstractTask* task);

public slots:
    void showTask(AbstractTask* task);

public:
    TaskDetailWindow(QWidget *parent = nullptr);
};

#endif // TASKDETAILWINDOW_H
