#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

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
    // move bullet up
    setPos(x(),y()-10);

    // when bullet is out of screen, free memory
    if(pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
