#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QLineEdit>

class CustomLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit CustomLineEdit(QWidget *parent = 0);

signals:

public slots:

protected:
    void mouseDoubleClickEvent(QMouseEvent *);

};

#endif // CUSTOMLINEEDIT_H
