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

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem *, QGraphicsScene *sceene=0);
    void keyPressEvent(QKeyEvent * event);


    QGraphicsScene *scene;

    Score* score;
    Health* health;

    void setWannaBeX(int x);
    void setWannaBeY(int y);

    int playerWidth;

 //   void mousePressEvent(QMouseEvent *event);


public slots:
    void spawn();
    //void spawnBoat();
    void motion();
    void collision();
private:
    QMediaPlayer * bulletsound;
    int wannaBeX = 0;
    int wannaBeY = 0;

};
#endif // PLAYER_H
