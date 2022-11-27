#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)  //With Qobject you say this Bullet is a object, Qgraphics gives the bullet a size.
{
    // draw the rect
    setRect(0,0,10,50);

    // connects
    QTimer * timer = new QTimer(this);
    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

void Bullet::move()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem * > colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n= colliding_items.size(); i < n; ++i)
    {
        //checks if the bullet hit a enemy.
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // increase the score
            game->score->increase();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // free memory
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    // move bullet up by pixels
    setPos(x(),y()-10);

    // when bullet is out of screen, free memory and remove bullet
    if(pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
