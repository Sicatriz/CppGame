#include "Buff1.h"
#include "bullet.h"
#include "game.h"

//extern game * game;
Buff1::Buff1(QGraphicsItem *parent): Buff() //With Qobject you say this Enemy is a object, Qgraphics gives the enemy a size.
{

    // set random start position
    int random_number = rand() % 1750;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/Hp.png"));


    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}




