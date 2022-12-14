#include "meteor1.h"

Meteor1::Meteor1(QGraphicsItem *parent){
    int random_number = rand() % 1750;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/Stones2Filled_25.png"));
}

void Meteor1::move()
{
    // move enemy down
    setPos(x(),y()+2);

    // when enemy is out of screen, free memory
    if(pos().y() > 1100){

        //decrease the health


        scene()->removeItem(this);
        this->deleteLater();
  }
}
