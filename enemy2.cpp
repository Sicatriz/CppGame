#include "enemy2.h"

extern Game * game;

Enemy2::Enemy2(QGraphicsItem *parent):Enemy()
{
    // set random start position
    int random_number = rand() % 700;
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
}

void Enemy2::move(int speed)
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

void Enemy2::hit(int dmg)
{
    hp = hp - dmg;
}

void Enemy2::destroy(){
    if(hp <= 0){
    this->deleteLater();
    }
}

