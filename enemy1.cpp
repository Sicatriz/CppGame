#include "enemy1.h"

//this is the base enemy
Enemy1::Enemy1(QGraphicsItem *, Health* h):Enemy()
{
    health = h;
    // set random start position
    int random_number = rand() % 1700;
    setPos(random_number, 0);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/WingShip_Spider.png"));

    hp = 5;
}

void Enemy1::move()
{
    // move enemy down
    setPos(x(),y()+1);

    // when enemy is out of screen, free memory
    if(pos().y() > 1000){

        scene()->removeItem(this);
        this->deleteLater();
    }
}

void Enemy1::hit(int dmg)
{
    hp = hp - dmg;
}



