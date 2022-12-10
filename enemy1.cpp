#include "enemy1.h"

extern Game * game;

Enemy1::Enemy1(QGraphicsItem *parent):Enemy()
{
    // set random start position
    int random_number = rand() % 1850;
    setPos(random_number, 0);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/enemy1.png"));


    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(200);
    hp = 5;
}

void Enemy1::move(int speed)
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

void Enemy1::hit(int dmg)
{
    hp = hp - dmg;
}



