#ifndef BILL_H
#define BILL_H

#include "Deadline.h"

class Bill : public Deadline {
private:
    double amount;
    bool paid;
    QString provider;
    QString IBAN;
    bool recurring;

public:
    Bill(QString title, QString description,
         QString assignee, QDate creationDate,
         QDate dueDate, Priority priority,
         bool completed, bool skipped,
         double amount, bool paid,
         QString provider, QString IBAN, bool recurring);
    virtual ~Bill() override;

    double getAmount()   const;
    bool   isPaid()      const;
    QString getProvider() const;
    QString getIBAN()     const;
    bool   isRecurring() const;

    void setAmount   (const double& newAmount);
    void setPaid     (const bool& newPaid);
    void setProvider (const QString& newProvider);
    void setIBAN     (const QString& newIBAN);
    void setRecurring(const bool& newRecurring);

    bool pay();

    bool remove()           override;
    void accept(ConstVisitor& v) override;
    void accept(Visitor& v) override;
};

#endif // BILL_H
