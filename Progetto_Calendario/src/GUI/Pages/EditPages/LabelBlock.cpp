#include "LabelBlock.h"

#include <QHBoxLayout>

LabelBlock::LabelBlock(QString t, QWidget *parent):QFrame(parent), text(new QLabel(t)) {

    setObjectName("LabelBlock");
    setFrameShape(QFrame::StyledPanel);
    setFrameShadow(QFrame::Plain);
    setStyleSheet("QFrame#TaskBlock { border:1px solid #a0a0a0 }");

    deleteButton = new QPushButton();
    deleteButton->setText("X");
    deleteButton->setStyleSheet("QPushButton {border: 1px solid #000000;}"
                                "QPushButton:hover{background-color: rgb(205,25,25);}");
    deleteButton->setFixedSize(20,20);
    connect(deleteButton, &QPushButton::clicked, this, &LabelBlock::deleteLater);

    QHBoxLayout *line = new QHBoxLayout(this);
    line->setAlignment(Qt::AlignVCenter);
    line->setContentsMargins(1,1,1,1);
    line->setSpacing(1);
    QSpacerItem *separator = new QSpacerItem(1,1,QSizePolicy::Policy::Minimum,QSizePolicy::Policy::Expanding);
    line->addWidget(text);
    line->addSpacerItem(separator);
    line->addWidget(deleteButton);

    setMaximumHeight(25);
}

QString LabelBlock::getText() const{
    return text->text();
}
