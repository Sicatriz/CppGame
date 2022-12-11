#include "enemy3.h"

extern Game * game;
//this enemy is the small enemy
Enemy3::Enemy3(QGraphicsItem *parent):Enemy()
{
    // set random start position
    int random_number = rand() % 1750;
    setPos(random_number, 0);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/Scorpion.png"));


    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(250);
    hp = 1;
}

void Enemy3::move(int speed/*, Game* game*/)
{
    // move enemy down
    setPos(x(),y()+speed);

    // when enemy is out of screen, free memory
    if(pos().y() > 1100){

        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        this->deleteLater();
    }
}

void Enemy3::hit(int dmg)
{
    hp = hp - dmg;
}



