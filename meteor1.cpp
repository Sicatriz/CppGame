#include "meteor1.h"
#include "bullet.h"
#include "game.h"

meteor1::meteor1(QGraphicsItem *parent){
    int random_number = rand() % 1750;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/WingShip_Spider.png"));


    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void meteor1::move(int speed)
{
    // move enemy down
    setPos(x(),y()+speed);

    // when enemy is out of screen, free memory
    if(pos().y() > 1100){

        //decrease the health


        scene()->removeItem(this);
        this->deleteLater();
  }
}
