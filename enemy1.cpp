#include "enemy1.h"

using namespace insemi;

// 5 HP enemy
Enemy1::Enemy1(QGraphicsItem *, Health* h):Enemy()
{
    health = h;
    // set random start position
    int random_number = rand() % 1600;
    setPos(random_number, 0);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/WingShip_Spider.png"));
    setRotation(180);

    hp = 5;
}

// enemy movement
void Enemy1::move()
{
    speed = getSpeed();

    // move enemy down
    setPos(x(),y()+speed);

    // when enemy is out of screen, free memory
    if(pos().y() > 1000){

        scene()->removeItem(this);
        this->deleteLater();
    }
}

// enemy hp decrease
void Enemy1::hit(int dmg)
{
    hp = hp - dmg;
}



