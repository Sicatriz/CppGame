#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    // set random start position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // draw the rect
    setRect(0,0,100,100);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));  // use of THIS

    // timer for enemy movement
    timer->start(50);

}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+5);

    // when enemy is out of screen, free memory
    if(pos().y() > 600){

        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
