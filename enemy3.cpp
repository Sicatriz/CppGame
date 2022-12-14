#include "enemy3.h"
#include "score.h"
#include "bullet.h"

//this enemy is the small enemy
Enemy3::Enemy3(QGraphicsItem *, Health* h):Enemy()
{
    health = h;
    // set random start position
    int random_number = rand() % 1700;
    setPos(random_number, 0);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/Scorpion.png"));

    hp = 1;
}

void Enemy3::move()
{

    speed = getSpeed()+0.5;

    //speed = getSpeed() + (Score().getScore());

    // move enemy down
    setPos(x(),y()+speed);

    // when enemy is out of screen, free memory
    if(pos().y() > 1000){

        //decrease the health
        health->decrease();

        scene()->removeItem(this);
        this->deleteLater();
    }
}

void Enemy3::hit(int dmg)
{
    hp = hp - dmg;
}



