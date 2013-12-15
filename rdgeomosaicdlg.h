#ifndef RDGEOMOSAICDLG_H
#define RDGEOMOSAICDLG_H

#include <QDialog>

class QListWidgetItem;

namespace Ui {
class RdGeoMosaicDlg;
}

class RdGeoMosaicDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RdGeoMosaicDlg(QWidget *parent = 0);
    ~RdGeoMosaicDlg();
protected slots:
    void addItem();
    void removeItem(QListWidgetItem* item);
    void addItems();
    void selectImg(QWidget *);
    void execMosaic();
private:
    Ui::RdGeoMosaicDlg *ui;
};

#endif // RDGEOMOSAICDLG_H
