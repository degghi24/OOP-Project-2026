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

    amount = new QSpinBox();
    paid = new QRadioButton();
    provider = new QLineEdit();
    iban = new QLineEdit();
    recurring = new QRadioButton();

    page->addWidget(new QLabel("Amount:"));
    page->addWidget(amount);
    QHBoxLayout *linePaid = new QHBoxLayout();
    linePaid->setAlignment(Qt::AlignLeft);
    linePaid->addWidget(new QLabel("Is Paid:"));
    linePaid->addWidget(paid);
    page->addLayout(linePaid);
    page->addWidget(new QLabel("Provider:"));
    page->addWidget(provider);
    page->addWidget(new QLabel("Iban:"));
    page->addWidget(iban);
    QHBoxLayout *lineRec = new QHBoxLayout();
    lineRec->setAlignment(Qt::AlignLeft);
    lineRec->addWidget(new QLabel("Is Recurring:"));
    lineRec->addWidget(recurring);
    page->addLayout(lineRec);

}

int BillEdit::getAmount() const{
    return amount->value();
}
bool BillEdit::isPaid() const{
    return paid->isChecked();
}
std::string BillEdit::getProvider() const{
    return provider->text().toStdString();
}
std::string BillEdit::getIban() const{
    return iban->text().toStdString();
}
bool BillEdit::isRecurring() const{
    return recurring->isChecked();
}

void BillEdit::createTask(){
    Bill *newBill = new Bill(getTitle(),getDescription(),getAssignee(), QDate::currentDate(),
                             getDueDate(),static_cast<Deadline::Priority>(getPriority()),isCompleted(),isSkipped(),
                             getAmount(),isPaid(),getProvider(),getIban(),isRecurring());
    emit returnTask(newBill);
}
