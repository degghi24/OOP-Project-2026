#include "data_persistancy/Visitor.h"
#include "Headers/Bill.h"
#include <iostream>
using std::cout;
using std::endl;

Bill::Bill(string id, string title, string description,
           string assignee, string creationDate,
           string dueDate, Priority priority,
           bool completed, bool skipped,
           double amount, bool paid,
           string provider, string IBAN, bool recurring)
    : AbstractTask(id, title, description, assignee, creationDate),
    Deadline(id, title, description, assignee, creationDate,
             dueDate, priority, completed, skipped),
    amount(amount), paid(paid),
    provider(provider), IBAN(IBAN), recurring(recurring)
{}

double Bill::getAmount()   const { return amount;    }
bool   Bill::isPaid()      const { return paid;      }
string Bill::getProvider() const { return provider;  }
string Bill::getIBAN()     const { return IBAN;      }
bool   Bill::isRecurring() const { return recurring; }

void Bill::setAmount   (const double& newAmount)    { amount    = newAmount;    }
void Bill::setPaid     (const bool& newPaid)        { paid      = newPaid;      }
void Bill::setProvider (const string& newProvider)  { provider  = newProvider;  }
void Bill::setIBAN     (const string& newIBAN)      { IBAN      = newIBAN;      }
void Bill::setRecurring(const bool& newRecurring)   { recurring = newRecurring; }

bool Bill::pay() {
    paid = true;
    return true;
}

void Bill::display() {
    cout << "Bill: "     << getTitle() << endl;
    cout << "Amount: "   << amount << endl;
    cout << "Provider: " << provider << endl;
    cout << "Due: "      << getDueDate() << endl;
    cout << "Paid: "     << (paid ? "Yes" : "No") << endl;
}

bool Bill::remove() {
    return true; // placeholder
}

void Bill::accept(Visitor& v) {
    v.visit(*this);
}
