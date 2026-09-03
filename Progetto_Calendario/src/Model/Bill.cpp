#include "data_persistancy/ConstVisitor.h"
#include "Headers/TaskListManager.h"
#include "Headers/Bill.h"
#include <iostream>
using std::cout;
using std::endl;

Bill::Bill(QString title, QString description,
           QString assignee, QDate creationDate,
           QDate dueDate, Priority priority,
           bool completed, bool skipped,
           double amount, bool paid,
           QString provider, QString IBAN, bool recurring)
    : AbstractTask(title, description, assignee, creationDate),
    Deadline(title, description, assignee, creationDate,
             dueDate, priority, completed, skipped),
    amount(amount), paid(paid),
    provider(provider), IBAN(IBAN), recurring(recurring)
{}

double Bill::getAmount()   const { return amount;    }
bool   Bill::isPaid()      const { return paid;      }
QString Bill::getProvider() const { return provider;  }
QString Bill::getIBAN()     const { return IBAN;      }
bool   Bill::isRecurring() const { return recurring; }

void Bill::setAmount   (const double& newAmount)    { amount    = newAmount;    }
void Bill::setPaid     (const bool& newPaid)        { paid      = newPaid;      }
void Bill::setProvider (const QString& newProvider)  { provider  = newProvider;  }
void Bill::setIBAN     (const QString& newIBAN)      { IBAN      = newIBAN;      }
void Bill::setRecurring(const bool& newRecurring)   { recurring = newRecurring; }

bool Bill::pay() {
    paid = true;
    return true;
}

bool Bill::remove() {
    return TaskListManager::getInstance().removeTask(getId());
}

void Bill::accept(ConstVisitor& v) {
    v.visit(*this);
}

void Bill::accept(Visitor &v) {
    v.visit(this);
}

Bill::~Bill(){
}
