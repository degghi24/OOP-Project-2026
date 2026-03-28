#include "TaskListWindow.h"

#include <QStyle>

TaskListWindow::TaskListWindow(QWidget *parent): QWidget(parent){

    setupUI();

}

void TaskListWindow::setupUI(){
    mainFrame = new QGridLayout(this);
    mainFrame->setAlignment(Qt::AlignTop);

    searchBar = new QLineEdit();

    filterButton = new QPushButton();
    filterButton->setCursor(Qt::PointingHandCursor);
    filterButton->setMaximumSize(50,filterButton->height());
    filterButton->setMinimumWidth(50);
    filterButton->setText("Filter");


    taskListContainer = new QVBoxLayout();

    mainFrame->addWidget(searchBar,1,1,1,2);
    mainFrame->addWidget(filterButton,1,3,1,1);

    mainFrame->addLayout(taskListContainer,2,1,1,3);
    setMinimumWidth(250);
    setMaximumWidth(500);
}

TaskListWindow::~TaskListWindow() {};
