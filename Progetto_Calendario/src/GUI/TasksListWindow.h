#ifndef TASKSLISTWINDOW_H
#define TASKSLISTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>

#include "TasksList.h"
#include "FilterWindow.h"

class TasksListWindow: public QWidget{
    Q_OBJECT

signals:
    //search
    //filterEdit

private slots:
    //show/hide filter
    void toggleFilter();


public:
    TasksListWindow(QWidget *parent = nullptr);
    ~TasksListWindow();

private:

    //main frame of the widget
    QGridLayout *mainFrame = nullptr;

    //search bar
    QLineEdit *searchBar = nullptr;
    //filter button, shows the filter window
    QPushButton *filterButton = nullptr;
    //filter window
    FilterWindow *filterWindow = nullptr;

    //vertical box with tasks
    TasksList *taskListContainer = nullptr;

    void setupUI();
};

#endif
