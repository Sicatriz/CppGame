#include "health.h"

// print health and hp
Health::Health(QGraphicsItem *){
    // initialize the score to 0
    health =3;

    printhealth();
    printhp();
}

// decrease health
void Health::decrease(){

    health--;
    printhealth();
}

// increase health
void Health::increase(){
    health++;
    printhealth();
}

// get health value
int Health::getHealth() const{
    return health;
}

// increase HP
void Health::increaseHP()
{
    setHP(1);
    printhealth();
    printhp();
}

// decrease HP
void Health::decreaseHP()
{
    setHP(-1);
    printhealth();
    printhp();
}

// print health on screen
void Health::printhealth()
{
    setPos(0,30);
    setFont(QFont("times",24));
    setDefaultTextColor(Qt::red);
    setPlainText(QString("Health: ") + QString::number(health));
}



