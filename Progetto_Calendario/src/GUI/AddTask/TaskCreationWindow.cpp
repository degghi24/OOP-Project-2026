#include "TaskCreationWindow.h"

#include <QDialogButtonBox>
#include <QGridLayout>

TaskCreationWindow::TaskCreationWindow(QWidget *parent): QDialog(parent) {}

TaskCreationWindow::TaskCreationWindow(QString type, QWidget *parent): QDialog(parent){
    setWindowTitle(type);
    resize(350,700);

    QGridLayout *grid = new QGridLayout(this);

    grid->addWidget(form = new EditPage(type));

    QDialogButtonBox *dialogButton = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,this);
    dialogButton->setCenterButtons(true);

    connect(dialogButton, &QDialogButtonBox::accepted, this, &TaskCreationWindow::accept);
    connect(dialogButton, &QDialogButtonBox::accepted, form, &EditPage::confirmCreation);
    connect(form, &EditPage::sendTask, this, &TaskCreationWindow::sendTask);
    connect(dialogButton, &QDialogButtonBox::rejected, this, &QDialog::reject);

    grid->addWidget(dialogButton);
}
