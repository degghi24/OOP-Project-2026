#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QWidget>
#include <QDateEdit>
#include <QComboBox>

class FilterWindow: public QWidget{
    Q_OBJECT

private:
    //select start date
    QDateEdit *stardDateSelect = nullptr;
    //optional select end date
    QDateEdit *endDateSelect = nullptr;
    //type
    QComboBox *typeSelect = nullptr;

private slots:
    void toggleEndDateEdit(bool state);

public:
    FilterWindow(QWidget *parent = nullptr);
};

#endif // FILTERWINDOW_H
