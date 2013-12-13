#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H

#include <QListWidget>
#include <QStyledItemDelegate>
#include <QtGui/QPainter>

class MyDelegate : public QStyledItemDelegate  {
    public:
    MyDelegate(QObject *parent=0) : QStyledItemDelegate (parent){}

    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const{
        if(option.state & QStyle::State_Selected){
            painter->fillRect(option.rect, option.palette.color(QPalette::Highlight));
        }

        QString title = index.data(Qt::DisplayRole).toString();
        QString description = index.data(Qt::UserRole + 1).toString();
        QRect r;
        r = option.rect.adjusted(50, 0, 0, -50);
        painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignBottom|Qt::AlignLeft|Qt::TextWordWrap, title, &r);

        r = option.rect.adjusted(50, 50, 0, 0);
        painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignLeft|Qt::TextWordWrap, description, &r);
    }

    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const{
        return QSize(20, 100);
    }
};

class CustomListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit CustomListWidget(QWidget *parent = 0);

signals:

public slots:

};

#endif // CUSTOMLISTWIDGET_H
