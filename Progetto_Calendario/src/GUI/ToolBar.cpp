#include "ToolBar.h"

ToolBar::ToolBar(QWidget *parent): QToolBar(parent){

    save = new QToolButton();
    save->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
    save->setToolTip("Save content to file");
    connect(save, &QToolButton::clicked, this, &ToolBar::saveSignal);

    import = new QToolButton();
    import->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::FolderOpen));
    import->setToolTip("Import content from file");
    connect(import, &QToolButton::clicked, this, &ToolBar::importSignal);


    addWidget(save);
    addWidget(import);
}
