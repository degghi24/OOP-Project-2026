#ifndef WORKEDIT_H
#define WORKEDIT_H

#include "RepeatableEditPage.h"
#include "Model/Headers/Work.h"

#include <QWidget>

class WorkEdit: public RepeatableEditPage{
    Q_OBJECT

private:
    QVBoxLayout *subTasksScrollAreaLayout = nullptr;
    QLineEdit *subTaskToAdd = nullptr;
    QSpinBox *progress = nullptr;
    QLineEdit *client = nullptr;
    QLineEdit *category = nullptr;
    QLineEdit *notes = nullptr;

    void setUp();

private slots:
    void addSubTask();

public slots:
    void createTask();

signals:
    void returnTask(Work *task);

public:
    QStringList getSubTasks();
    int getProgress() const;
    std::string getClient() const;
    std::string getCategory() const;
    std::string getNotes() const;

    WorkEdit(Work *task, QWidget *parent = nullptr);
    WorkEdit(QWidget *parent = nullptr);
};

#endif // WORKEDIT_H
