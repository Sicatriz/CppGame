#include "meteor1.h"

Meteor1::Meteor1(QGraphicsItem *){
    int random_number = rand() % 1750;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/Stones2Filled_25.png"));
}

void Meteor1::move()
{
    // move enemy down
    setPos(x(),y()+0.5);

    // when enemy is out of screen, free memory
    if(pos().y() > 1100 || pos().x() > 1800 || pos().x() < 0){

        scene()->removeItem(this);
        this->deleteLater();
  }
}
