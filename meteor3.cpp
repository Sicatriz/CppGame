#include "meteor3.h"

using namespace insemi;

// meteor random spawnposition and sprite
Meteor3::Meteor3(QGraphicsItem *){
    int random_number = rand() % 1600;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/Stones2Filled_25.png"));
}

// meteor movement and deletion
void Meteor3::move()
{
    if (i == 0){
        int select = rand()%2;
        int ran = rand()%7;
       ranused = ran;
       selectused = select;
       i++;
    }
    // move meteor down
    if(selectused == 1){
     setPos(x()-(ranused/10),y()+0.4);
    }else{
         setPos(x()+(ranused/10),y()+0.2);
     }
// when enemy is out of screen, free memory
    if(pos().y() > 1100 || pos().x() > 1800 || pos().x() < 0){

    scene()->removeItem(this);
    this->deleteLater();
}
}

