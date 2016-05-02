#ifndef CTRAINNET_H
#define CTRAINNET_H
#include<QString>
#include<QList>
#include<ckindtrain.h>
class CTrainNet
{
private:
    QList<CKindTrain*> trains;
public:
    CTrainNet(const QString &name);
    QList<CKindTrain*> GetTrains(const QString& fStation,const QString& lStation);
    QList<CKindTrain*> GetTrainsBeforeArrival(const QString& fStation,const QString& lStation,const QTime& hour);
    QList<CKindTrain*> GetTrainsBeforeDeparture(const QString& fStation,const QString& lStation,const QTime& hour);
    CKindTrain *GetFastestTrain(const QString& fStation,const QString& lStation) const;
    double GetAverageSpeed(const KindTrain& kind) const;
};

#endif // CTRAINNET_H
