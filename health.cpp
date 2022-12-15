#include "health.h"

Health::Health(QGraphicsItem *){
    // initialize the score to 0
    health =3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health gets set to 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",30));
    setPos(10,30);
}

void Health::decrease(){

    //if(health>0){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health gets reduced
   // }
}

void Health::increase(){
    health++;
     setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}

