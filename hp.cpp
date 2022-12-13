#include "hp.h"

HP::HP(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    hp = 4;
}


void HP::decreaseHP()
{
    // 1 HEALTH = 4 HP

    hp--;
}

int HP::getHP()
{
    return hp;
}

void HP::setHP()
{
    hp = 4;

}
