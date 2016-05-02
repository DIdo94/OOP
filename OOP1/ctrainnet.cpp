
#include "ctrainnet.h"
#include"ckindtrain.h"
#include<ctrain.h>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QStringList>
CTrainNet::CTrainNet(const QString &name)
{
    QFile input(name);
    QString line;
    KindTrain kt;
     QMessageBox err;
     QMap<QString,QTime> stops;
    if (!input.open(QFile::ReadOnly | QFile::Text))
    {
        err.setText("File Not Found!!!");
        err.exec();
        input.close();
        exit(0);
    }

    QTextStream text(&input);
    while(true)
    {
        if( !(line=text.readLine()).isNull())
        {
            QStringList strings=line.split(",");
            if (strings[0]=="Fast")
            {
                kt=KindTrain::Fast;
            }
            else if(strings[0]=="Express")
            {
                kt=KindTrain::Express;
            }
            else
            {
                kt=KindTrain::Passanger;
            }

            QString str=strings[2];
            QStringList stop=str.split(" ");
            foreach (QString item, stop) {
               QStringList pair=item.split("-");
               stops.insert(pair[0],QTime::fromString(pair[1],"H:m:s"));

            }
           trains.append(new CKindTrain(kt,QTime::fromString(strings[1],"H:m:s"),
                         stops,strings[3],strings[4],QTime::fromString(strings[5],"H:m:s"),strings[6].toDouble()));

        }
        else
        {
            break;
        }
    }

    input.close();
}

QList<CKindTrain*> CTrainNet::GetTrains(const QString& fStation,const QString& lStation)
{
    QList<CKindTrain*> trainsToReturn;
    foreach (CKindTrain *tr, trains) {
        if(tr->GetFirstStation()==fStation && tr->GetLastStation()==lStation)
        {
            trainsToReturn.append(tr);
        }
    }

    return trainsToReturn;
}

QList<CKindTrain*> CTrainNet::GetTrainsBeforeDeparture(const QString& fStation,const QString& lStation,const QTime& hour)
{
    QList<CKindTrain*> trainsToReturn;
    foreach (CKindTrain *tr, trains) {
        if(tr->GetFirstStation()==fStation && tr->GetLastStation()==lStation && tr->GetDepartureTime()<hour)
        {
            trainsToReturn.append(tr);
        }
    }

    return trainsToReturn;
}

CKindTrain* CTrainNet::GetFastestTrain(const QString& fStation,const QString& lStation) const
{
    double speed=0.0;
    CKindTrain *trainToReturn=new CKindTrain();
    foreach (CKindTrain *tr, trains) {
        if(tr->GetFirstStation()==fStation && tr->GetLastStation()==lStation)
        {
            if(speed<tr->TrainSpeed())
            {
                speed=tr->TrainSpeed();
                *trainToReturn=*tr;
            }
        }
    }
    return trainToReturn;
}

 double CTrainNet::GetAverageSpeed(const KindTrain& kind) const
 {
     double speed=0.0;
     int counter=0;
     foreach (CKindTrain *tr, trains) {
         if(tr->GetKindTrain()==kind)
         {
            speed+=tr->TrainSpeed();
            counter++;
         }
     }
    if(counter==0)
        return -1;
     return speed/counter;
 }

 QList<CKindTrain*> CTrainNet::GetTrainsBeforeArrival(const QString& fStation,const QString& lStation,const QTime& hour)
 {
     QList<CKindTrain*> trainsToReturn;
     foreach (CKindTrain *tr, trains) {
         if(tr->GetFirstStation()==fStation && tr->GetLastStation()==lStation && tr->GetArrivalTime()<hour)
         {
             trainsToReturn.append(tr);
         }
     }

     return trainsToReturn;
 }
