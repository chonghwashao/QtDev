#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QLineEdit>
#include "customlineedit.h"
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 4; i++)
    {
//        QListWidgetItem *item = new QListWidgetItem();
//        item->setFlags (item->flags() | Qt::ItemIsEditable);
//        item->setData(Qt::DisplayRole, "This is the title" + QString("%1").arg(i));
//        item->setData(Qt::UserRole + 1, "This is description");
//        ui->listWidget->setItemWidget();
//        ui->listWidget->addItem(item);
        QListWidgetItem* item = new QListWidgetItem();
        QIcon icon = QIcon::fromTheme("edit-undo");
        item->setIcon(icon);
        //item->setText("Item1");
        item->setFlags (item->flags() | Qt::ItemIsEditable);
        item->setSizeHint(QSize(item->sizeHint().width(), 20));

        //item->setBackgroundColor(QColor(200,255,100));

        ui->listWidget->addItem(item);
        QPushButton *addBtn = new QPushButton();
        QObject::connect(addBtn, SIGNAL(clicked()),
                         this,  SLOT(selectImg()));
        addBtn->setMaximumSize(24,24);
        addBtn->setIcon(QIcon(":/icons/select"));
        QPushButton *rmBtn = new QPushButton();
        QObject::connect(rmBtn, SIGNAL(clicked()),
                         this,  SLOT(selectImg()));
        rmBtn->setMaximumSize(24,24);
        rmBtn->setIcon(QIcon(":/icons/delete"));
        QLineEdit* lineEdit = new QLineEdit();
        lineEdit->setMaxLength(512);
        //lineEdit->setStyleSheet("background: transparent; border: none");

        QHBoxLayout *layout= new QHBoxLayout();
        layout->setSpacing(1);
        layout->setContentsMargins(0,0,0,0);

        layout->addWidget(lineEdit);
        layout->addWidget(addBtn);
        layout->addWidget(rmBtn);
        QWidget *widget = new QWidget();
        widget->setLayout(layout);
        //item->setSizeHint(widget->sizeHint());
        ui->listWidget->setItemWidget(item, widget);
    }

    //ui->listWidget->setItemDelegate(new MyDelegate(ui->listWidget));
    ui->listWidget->showMaximized();
    //ui->listWidget->showMinimized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectImg()
{
    qDebug() << "选择影像。。。。";
}
