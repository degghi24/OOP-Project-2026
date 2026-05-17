#ifndef LABELBLOCK_H
#define LABELBLOCK_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>

class LabelBlock:public QFrame{
    Q_OBJECT

private:
    QLabel *text = nullptr;
    QPushButton *deleteButton = nullptr;

public:
    LabelBlock(QString text, QWidget *parent = nullptr);

    QString getText() const;
};

#endif // LABELBLOCK_H
