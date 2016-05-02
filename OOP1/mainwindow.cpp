#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include<QFormLayout>
#include<QTime>
#include<QLineEdit>
#include <QApplication>
#include<QtCore>
#include<QtGui>
#include<QDialogButtonBox>
#include<QMessageBox>
#include<ctrain.h>
#include<ckindtrain.h>
#include<QMessageBox>
#include<ctrainnet.h>
Q_GLOBAL_STATIC_WITH_ARGS(CTrainNet,tNet,(":/Input/test.txt"))

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::HelpFunc()
{
    QMessageBox msg;
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);
    // Add some text above the fields

    // Add the lineEdits with their respective labels
        QList<QLineEdit*> fields;
        QLineEdit* kind= new QLineEdit(&dialog);
        form.addRow("Въведете вид влак",kind);
        fields << kind;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
   QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec()==QDialog::Accepted)
    {
        KindTrain kt;
        //QString str=fStation->text();
        if(kind->text()=="Fast")
        {
            kt=KindTrain::Fast;
        }
        else if(kind->text()=="Passanger")
        {
            kt=KindTrain::Passanger;
        }
        else
        {
            kt=KindTrain::Express;
        }
        double speed=0.0;
        speed=tNet->GetAverageSpeed(kt);
        if(speed==-1)
        {

            msg.setText("Няма такъв влак");

        }
        else
        {
            msg.setText(QString::number(speed));
        }
          msg.exec();
    }
    else
    {
        fields.erase(fields.begin(),fields.end());
    }
}
void MainWindow::on_pushButton_clicked()
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);
    // Add some text above the fields

    // Add the lineEdits with their respective labels
        QList<QLineEdit*> fields;
        QLineEdit* fStation= new QLineEdit(&dialog);
        form.addRow("Въведете начална гара",fStation);

         QLineEdit* lStation= new QLineEdit(&dialog);
        form.addRow("Въведете крайна гара",lStation);

        fields << fStation<<lStation;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
   QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec()==QDialog::Accepted)
    {

        //QString str=fStation->text();
       QString txt= fields.at(0)->text();
       QList<CKindTrain*> trainList=tNet->GetTrains(fStation->text(),lStation->text());
       if(trainList.empty())
       {
       QMessageBox msg;
       msg.setText("Няма намерени влакове");
       msg.exec();
       }
       else
       {
            foreach (CKindTrain* train, trainList) {
            train->Print();
            }
       }
    }
    else
    {
        fields.erase(fields.begin(),fields.end());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);
    // Add some text above the fields

    // Add the lineEdits with their respective labels
        QList<QLineEdit*> fields;
        QLineEdit* fStation= new QLineEdit(&dialog);
        form.addRow("Въведете начална гара",fStation);

         QLineEdit* lStation= new QLineEdit(&dialog);
        form.addRow("Въведете крайна гара",lStation);
         QLineEdit* time= new QLineEdit(&dialog);
         form.addRow("Въведете време",time);
        fields << fStation<<lStation<<time;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
   QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec()==QDialog::Accepted)
    {

        //QString str=fStation->text();
       QString txt= fields.at(0)->text();
       QList<CKindTrain*> trainList=tNet->GetTrainsBeforeArrival(fStation->text(),lStation->text(),QTime::fromString(time->text(),"H:m:s"));
       if(trainList.empty())
       {
       QMessageBox msg;
       msg.setText("Няма намерени влакове");
       msg.exec();
       }
       else
       {
            foreach (CKindTrain* train, trainList) {
            train->Print();
            }
       }
    }
    else
    {
        fields.erase(fields.begin(),fields.end());
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);
    // Add some text above the fields

    // Add the lineEdits with their respective labels
        QList<QLineEdit*> fields;
        QLineEdit* fStation= new QLineEdit(&dialog);
        form.addRow("Въведете начална гара",fStation);

         QLineEdit* lStation= new QLineEdit(&dialog);
        form.addRow("Въведете крайна гара",lStation);
         QLineEdit* time= new QLineEdit(&dialog);
         form.addRow("Въведете време",time);
        fields << fStation<<lStation<<time;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
   QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec()==QDialog::Accepted)
    {

        //QString str=fStation->text();
       QString txt= fields.at(0)->text();
       QList<CKindTrain*> trainList=tNet->GetTrainsBeforeDeparture(fStation->text(),lStation->text(),QTime::fromString(time->text(),"H:m:s"));
       if(trainList.empty())
       {
       QMessageBox msg;
       msg.setText("Няма намерени влакове");
       msg.exec();
       }
       else
       {
            foreach (CKindTrain* train, trainList) {
            train->Print();
            }
       }
    }
    else
    {
        fields.erase(fields.begin(),fields.end());
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);
    // Add some text above the fields

    // Add the lineEdits with their respective labels
        QList<QLineEdit*> fields;
        QLineEdit* fStation= new QLineEdit(&dialog);
        form.addRow("Въведете начална гара",fStation);

         QLineEdit* lStation= new QLineEdit(&dialog);
        form.addRow("Въведете крайна гара",lStation);
        fields << fStation<<lStation;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
   QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec()==QDialog::Accepted)
    {

        //QString str=fStation->text();
        QString txt= fields.at(0)->text();
        CKindTrain* train;
        CTrainNet *tn=new CTrainNet(":/Input/test.txt");
        train=tn->GetFastestTrain(fStation->text(),lStation->text());
        if(train==NULL)
        {
            QMessageBox msg;
            msg.setText("Няма такъв влак");
            msg.exec();
        }
        else
        {
            train->Print();
        }
    }
    else
    {
        fields.erase(fields.begin(),fields.end());
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    MainWindow::HelpFunc();
}
