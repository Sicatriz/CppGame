#include "enemy2.h"

using namespace insemi;

//this is the fast enemy
Enemy2::Enemy2(QGraphicsItem *, Health* h):Enemy()
{
    health = h;
    // set random start position
    int random_number = rand() % 1600;
    setPos(random_number, 0);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/Buggy_LightPurple.png"));

    hp = 2;
}

void Enemy2::move()
{
    speed = getSpeed()+1.5;

    // move enemy down
    setPos(x(),y()+speed);

    // when enemy is out of screen, free memory
    if(pos().y() > 1000){

        //decrease the health
        health->decrease();

        // clear memory
        scene()->removeItem(this);
        this->deleteLater();
    }
}

// enemy HP decrease
void Enemy2::hit(int dmg)
{
    hp = hp - dmg;
}




