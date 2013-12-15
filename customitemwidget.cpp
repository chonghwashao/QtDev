#include "customitemwidget.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidgetItem>
#include <QtWidgets/QFileDialog>

CustomItemWidget::CustomItemWidget(QListWidgetItem *item,QWidget *parent) :
    QWidget(parent),
    item(item)
{
    plusBtn = new QPushButton();
    plusBtn->setMaximumSize(24,24);
    plusBtn->setIcon(QIcon(":/icons/select"));
    minusBtn = new QPushButton();
    minusBtn->setMaximumSize(24,24);
    minusBtn->setIcon(QIcon(":/icons/delete"));
    lineEdit = new QLineEdit();
    lineEdit->setMaxLength(512);

    QHBoxLayout *layout= new QHBoxLayout();
    layout->setSpacing(1);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(lineEdit);
    layout->addWidget(plusBtn);
    layout->addWidget(minusBtn);
    setLayout(layout);

    // 控件相关响应
    connect(plusBtn, SIGNAL(clicked()), this,  SLOT(changeItem()));
    connect(minusBtn, SIGNAL(clicked()), this,  SLOT(removeItem()));
}

void CustomItemWidget::changeItem()
{
    QFileDialog dlg(this,"选择影像...");
    dlg.setNameFilter(tr("Image Files(*.tiff *.tif *.jpg *.png)"));
    if(dlg.exec()==QFileDialog::Accepted) // ok
    {
        QString fn = dlg.selectedFiles()[0];
        lineEdit->setText(fn);
    }
}

void CustomItemWidget::removeItem()
{
    emit removeItem(item);
}
