#ifndef CKINDTRAIN_H
#define CKINDTRAIN_H

#include <QMainWindow>
#include<ctrain.h>
#include<QTime>
#include<QMap>
#include<kindtrain.h>

class CKindTrain:CTrain
{

private:
    KindTrain kt;
    QTime arrivalTime;
    QMap<QString,QTime> stopsInfo;
public:
    CKindTrain();
    CKindTrain(KindTrain kTr, const QTime& arrTime, QMap<QString,QTime> stops, const QString& fStation, const QString& lStation,
                  const QTime& depTime, const double&);
    QString GetFirstStation() const;
    QString GetLastStation() const;
    QTime GetDepartureTime() const;
    QTime GetArrivalTime() const;
    KindTrain GetKindTrain() const;
    CKindTrain operator =(const CKindTrain& temp);

    void Print();
    double TrainSpeed();
    QTime GetStation(const QString& station);
    QString TimeToArrival(const QString& station);


};

#endif // CKINDTRAIN_H
