#include "rdgeomosaicdlg.h"
#include "ui_rdgeomosaicdlg.h"
#include <QDebug>
#include "custonbutton.h"
#include "customitemwidget.h"

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
    //item->setFlags (item->flags() | Qt::ItemIsEditable);
    item->setSizeHint(QSize(item->sizeHint().width(), 20));
    ui->customList->addItem(item);
    // 添加定制的Item
    CustomItemWidget *widget = new CustomItemWidget(item, this);
    ui->customList->setItemWidget(item, widget);
    ui->customList->setCurrentItem(item);
    connect(widget, SIGNAL(removeItem(QListWidgetItem *)), this, SLOT(removeItem(QListWidgetItem *)));
}

void RdGeoMosaicDlg::removeItem(QListWidgetItem *item)
{
    ui->customList->removeItemWidget(item);
    delete item;
}

void RdGeoMosaicDlg::addItems()
{

}

void RdGeoMosaicDlg::selectImg(QWidget *w)
{
    qDebug() << "===========================";
    QLineEdit *edit = (QLineEdit *)w;
    edit->setText("hello world");

}

void RdGeoMosaicDlg::execMosaic()
{
    qDebug() << "==============执行拼接=============";
}
