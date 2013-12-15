#ifndef CUSTONBUTTON_H
#define CUSTONBUTTON_H

#include <QPushButton>
#include <QListWidgetItem>

class CustonButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CustonButton(QListWidgetItem* item, QWidget *parent = 0);

    // 保存对应list中Item
    QListWidgetItem* item;

signals:
    void minusClicked(QListWidgetItem *itm);

public slots:
    void reomveItem();
};

#endif // CUSTONBUTTON_H
