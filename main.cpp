#include "mainwindow.h"
#include <QApplication>
#include "rdgeomosaicdlg.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    RdGeoMosaicDlg dlg;
    dlg.show();

    //a.setStyleSheet("QListWidget { background: red; } QListWidget::item { background: black; } QListWidget::item:selected { background: gray; }");

    return a.exec();
}
