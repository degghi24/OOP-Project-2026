#include "BillEdit.h"

BillEdit::BillEdit(Bill *task, QWidget *parent): DeadlineEditPage(task,parent) {

    savedBill = task;

    setUp();

    if(task){
        amount->setValue(task->getAmount());
        paid->setChecked(task->isPaid());
        provider->setText(task->getProvider());
        iban->setText(task->getIBAN());
        recurring->setChecked(task->isRecurring());
    }
}

BillEdit::BillEdit(QWidget *parent): DeadlineEditPage(parent) {
    setUp();
}

void BillEdit::setUp(){

    amount = new QSpinBox();
    paid = new QRadioButton();
    paid->setAutoExclusive(false);
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
QString BillEdit::getProvider() const{
    return provider->text();
}
QString BillEdit::getIban() const{
    return iban->text();
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

void BillEdit::saveEdit(){

    savedBill->setTitle(getTitle());
    savedBill->setDescription(getDescription());
    savedBill->setAssignee(getAssignee());
    savedBill->setDueDate(getDueDate());
    savedBill->setPriority(Deadline::Priority(getPriority()));
    savedBill->setCompleted(isCompleted());
    savedBill->setSkipped(isSkipped());
    savedBill->setAmount(getAmount());
    savedBill->setPaid(isPaid());
    savedBill->setProvider(getProvider());
    savedBill->setIBAN(getIban());
    savedBill->setRecurring(isRecurring());
}
