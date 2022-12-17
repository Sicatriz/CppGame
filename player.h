#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>
#include "score.h"
#include "health.h"
#include "movableObjects.h"

/*******************************************/
/*******************************************/
/****************  PLAYER  *****************/
/*******************************************/
/*******************************************/

class Player: public MovableObjects //public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem*parent = 0);

    Score* score;
    Health* health;

    // goal position ship
    void setWannaBeX( int x);
    void setWannaBeY( int y);

    int playerWidth;

public slots:

    void move();

private:
    QMediaPlayer * bulletsound;
   int wannaBeX = 0;
   int wannaBeY = 0;

};
#endif // PLAYER_H
