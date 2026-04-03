#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    Calendar::getInstance();

    toolBar = new ToolBar(this);
    addToolBar(toolBar);

    splitter = new QSplitter(Qt::Horizontal);
    setCentralWidget(splitter);

    taskListWindow = new TaskListWindow();
    splitter->addWidget(taskListWindow);

    splitter->addWidget(calendar = new QCalendarWidget());
}

MainWindow::~MainWindow() {
    delete Calendar::getInstance();
}