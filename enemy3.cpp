#include "enemy3.h"
#include "game.h"

extern Game * game;

Enemy3::Enemy3(QGraphicsItem *parent):Enemy()
{
    // set random start position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/enemy3.png"));


    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(250);
}

void Enemy3::move(int speed)
{
    // move enemy down
    setPos(x(),y()+speed);

    // when enemy is out of screen, free memory
    if(pos().y() > 600){

        //decrease the health
        game->health->decrease();


        scene()->removeItem(this);
        delete this;
    }
}

