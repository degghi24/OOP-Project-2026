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
    stackWindow = new StackedWindow();
    splitter->addWidget(stackWindow);

    setMinimumSize(920,600);
}

MainWindow::~MainWindow() {
    //delete TaskListManager::getInstance();
}
