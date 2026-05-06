#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include "ToolBar.h"
#include "TasksListWindow.h"
#include "StackedWindow.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSplitter       *splitter       = nullptr;
    ToolBar         *toolBar        = nullptr;

    //Leftside
    TasksListWindow *taskListWindow = nullptr;

    //Rightside
    StackedWindow *stackWindow = nullptr;
};

#endif // MAINWINDOW_H
