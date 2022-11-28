#ifndef ENEMY1_H
#define ENEMY1_H

#include <enemy.h>
#include "game.h"

class Enemy1: public Enemy{    /***7 usefull and correct base class ***/
    Q_OBJECT
public:
    Enemy1(QGraphicsItem * parent=0);
public slots:
    void move(int speed = 5);   /***5 polymorphism***/

};

#endif // ENEMY1_H
