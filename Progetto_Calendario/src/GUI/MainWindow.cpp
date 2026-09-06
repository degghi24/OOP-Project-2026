#include "MainWindow.h"
#include "AddTask/TypeSelectionPopup.h"
#include "AddTask/TaskCreationWindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include "../Model/Headers/TaskListManager.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    toolBar = new ToolBar(this);
    addToolBar(toolBar);
    connect(toolBar, &ToolBar::saveSignal, this, &MainWindow::saveToFile);
    connect(toolBar, &ToolBar::importSignal, this, &MainWindow::loadFromFile);

    splitter = new QSplitter(Qt::Horizontal);
    setCentralWidget(splitter);


    //////////Left: LIST
    taskListWindow = new TasksListWindow();
    splitter->addWidget(taskListWindow);
    connect(taskListWindow, &TasksListWindow::addRequest, this, &MainWindow::showTypeSelect);


    /////////Right: CALENDAR/DETAIL_WINDOW
    stackWindow = new StackedWindow();
    splitter->addWidget(stackWindow);
    connect(taskListWindow, &TasksListWindow::taskToShow, stackWindow, &StackedWindow::showDetailWindow);
    connect(stackWindow, &StackedWindow::unselectTaskBlock, taskListWindow->getTaskList(), &TasksList::unselect);
    connect(stackWindow, &StackedWindow::removeTask, taskListWindow->getTaskList(), &TasksList::removeTask);
    connect(stackWindow, &StackedWindow::removeTask, this, &MainWindow::removeTask);
    connect(stackWindow, &StackedWindow::selectedFilterDate, taskListWindow, &TasksListWindow::filterByCalendar);
    connect(stackWindow, &StackedWindow::updateTaskBlock, taskListWindow->getTaskList(), &TasksList::updateList);

    setMinimumSize(920,600);
}

void MainWindow::showTypeSelect(){
    TypeSelectionPopup *typePopup = new TypeSelectionPopup(this);
    typePopup->setAttribute(Qt::WA_DeleteOnClose, true);
    connect(typePopup, &TypeSelectionPopup::sendType, this, &MainWindow::showTaskCreation); //showTaskCreation(QString type)
    if (typePopup->exec() == QDialog::Accepted){
        qDebug()<<"Accepted";
        //connect(typePopup, &TypeSelectionPopup::createTaskSignal, TaskCreationWindowObject, &TaskCreationWindow::createTask);
    }
}

void MainWindow::showTaskCreation(QString type){
    TaskCreationWindow *creationWindow = new TaskCreationWindow(type, this);
    creationWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    connect(creationWindow, &TaskCreationWindow::sendTask, this, &MainWindow::addTask);
    creationWindow->exec();
}

void MainWindow::addTask(AbstractTask* task){
    TaskListManager::getInstance().addTask(task);
    /*for(auto it : TaskListManager::getInstance().getTaskList()){
        qDebug()<<it->getTitle()<<it->getId();
    }*/
    taskListWindow->addTask(task);
}

void MainWindow::removeTask(AbstractTask* taskToRemove){
    qDebug()<<taskToRemove->getId();
    TaskListManager::getInstance().removeTask(taskToRemove->getId());
}

void MainWindow::saveToFile(){
    QString file = QFileDialog::getSaveFileName(
        this,
        QString("Save To File"),
        QDir::homePath(),
        "Json Files (*.json);;XML Files (*.xml)");

    if (!file.isEmpty())
    {
        bool success = TaskListManager::getInstance().saveToFile(file);
        if (success){
            QMessageBox::information(this, "Success", "Content saved successfully");
        }
        else{
            QMessageBox::warning(this, "Error", "Failed to import content");
        }
    }
}

void MainWindow::loadFromFile(){
    QString file = QFileDialog::getOpenFileName(
        this,
        QString("Load From File"),
        QDir::homePath(),
        "Files (*.xml *.json)");

    if (!file.isEmpty())
    {
        bool success = TaskListManager::getInstance().loadFromFile(file);
        if (success){
            QMessageBox::information(this, "Success", "Content imported successfully");
            stackWindow->toHomePage();
            taskListWindow->clearTaskList();
            qDebug()<<TaskListManager::getInstance().getTaskList().size();
            for(auto it : TaskListManager::getInstance().getTaskList()){
                taskListWindow->addTask(it);
            }
        }
        else{
            QMessageBox::warning(this, "Error", "Failed to import content");
        }
    }
}

MainWindow::~MainWindow() {
    //delete TaskListManager::getInstance();
}
