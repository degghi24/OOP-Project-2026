#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QSplitter>
#include "ToolBar.h"
#include "TaskListWindow.h"
#include "src/Model/Headers/Calendar.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    TaskListWindow  *taskListWindow = nullptr;
    QCalendarWidget *calendar       = nullptr;
    ToolBar         *toolBar        = nullptr;
    QSplitter       *splitter       = nullptr;
};

#endif // MAINWINDOW_H