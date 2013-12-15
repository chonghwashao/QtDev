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
    rdgeomosaicdlg.cpp \
    customitemwidget.cpp

HEADERS  += mainwindow.h \
    customlistwidget.h \
    rdgeomosaicdlg.h \
    customitemwidget.h

FORMS    += mainwindow.ui \
    rdgeomosaicdlg.ui

RESOURCES += \
    button_icons.qrc

OTHER_FILES +=
