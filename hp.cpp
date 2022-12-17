#include "hp.h"

using namespace insemi;

// standard HP value
HP::HP(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    hp = 4;
}

// decrease HP
void HP::decreaseHP()
{
    // 1 HEALTH = 4 HP

    hp--;
    setPos(10,50);
}

// increase HP
void HP::increaseHP(){
    hp++;
}

// get HP value
int HP::getHP() const
{
    return hp;
}

// set HP value
void HP::setHP(int i)
{
    hp += i;
}

// print HP on screen
void HP::printhp()
{
    setPos(x(),60);
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",24));
    setPlainText(QString("Hit points: ") + QString::number(hp));
}


