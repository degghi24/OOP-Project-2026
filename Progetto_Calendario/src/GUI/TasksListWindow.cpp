#include "TasksListWindow.h"

#include <QStyle>

TasksListWindow::TasksListWindow(QWidget *parent): QWidget(parent){
    setupUI();

}

void TasksListWindow::setupUI(){
    mainFrame = new QGridLayout(this);
    mainFrame->setAlignment(Qt::AlignTop);

    //Search Bar
    searchBar = new QLineEdit();
    //Filter Button
    filterButton = new QPushButton();
    filterButton->setCursor(Qt::PointingHandCursor);
    filterButton->setMaximumSize(50,filterButton->height());
    filterButton->setMinimumWidth(50);
    filterButton->setText("Filter");
    connect(filterButton, &QPushButton::clicked, this, &TasksListWindow::toggleFilter);


    //TaskList
    taskListContainer = new TasksList();
    //FilterWindow
    filterWindow = new FilterWindow();
    filterWindow->setVisible(false);

    mainFrame->addWidget(searchBar,1,1,1,2);
    mainFrame->addWidget(filterButton,1,3,1,1);
    mainFrame->addWidget(filterWindow,2,1,1,3);
    mainFrame->addWidget(taskListContainer,3,1,1,3);

    setMinimumWidth(310);
    setMaximumWidth(500);


}

void TasksListWindow::toggleFilter(){
    if(filterWindow->isVisible()){
        filterWindow->setVisible(false);
    }else{
        filterWindow->setVisible(true);
    }
}


TasksListWindow::~TasksListWindow() {};
