#include "ToolBar.h"

ToolBar::ToolBar(QWidget *parent): QToolBar(parent){
    save = new QToolButton();
    import = new QToolButton();

    addWidget(save);
    addWidget(import);
}
