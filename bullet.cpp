#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"


Bullet::Bullet()
{
    // draw the rect
    setRect(0,0,10,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));  // use of THIS

    // timer for bullet movement
    timer->start(50);

}

void Bullet::move()
{
    // if bullet collision, destroy both
    QList<QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n= colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // free memory
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(),y()-10);

    // when bullet is out of screen, free memory
    if(pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
