#-------------------------------------------------
#
# Project created by QtCreator 2016-04-08T14:42:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OOP1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ctrain.cpp \
    ckindtrain.cpp \
    ctrainnet.cpp

HEADERS  += mainwindow.h \
    ctrain.h \
    ckindtrain.h \
    ctrainnet.h

FORMS    += mainwindow.ui

DISTFILES += \
    test.txt

RESOURCES += \
    files.qrc
