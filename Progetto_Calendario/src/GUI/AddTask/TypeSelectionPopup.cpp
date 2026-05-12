#include "TypeSelectionPopup.h"

#include <QDialogButtonBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QPropertyAnimation>

TypeSelectionPopup::TypeSelectionPopup(QWidget *parent): QDialog(parent) {

    QString styleSheet("QPushButton {"
                       "   padding: 15px;"
                       "   border: 2px solid transparent;"
                       "   border-radius: 8px;"
                       "   spacing: 5px;"
                       "   background: none;"
                       "}"
                       "QPushButton:hover {"
                       "   border-color: #3498db;"
                       "}"
                       "QPushButton:checked {"
                       "   border-color: #2ecc71;"
                       "   border-width: 3px;"
                       "}"
                       "QPushButton:pressed {"
                       "   border-color: #27ae60;"
                       "}");

    QDialogButtonBox *dialogButton = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    dialogButton->setCenterButtons(true);
    connect(dialogButton, &QDialogButtonBox::accepted, this, &TypeSelectionPopup::typeSelected);
    connect(dialogButton, &QDialogButtonBox::accepted, this, &TypeSelectionPopup::accept);
    connect(dialogButton, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QPushButton *activityButton = new QPushButton("Activity");
    QPushButton *workButton = new QPushButton("Work");
    QPushButton *billButton = new QPushButton("Bill");
    QPushButton *projectButton = new QPushButton("Project");
    QPushButton *reminderButton = new QPushButton("Reminder");

    typeSelectButtonGroup = new QButtonGroup(this);
    typeSelectButtonGroup->setExclusive(true);
    typeSelectButtonGroup->addButton(activityButton);
    typeSelectButtonGroup->addButton(workButton);
    typeSelectButtonGroup->addButton(billButton);
    typeSelectButtonGroup->addButton(projectButton);
    typeSelectButtonGroup->addButton(reminderButton);


    QSize normalSize(80, 80);
    QSize selectedSize(90, 90);
    for(auto button : typeSelectButtonGroup->buttons()){
        button->setIconSize(normalSize);
        button->setToolTip("Create new " + button->text());
        button->setCheckable(true);
        button->setStyleSheet(styleSheet);
        auto *sizeAnimation = new QPropertyAnimation(button, "iconSize", this);
        sizeAnimation->setDuration(150);
        sizeAnimation->setEasingCurve(QEasingCurve::OutCubic);
        connect(button, &QPushButton::toggled, [sizeAnimation, normalSize, selectedSize](bool checked) {
            sizeAnimation->stop();
            sizeAnimation->setStartValue(sizeAnimation->targetObject()->property("iconSize").toSize());
            sizeAnimation->setEndValue(checked ? selectedSize : normalSize);
            sizeAnimation->start();
        });
    }

    QGridLayout *typeSelectButtonList = new QGridLayout(this);
    typeSelectButtonList->addWidget(activityButton,0,0);
    typeSelectButtonList->addWidget(workButton,0,1);
    typeSelectButtonList->addWidget(billButton,0,2);
    typeSelectButtonList->addWidget(projectButton,0,3);
    typeSelectButtonList->addWidget(reminderButton,0,4);

    typeSelectButtonList->addWidget(dialogButton,1,0,1,5);
    typeSelectButtonList->setAlignment(Qt::AlignCenter);
}

void TypeSelectionPopup::typeSelected(){
    emit sendType(typeSelectButtonGroup->checkedButton()->text());
    delete this;
}
