#include "TasksListWindow.h"

#include <QStyle>
#include <QSizePolicy>
#include <QCalendar>


TasksListWindow::TasksListWindow(QWidget *parent): QWidget(parent){
    setupUI();

}

void TasksListWindow::setupUI(){

    mainGrid = new QGridLayout(this);
    mainGrid->setAlignment(Qt::AlignTop);

    //Search Bar
    searchBar = new QLineEdit();

    //TaskList
    taskListContainer = new TasksList();
    connect(taskListContainer, &TasksList::taskToShow, this, &TasksListWindow::taskToShow);

    //scrollArea
    scrollArea = new QScrollArea(this);
    scrollArea->setWidget(taskListContainer);
    scrollArea->setWidgetResizable(true);

    //Search Button
    searchButton = new QPushButton();
    searchButton->setCursor(Qt::PointingHandCursor);
    searchButton->setMaximumSize(50,searchButton->height());
    searchButton->setMinimumWidth(50);
    searchButton->setText("Search");
    connect(searchButton, &QPushButton::clicked, this, &TasksListWindow::search);
    connect(this, &TasksListWindow::sendFilterValues, taskListContainer, &TasksList::filter);


    //Filter Button
    filterButton = new QPushButton();
    filterButton->setCursor(Qt::PointingHandCursor);
    filterButton->setMaximumSize(50,filterButton->height());
    filterButton->setMinimumWidth(50);
    filterButton->setText("Filter");
    connect(filterButton, &QPushButton::clicked, this, &TasksListWindow::toggleFilter);


    //FilterWindow
    filterWindow = new FilterWindow();
    filterWindow->setVisible(false);

    //Add Button
    QPushButton *addButton = new QPushButton("Add");
    connect(addButton, &QPushButton::clicked, this, &TasksListWindow::addRequest);

    mainGrid->addWidget(searchBar,0,0,1,2);
    mainGrid->addWidget(searchButton,0,1,1,1);
    mainGrid->addWidget(filterButton,0,2,1,1);
    mainGrid->addWidget(filterWindow,1,0,1,3);
    mainGrid->addWidget(scrollArea,2,0,1,3);
    mainGrid->addWidget(addButton,3,0,1,3);

    setMinimumWidth(330);
    setMaximumWidth(500);

}

void TasksListWindow::addTask(AbstractTask* task){
    taskListContainer->addTask(task);
}

void TasksListWindow::clearTaskList(){
    taskListContainer->unselect();
    taskListContainer->getList().clear();
    QLayoutItem *child;
    while ((child = taskListContainer->getLayout()->takeAt(0)) != nullptr) {
        delete child->widget(); // delete the widget
        delete child;   // delete the layout item
    }
}

void TasksListWindow::toggleFilter(){
    if(filterWindow->isVisible()){
        filterWindow->setVisible(false);
    }else{
        filterWindow->setVisible(true);
    }
}

void TasksListWindow::search(){
    emit sendFilterValues(getFilterValues());
}

void TasksListWindow::filterByCalendar(QDate newDate){
    filterWindow->setStartDate(newDate);
    search();
}

Filter TasksListWindow::getFilterValues(){
    Filter filterValues = {
        searchBar->text(),
        filterWindow->getStartDate(),
        filterWindow->getEndDate(),
        filterWindow->getType()};
    return filterValues;
}

TasksList* TasksListWindow::getTaskList(){
    return taskListContainer;
}


TasksListWindow::~TasksListWindow() {
    clearTaskList();
};
