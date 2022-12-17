#include "meteor.h"

using namespace insemi;

// meteor random spawnposition and sprite
Meteor::Meteor(QGraphicsItem *parent): MovableObjects(parent)
{
    // set random start position
    int random_number = rand() % 1600;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/WingShip_Spider.png"));
}

// meteor movement and deletion
void Meteor::move()
{
    // move enemy down
    setPos(x(),y()+0.2);

    // when enemy is out of screen, free memory
    if(pos().y() > 1100 || pos().x() > 1800){

        //decrease the health
        scene()->removeItem(this);
        this->deleteLater();
    }
}

