#include "AbstractEditPage.h"

AbstractEditPage::AbstractEditPage(AbstractTask *task, QWidget *parent):QWidget(parent), page(new QVBoxLayout(this)){

    QLineEdit *title = new QLineEdit(task->getTitle().c_str());
    QTextEdit *description = new QTextEdit(task->getDescription().c_str());
    QLineEdit *assignee = new QLineEdit(task->getAssignee().c_str());
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

    QLineEdit *title = new QLineEdit();
    QTextEdit *description = new QTextEdit();
    QLineEdit *assignee = new QLineEdit();
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
