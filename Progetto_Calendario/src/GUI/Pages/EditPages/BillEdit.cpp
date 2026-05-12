#include "BillEdit.h"

BillEdit::BillEdit(Bill *task, QWidget *parent): DeadlineEditPage(task,parent) {
    setUp();

    if(task){
        amount->setValue(task->getAmount());
        paid->setChecked(task->isPaid());
        provider->setText(task->getProvider().c_str());
        iban->setText(task->getIBAN().c_str());
        recurring->setChecked(task->isRecurring());
    }
}

BillEdit::BillEdit(QWidget *parent): DeadlineEditPage(parent) {
    setUp();
}

void BillEdit::setUp(){

    QSpinBox *amount = new QSpinBox();
    QRadioButton *paid = new QRadioButton();
    QLineEdit *provider = new QLineEdit();
    QLineEdit *iban = new QLineEdit();
    QRadioButton *recurring = new QRadioButton();

    page->addWidget(new QLabel("Amount:"));
    page->addWidget(amount);
    page->addWidget(new QLabel("Is Paid:"));
    page->addWidget(paid);
    page->addWidget(new QLabel("Provider:"));
    page->addWidget(provider);
    page->addWidget(new QLabel("Iban:"));
    page->addWidget(iban);
    page->addWidget(new QLabel("Is Recurring:"));
    page->addWidget(recurring);

}
