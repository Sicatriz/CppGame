#include "hp.h"

HP::HP(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    hp = 4;

    setPlainText(QString("Hit points: ") + QString::number(hp)); // Score gets set to 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",24));
    setPos(10,50);
}

void HP::decreaseHP()
{
    // 1 HEALTH = 4 HP

    hp--;
}
void HP::increaseHP(){
    hp++;
}

int HP::getHP()
{
    return hp;
}

void HP::setHP(int i)
{
    hp += i;

}

