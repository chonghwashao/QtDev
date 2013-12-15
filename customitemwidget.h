#ifndef CUSTOMITEMWIDGET_H
#define CUSTOMITEMWIDGET_H

#include <QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

class QListWidgetItem;

class CustomItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomItemWidget(QListWidgetItem *item, QWidget *parent = 0);

signals:
    void removeItem(QListWidgetItem *);

public slots:
    void changeItem();
    void removeItem();

private:
    QPushButton *plusBtn;
    QPushButton *minusBtn;
    QLineEdit   *lineEdit;
    QListWidgetItem *item;

};

#endif // CUSTOMITEMWIDGET_H
