#include "AbstractEditPage.h"

AbstractEditPage::AbstractEditPage(AbstractTask *task, QWidget *parent):QWidget(parent), page(new QVBoxLayout(this)){

    title = new QLineEdit(task->getTitle());
    description = new QTextEdit(task->getDescription());
    assignee = new QLineEdit(task->getAssignee());
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

QString AbstractEditPage::getTitle() const{
    return title->text();
}
QString AbstractEditPage::getDescription() const{
    return description->toPlainText();
}
QString AbstractEditPage::getAssignee() const{
    return assignee->text();
}


