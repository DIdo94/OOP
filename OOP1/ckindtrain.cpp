
#include<QString>
#include<QMetaEnum>
#include<QMetaObject>
#include<QMessageBox>
#include<QTime>
#include <ckindtrain.h>
#include<ctrain.h>

CKindTrain::CKindTrain():CTrain()
{

}


CKindTrain::CKindTrain(KindTrain kTr, const QTime& arrTime, QMap<QString,QTime> stops, const QString& fStation, const QString& lStation,
              const QTime& depTime, const double& dist): CTrain(fStation,lStation,depTime,dist)
   {

       this->kt=kTr;
       this->arrivalTime=arrTime;
       this-> stopsInfo=stops;
   }

QString CKindTrain::GetFirstStation() const
{
    return this->firstStation;
}
QString CKindTrain::GetLastStation() const
{
    return this->lastStation;
}
QTime CKindTrain::GetDepartureTime() const
{
    return this->departureTime;
}
QTime CKindTrain::GetArrivalTime() const
{
    return this->arrivalTime;
}

 KindTrain CKindTrain::GetKindTrain() const
 {
     return this->kt;
 }



void CKindTrain::Print()
       {
            QString value;
           QMessageBox msg;
           if(kt==KindTrain::Express)
           {
                value="Express";

           }
           else if (kt==KindTrain::Passanger)
           {
                value="Passanger";
           }
           else
           {
               value="Fast";
           }
          // QString value=QString(metaEnum.key(kt));
           QString output="Kind:"+value+" Arrival Time:"+arrivalTime.toString("H:m:s a")+
                   "DepartureTime:"+departureTime.toString("H:m:s a")+" First Station:"+firstStation+" Last Station:"+lastStation+"\n";
           foreach (auto stop, stopsInfo.keys()) {
                output+="Stop:"+stop+" Time:"+stopsInfo.value(stop).toString("H:m:s a")+"\n";
           }
           msg.setText(output);
           msg.exec();
       }
   double CKindTrain::TrainSpeed()
   {
       int time=departureTime.secsTo(arrivalTime);
       time=time-(stopsInfo.size()-2)*300;
       double hour=time/3600.0;
       double kmH=distance/hour;
       return kmH;
   }

   QTime CKindTrain::GetStation(const QString& station)
       {

           for(auto stop:stopsInfo.keys())
           {
               if (stop==station)
               {
                   return stopsInfo.value(stop);
                   break;
               }
           }
           return QTime();
       }

   QString CKindTrain::TimeToArrival(const QString& station)
   {

        QTime timer;
       for(auto stop:stopsInfo.keys())
       {
           if (stop==station)
           {
               timer=stopsInfo.value(stop);
               break;
           }

       }
         int secs=(departureTime.secsTo(timer));

       return QString::number(secs);
   }

   CKindTrain CKindTrain::operator =(const CKindTrain& temp)
   {
       this->kt=temp.kt;
       this->arrivalTime=temp.arrivalTime;
       this->stopsInfo=temp.stopsInfo;
       this->firstStation=temp.firstStation;
       this->lastStation=temp.lastStation;
       this->departureTime=temp.departureTime;
       this->distance=temp.distance;
       return *this;
   }




