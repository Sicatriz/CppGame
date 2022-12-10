#include "bgdecks.h"
#include "game.h"

extern Game * game;

BgDecks::BgDecks(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    // set random start position
    int random_width = 150 + (rand() % 1600);

    setPos(random_width, 20);


    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/boatSmall.png"));

    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(500);

}

void BgDecks::move(int speed)
{
    // move enemy down
    setPos(x(),y()+speed);

    // when enemy is out of screen, free memory
    if(pos().y() > 1100){

        scene()->removeItem(this);
        this->deleteLater();
    }
}


