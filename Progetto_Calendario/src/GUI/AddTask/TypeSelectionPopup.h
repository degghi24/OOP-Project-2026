#ifndef TYPESELECTIONPOPUP_H
#define TYPESELECTIONPOPUP_H

#include <QDialog>
#include <QButtonGroup>
#include <QPushButton>

class TypeSelectionPopup:public QDialog{
    Q_OBJECT

private:
    QButtonGroup *typeSelectButtonGroup = nullptr;

private slots:
    void typeSelected();

signals:
    void sendType(QString type);

public:
    TypeSelectionPopup(QWidget *parent = nullptr);
};

#endif // TYPESELECTIONPOPUP_H
