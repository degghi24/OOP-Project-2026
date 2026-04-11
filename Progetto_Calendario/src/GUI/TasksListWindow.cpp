#include "TasksListWindow.h"

#include <QStyle>

TasksListWindow::TasksListWindow(QWidget *parent): QWidget(parent){
    setupUI();

}

void TasksListWindow::setupUI(){
    mainFrame = new QGridLayout(this);
    mainFrame->setAlignment(Qt::AlignTop);

    searchBar = new QLineEdit();

    filterButton = new QPushButton();
    filterButton->setCursor(Qt::PointingHandCursor);
    filterButton->setMaximumSize(50,filterButton->height());
    filterButton->setMinimumWidth(50);
    filterButton->setText("Filter");


    //TaskList
    taskListContainer = new TasksList();

    mainFrame->addWidget(searchBar,1,1,1,2);
    mainFrame->addWidget(filterButton,1,3,1,1);

    mainFrame->addWidget(taskListContainer,2,1,1,3);
    setMinimumWidth(250);
    setMaximumWidth(500);
}

TasksListWindow::~TasksListWindow() {};
