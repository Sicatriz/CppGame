#include "enemy2.h"

//this is the fast enemy
Enemy2::Enemy2(QGraphicsItem *parent):Enemy()
{
    // set random start position
    int random_number = rand() % 1850;
    setPos(random_number, 0);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/enemy2.png"));


    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    hp = 2;
}

void Enemy2::move(int speed)
{
    // move enemy down
    setPos(x(),y()+speed);

    // when enemy is out of screen, free memory
    if(pos().y() > 1100){

        //decrease the health
        //game->health->decrease();


        scene()->removeItem(this);
        this->deleteLater();
    }


}

void Enemy2::hit(int dmg)
{
    hp = hp - dmg;
}




