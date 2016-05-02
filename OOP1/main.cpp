#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QApplication>
#include<QtCore>
#include<QtGui>
#include<QMessageBox>
#include<ctrain.h>
#include<ckindtrain.h>
#include<QTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;



    w.show();
    return a.exec();
}
