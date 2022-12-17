#include "health.h"

Health::Health(QGraphicsItem *){
    // initialize the score to 0
    health =3;

    // draw the text
    //setPlainText(QString("Health: ") + QString::number(health)); // Health gets set to 3
    printhealth();
    printhp();
    //setDefaultTextColor(Qt::red);

}

void Health::decrease(){

    //if(health>0){
    health--;
    printhealth();
    //(QString("hp: ") + QString::number(getHP()));
  //  HP().printhp();
 //   printhp();
}

void Health::increase(){
    health++;
    printhealth();
   // HP().printhp();
   // printhp();
}

int Health::getHealth() const{
    return health;
}

void Health::increaseHP()
{
    setHP(1);
    printhealth();
    printhp();
}

void Health::decreaseHP()
{
    setHP(-1);
    printhealth();
    printhp();
}

void Health::printhealth()
{
    setPos(0,30);
    setFont(QFont("times",24));
    setDefaultTextColor(Qt::red);
    setPlainText(QString("Health: ") + QString::number(health));
}



