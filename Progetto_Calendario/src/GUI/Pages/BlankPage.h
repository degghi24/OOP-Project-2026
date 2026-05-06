#ifndef BLANKPAGE_H
#define BLANKPAGE_H

#include <QVBoxLayout>
#include <QWidget>

class BlankPage: public QWidget{
    Q_OBJECT

private:
    QStringList list{"Activity","Reminder","Bill","Project","Work"};

    void abstractBase(bool isEditable);
    void timedBase(bool isEditable);
    void repeatableBase(bool isEditable);
    void deadlineBase(bool isEditable);

protected:
    QVBoxLayout *page = nullptr;

public:
    BlankPage(QString &type, bool isEditable = false, QWidget *parent = nullptr);

};

#endif // BLANKPAGE_H
