#include "bgdeckscruise.h"

extern Game * game;

BgdecksCruise::BgdecksCruise(QGraphicsItem *parent):BgDecks()
{
    // set random start position
    //int random_number = rand() % 1800;
    int random_width = 150 + (rand() % 1600);
    int random_rotation = rand() % 360;
    setPos(random_width, 0);
    setRotation(random_rotation);

    //gfx enemy type 2
    setPixmap(QPixmap(":/gfx/gfx/boatCruise.png"));


    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
//    QTimer * timerBoat = new QTimer(this);
//    connect(timerBoat,SIGNAL(timeout()),this,SLOT(move()));
//    timerBoat->start(500);
}

//void BgdecksCruise::move(int speed)
//{
//    // move enemy down
//    setPos(x(),y()+speed);

//    if(pos().y() > 1100)
//    {
//    scene()->removeItem(this);
//    this->deleteLater();
//    }
//}
