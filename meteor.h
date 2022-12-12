#ifndef METEOR_H
#define METEOR_H

//#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>


#include <QTimer>

class meteor: public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    meteor(QGraphicsItem * parent=0);
public slots:
    virtual void move(int speed)=0;
};

#endif // METEOR_H
