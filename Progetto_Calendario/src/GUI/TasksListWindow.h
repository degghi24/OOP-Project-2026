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
    //send filter to TaskList
    void sendFilterValues(Filter filterValues);
    //filterEdit

private slots:
    //show/hide filter
    void toggleFilter();
    //initiate search
    void search();


public:
    TasksListWindow(QWidget *parent = nullptr);
    ~TasksListWindow();

private:

    //main frame of the widget
    QGridLayout *mainFrame = nullptr;

    //search bar
    QLineEdit *searchBar = nullptr;
    //search button
    QPushButton *searchButton = nullptr;
    //filter button, shows the filter window
    QPushButton *filterButton = nullptr;
    //filter window
    FilterWindow *filterWindow = nullptr;

    //vertical box with tasks
    QScrollArea *scrollArea = nullptr;
    TasksList *taskListContainer = nullptr;

    void setupUI();

    Filter getFilterValues();
};

#endif
