#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    toolBar = new ToolBar(this);
    addToolBar(toolBar);

    splitter = new QSplitter(Qt::Horizontal);
    setCentralWidget(splitter);

    //first half for the list
    taskListWindow = new TaskListWindow();
    splitter->addWidget(taskListWindow);

    //second half is for the calendar
    splitter->addWidget(calendar = new QCalendarWidget());


}

MainWindow::~MainWindow() {}
