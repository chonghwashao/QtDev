#include "customlineedit.h"

CustomLineEdit::CustomLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    //setReadOnly(true)
}

void CustomLineEdit::mouseDoubleClickEvent(QMouseEvent *)
{
//    setReadOnly(false);
//    setEnabled(true);
//    setFocus();
    setModified(true);
    setFocus();
}
