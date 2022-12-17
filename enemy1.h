#ifndef ENEMY1_H
#define ENEMY1_H

#include <enemy.h>

/*******************************************/
/*******************************************/
/***********  ENEMY1: 5 HP enemy  **********/
/*******************************************/
/*******************************************/

class Enemy1: public Enemy{    /***7 usefull and correct base class ***/
    Q_OBJECT
public:
    Enemy1(QGraphicsItem * parent=0, Health* h=0);
public slots:
    void move();
    void hit(int dmg);

private:
};

#endif // ENEMY1_H
