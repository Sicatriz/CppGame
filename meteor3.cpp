#include "meteor3.h"

Meteor3::Meteor3(QGraphicsItem *parent){
    int random_number = rand() % 1750;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/Stones2Filled_25.png"));
}

void Meteor3::move()
{
    if (i == 0){
        int select = rand()%2;
        int ran = rand()%7;
       ranused = ran;
       selectused = select;
       i++;
    }
    // move enemy down
    if(selectused == 1){
     setPos(x()-ranused,y()+speed);
    }else{
         setPos(x()+ranused,y()+speed);
     }
// when enemy is out of screen, free memory
    if(pos().y() > 1100){

    //decrease the health

    scene()->removeItem(this);
    this->deleteLater();
}
}

