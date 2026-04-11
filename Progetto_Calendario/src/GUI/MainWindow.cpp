#include "MainWindow.h"
#include "../Model/Headers/TaskListManager.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    toolBar = new ToolBar(this);
    addToolBar(toolBar);

    splitter = new QSplitter(Qt::Horizontal);
    setCentralWidget(splitter);


    //////////Left: LIST
    taskListWindow = new TasksListWindow();
    splitter->addWidget(taskListWindow);


    /////////Right: CALENDAR/DETAIL_WINDOW
    splitter->addWidget(calendar = new QCalendarWidget());
}

MainWindow::~MainWindow() {
    //delete TaskListManager::getInstance();
}
