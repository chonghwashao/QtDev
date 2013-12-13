#include "custonbutton.h"

CustonButton::CustonButton(QListWidgetItem *item, QWidget *parent) :
    QPushButton(parent), item(item)
{
    connect(this, SIGNAL(clicked()), this, SLOT(selectItem()));
}

void CustonButton::selectItem()
{
    emit itemClicked(item);
}
