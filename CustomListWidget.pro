#-------------------------------------------------
#
# Project created by QtCreator 2013-12-12T21:20:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CustomListWidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    customlistwidget.cpp \
    customlineedit.cpp \
    rdgeomosaicdlg.cpp \
    custonbutton.cpp

HEADERS  += mainwindow.h \
    customlistwidget.h \
    customlineedit.h \
    rdgeomosaicdlg.h \
    custonbutton.h

FORMS    += mainwindow.ui \
    rdgeomosaicdlg.ui

RESOURCES += \
    button_icons.qrc

OTHER_FILES +=
