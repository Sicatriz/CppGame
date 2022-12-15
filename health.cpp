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
    printhp();
}

void Health::increase(){
    health++;
    printhealth();
    printhp();
}

int Health::getHealth(){
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
    setPlainText(QString("Health: ") + QString::number(health));
}



