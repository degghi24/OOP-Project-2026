#include "ToolBar.h"

ToolBar::ToolBar(QWidget *parent): QToolBar(parent){

    save = new QToolButton();
    QIcon saveIcon("../../assets/images/SaveIcon.svg");
    qDebug()<<saveIcon.isNull();
    save->setIcon(saveIcon);
    save->setToolTip("Save content to file");
    connect(save, &QToolButton::clicked, this, &ToolBar::saveSignal);

    import = new QToolButton();
    QIcon importIcon("../../assets/images/ImportIcon.svg");
    qDebug()<<importIcon.isNull();
    import->setIcon(importIcon);
    import->setToolTip("Import content from file");
    connect(import, &QToolButton::clicked, this, &ToolBar::importSignal);


    addWidget(save);
    addWidget(import);
}
