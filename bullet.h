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


class Bullet: public MovableObjects  /****1 usefull and correct class ****/
{
   Q_OBJECT    // bullet needs to be an Qobject for movement and this makes it a object.
public:

  //  Bullet(QGraphicsItem * parent=0);  /*** argumented constructor ****/
    Bullet(QGraphicsItem * parent=0, int xas =0, int yas=0, Score* scoore = 0);
    Score* score;

public slots:  //slots let's you connect signals to your function.
    void move();
    //bool cooldown();

};

#endif // BULLET_H
