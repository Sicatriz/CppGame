#include "enemy2.h"

//this is the fast enemy
Enemy2::Enemy2(QGraphicsItem *parent, Health* h):Enemy()
{
    health = h;
    // set random start position
    int random_number = rand() % 1700;
    setPos(random_number, 0);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/Buggy_LightPurple.png"));

    hp = 2;
}

void Enemy2::move()
{
    // move enemy down
    setPos(x(),y()+1.5);

    // when enemy is out of screen, free memory
    if(pos().y() > 1000){

        //decrease the health
        health->decrease();

        scene()->removeItem(this);
        this->deleteLater();
    }
}

void Enemy2::hit(int dmg)
{
    hp = hp - dmg;
}




