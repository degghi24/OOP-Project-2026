#ifndef TASKLISTWINDOW_H
#define TASKLISTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>

class TaskListWindow: public QWidget{
    Q_OBJECT

signals:
    //search
    //filterEdit

public:
    TaskListWindow(QWidget *parent = nullptr);
    ~TaskListWindow();

private:

    //main frame of the widget
    QGridLayout *mainFrame = nullptr;

    //search bar
    QLineEdit *searchBar = nullptr;
    //filter button, shows the filter window
    QPushButton *filterButton = nullptr;

    //vertical box with tasks
    QVBoxLayout *taskListContainer = nullptr;

    void setupUI();
};

#endif
