#include "custonbutton.h"

CustonButton::CustonButton(QListWidgetItem *item, QWidget *parent) :
    QPushButton(parent), item(item)
{
    connect(this, SIGNAL(clicked()), this, SLOT(reomveItem()));
}

void CustonButton::reomveItem()
{
    emit minusClicked(item);
}

