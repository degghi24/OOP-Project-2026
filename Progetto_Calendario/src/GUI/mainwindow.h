#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QSplitter>

#include "ToolBar.h"
#include "TaskListWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    //List of activity sort by next closest in time
    TaskListWindow *taskListWindow = nullptr;

    //Calendar
    QCalendarWidget *calendar = nullptr;

    //Tool Bar for save and import
    ToolBar *toolBar = nullptr;

    //Split window in 2
    QSplitter *splitter = nullptr;

};
#endif // MAINWINDOW_H
