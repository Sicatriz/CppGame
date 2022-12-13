#include "hp.h"

HP::HP(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    hp = 4;

    // draw the text
    /*setPlainText(QString("HP: ") + QString::number(hp)); // Health gets set to 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));*/
}


void HP::decreaseHP()
{
    // 1 HEALTH = 4 HP

    hp--;
   // setPlainText(QString("Health: ") + QString::number(hp)); // Health gets reduced

}

int HP::getHP()
{
    return hp;
}

void HP::setHP()
{
    hp = 4;

}
