#ifndef BILLEDIT_H
#define BILLEDIT_H

#include "DeadlineEditPage.h"
#include "../../../Model/Headers/Bill.h"

#include <QWidget>
#include <QSpinBox>

class BillEdit: public DeadlineEditPage{
    Q_OBJECT

private:
    Bill *savedBill = nullptr;

    QSpinBox *amount = nullptr;
    QRadioButton *paid = nullptr;
    QLineEdit *provider = nullptr;
    QLineEdit *iban = nullptr;
    QRadioButton *recurring = nullptr;

    void setUp();

public slots:
    void createTask();
    void saveEdit();

signals:
    void returnTask(Bill *task);

public:
    int getAmount() const;
    bool isPaid() const;
    QString getProvider() const;
    QString getIban() const;
    bool isRecurring() const;

    BillEdit(Bill *task, QWidget *parent = nullptr);
    BillEdit(QWidget *parent = nullptr);

};

#endif // BILLEDIT_H
