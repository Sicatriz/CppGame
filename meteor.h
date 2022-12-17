#ifndef METEOR_H
#define METEOR_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QTimer>
#include "movableObjects.h"

/*******************************************/
/*******************************************/
/**********  ENEMY ABSTRACT CLASS  *********/
/*******************************************/
/*******************************************/
namespace insemi
{
class Meteor: public MovableObjects
{
     Q_OBJECT
public:
    Meteor(QGraphicsItem * parent=0);
public slots:
    void move();

};
}
#endif // METEOR_H
