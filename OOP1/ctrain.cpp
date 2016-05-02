#include "ctrain.h"
#include"ckindtrain.h"
#include<QTime>
 CTrain:: CTrain()
 {

 }
   CTrain:: CTrain(const QString& fStation,const QString& lStation,const QTime& depTime,const double& dist)
      {
        firstStation=fStation;
        lastStation=lStation;
        departureTime=depTime;
        distance=dist;
      }



