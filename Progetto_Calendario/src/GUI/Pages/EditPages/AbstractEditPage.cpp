#include "AbstractEditPage.h"

AbstractEditPage::AbstractEditPage(AbstractTask *task, QWidget *parent):QWidget(parent), page(new QVBoxLayout(this)){

    title = new QLineEdit(task->getTitle().c_str());
    description = new QTextEdit(task->getDescription().c_str());
    assignee = new QLineEdit(task->getAssignee().c_str());
    //QDateEdit *creationDate = new QDateEdit();

    page->addWidget(new QLabel("Title"));
    page->addWidget(title);
    page->addWidget(new QLabel("Description"));
    page->addWidget(description);
    QHBoxLayout *line = new QHBoxLayout();
    line->addWidget(new QLabel("Assignee"));
    line->addWidget(assignee);
    page->addLayout(line);
}

AbstractEditPage::AbstractEditPage(QWidget *parent):QWidget(parent), page(new QVBoxLayout(this)){

    title = new QLineEdit();
    description = new QTextEdit();
    assignee = new QLineEdit();
    //QDateEdit *creationDate = new QDateEdit();

    page->addWidget(new QLabel("Title"));
    page->addWidget(title);
    page->addWidget(new QLabel("Description"));
    page->addWidget(description);
    QHBoxLayout *line = new QHBoxLayout();
    line->addWidget(new QLabel("Assignee"));
    line->addWidget(assignee);
    page->addLayout(line);
}

std::string AbstractEditPage::getTitle() const{
    return title->text().toStdString();
}
std::string AbstractEditPage::getDescription() const{
    return description->toPlainText().toStdString();
}
std::string AbstractEditPage::getAssignee() const{
    return assignee->text().toStdString();
}
