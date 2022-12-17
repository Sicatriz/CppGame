#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "score.h"
#include "movableObjects.h"
#include <qmediaplayer.h>
#include <QAudioOutput>

/*******************************************/
/*******************************************/
/***  BULLET CLASS (is a movable object) ***/
/*******************************************/
/*******************************************/


class Bullet: public MovableObjects  /****1 usefull and correct class ****/
{
   Q_OBJECT    // is a Q object / movable object
public:

    Bullet(QGraphicsItem * parent=0);
    /*** argumented constructor ****/
    Bullet(QGraphicsItem * parent=0, int xas =0, int yas=0, Score* scoore = 0);

    Score* score;

public slots:  //slots let's you connect signals to your function.

    //bullet movement function
    void move();

};

#endif // BULLET_H
