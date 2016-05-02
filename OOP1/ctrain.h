#ifndef CTRAIN_H
#define CTRAIN_H

#include <QMainWindow>
#include<QTime>
typedef enum
{
  Fast,
  Express,
  Passanger
}  KindTrain;
class CTrain
{

   protected:
   QString firstStation;
   QString lastStation;
   QTime departureTime;
   double distance;
   public:


   CTrain();
   CTrain(const QString& fStation,const QString& lStation,const QTime& depTime,const double&);
   virtual void Print()=0;



};

#endif // CTRAIN_H
