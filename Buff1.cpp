#include "Buff1.h"
#include "bullet.h"


//extern game * game;
Buff1::Buff1(QGraphicsItem *): Buff() //With Qobject you say this Enemy is a object, Qgraphics gives the enemy a size.
{

    // set random start position
    int random_number = rand() % 1700;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/Hp.png"));

}

void Buff1::move()
{
    speed = getSpeed();
    // move enemy downs
    setPos(x(),y()+speed);

        // when enemy is out of screen, free memory
        if(pos().y() > 1000){

            scene()->removeItem(this);
            this->deleteLater();
    }
}


