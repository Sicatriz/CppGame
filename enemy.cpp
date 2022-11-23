#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Enemy::Enemy()
{
    // set random start position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // draw the rect
    setRect(0,0,100,100);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));  // use of THIS

    // timer for enemy movement
    timer->start(50);

}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+5);

    // when enemy is out of screen, free memory
    if(pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
