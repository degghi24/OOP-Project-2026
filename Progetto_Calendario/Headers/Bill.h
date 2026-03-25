#ifndef BILL_H
#define BILL_H

#include <string>
using std::string;
#include "Deadline.h"

class Bill : public Deadline {
private:
    double amount;
    bool paid;
    string provider;
    string IBAN;
    bool recurring;

public:
    Bill(string id, string title, string description,
         string assignee, string creationDate,
         string dueDate, Priority priority,
         bool completed, bool skipped,
         double amount, bool paid,
         string provider, string IBAN, bool recurring);
    virtual ~Bill() = default;

    double getAmount()   const;
    bool   isPaid()      const;
    string getProvider() const;
    string getIBAN()     const;
    bool   isRecurring() const;

    void setAmount   (const double& newAmount);
    void setPaid     (const bool& newPaid);
    void setProvider (const string& newProvider);
    void setIBAN     (const string& newIBAN);
    void setRecurring(const bool& newRecurring);

    bool pay();

    void display()          override;
    bool remove()           override;
    void accept(Visitor& v) override;
};

#endif // BILL_H