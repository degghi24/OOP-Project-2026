#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QSplitter>
#include "ToolBar.h"
#include "TasksListWindow.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    TasksListWindow *taskListWindow = nullptr;
    QCalendarWidget *calendar       = nullptr;
    ToolBar         *toolBar        = nullptr;
    QSplitter       *splitter       = nullptr;
};

#endif // MAINWINDOW_H
