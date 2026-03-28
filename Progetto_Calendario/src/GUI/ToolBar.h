#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>
#include <QToolButton>

class ToolBar: public QToolBar{
    Q_OBJECT

signals:
    //save
    //import

public:
    ToolBar(QWidget *Parent = nullptr);

private:
    QToolButton *save = nullptr;
    QToolButton *import = nullptr;
};

#endif
