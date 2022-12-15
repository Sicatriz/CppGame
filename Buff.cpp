#include "Buff.h"
#include "bullet.h"
#include "game.h"

//extern game * game;
Buff::Buff(QGraphicsItem *parent): MovableObjects(parent) //With Qobject you say this Enemy is a object, Qgraphics gives the enemy a size.
{

    // set random start position
    int random_number = rand() % 1750;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/Hp.png"));


}

void Buff::move()
{
    // move enemy down
    setPos(x(),y()+1.5);

    // when enemy is out of screen, free memory
    if(pos().y() > this->scene()->height()+this->pixmap().height()){

        //TODO
        Game().delItem(this);
//        scene()->removeItem(this);
//        this->deleteLater();
    }


}
