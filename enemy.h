#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "movableObjects.h"
#include "health.h"
#include <QTimer>

class Enemy: public MovableObjects /***8 abstract base class***/
{
   Q_OBJECT    // enemy needs to be an Qobject for movement

public:

   Enemy(QGraphicsItem * parent=0);
   Health* health;

public slots:
    virtual void move();
    void hit(int dmg); /***9 virtual function***/
    bool destroy();
protected:
    int hp = 1;

};

#endif // ENEMY_H
