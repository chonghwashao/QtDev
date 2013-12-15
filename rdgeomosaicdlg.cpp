#include "rdgeomosaicdlg.h"
#include "ui_rdgeomosaicdlg.h"
#include <QDebug>
#include "custonbutton.h"

RdGeoMosaicDlg::RdGeoMosaicDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RdGeoMosaicDlg)
{
    ui->setupUi(this);
    setWindowTitle("影像拼接");
    connect(ui->toolButton_addItem, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(ui->toolButton_addItemofDir, SIGNAL(clicked()), this, SLOT(addItems()));
    connect(ui->toolButton_rmAll, SIGNAL(clicked()), ui->customList, SLOT(clear()));

    connect(ui->pushButton_exec, SIGNAL(clicked()), this, SLOT(execMosaic()));
    connect(ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(close()));
}

RdGeoMosaicDlg::~RdGeoMosaicDlg()
{
    delete ui;
}

void RdGeoMosaicDlg::addItem()
{
    QListWidgetItem* item = new QListWidgetItem();
    QIcon icon = QIcon::fromTheme("edit-undo");
    item->setIcon(icon);
    item->setFlags (item->flags() | Qt::ItemIsEditable);
    item->setSizeHint(QSize(item->sizeHint().width(), 20));
    ui->customList->addItem(item);

    /**
      添加按钮及响应
    */
    CustonButton *plusBtn = new CustonButton(item);
    plusBtn->setMaximumSize(24,24);
    plusBtn->setIcon(QIcon(":/icons/select"));
    CustonButton *minusBtn = new CustonButton(item);
    minusBtn->setMaximumSize(24,24);
    minusBtn->setIcon(QIcon(":/icons/delete"));
    QLineEdit* lineEdit = new QLineEdit();
    lineEdit->setMaxLength(512);
    //QObject::connect(plusBtn, SIGNAL(clicked()), ui->customList,  SLOT(itemClicked(QListWidgetItem *)));
    QObject::connect(minusBtn, SIGNAL(itemClicked(QListWidgetItem *)), this,  SLOT(removeItem(QListWidgetItem *)));
    QObject::connect(plusBtn, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(selectImg(QListWidgetItem *)));
    QHBoxLayout *layout= new QHBoxLayout();
    layout->setSpacing(1);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(lineEdit);
    layout->addWidget(plusBtn);
    layout->addWidget(minusBtn);
    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    //item->setSizeHint(widget->sizeHint());
    ui->customList->setItemWidget(item, widget);
    ui->customList->setCurrentItem(item);
}

void RdGeoMosaicDlg::removeItem(QListWidgetItem *item)
{
    ui->customList->removeItemWidget(item);
    delete item;
}

void RdGeoMosaicDlg::addItems()
{

}

void RdGeoMosaicDlg::selectImg(QListWidgetItem *item)
{
    qDebug() << "===========================";
    QWidget *widget = itemWidget(item);

}

void RdGeoMosaicDlg::execMosaic()
{
    qDebug() << "==============执行拼接=============";
}
