#include "bullet.h"
#include "enemy.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"
//#include "meteor.h"
#include "meteor1.h"
#include "meteor2.h"
#include "meteor3.h"
#include "audio.h"

using namespace std;

namespace insemi
{

Bullet::Bullet(QGraphicsItem *parent): MovableObjects(parent)  //With Qobject you say this Bullet is a object, Qgraphics gives the bullet a size.
{
    setPixmap(QPixmap(":/gfx/gfx/laser.png")); //give bullet graphics
    QGraphicsPixmapItem::setOffset(2, 50);
}

Bullet::Bullet(QGraphicsItem* parent, int xas, int yas, Score* scoore): MovableObjects(parent)
{
    setPixmap(QPixmap(":/gfx/gfx/laser.png")); //give bullet graphics
    score = scoore;

    // Offset ship to mousecursor
    QGraphicsPixmapItem::setOffset(xas, yas);

    Audio* bulletSound = new Audio();
    bulletSound->playBullet(0.5);


}

void Bullet::move()
{
    // get a list of all the items currently colliding with this bullet

   // move bullet up by pixels
    setPos(x(),y()-5);

     //when bullet is out of screen, free memory and remove bullet
    if(pos().y() < 0)
    {
        // Game().delItem(this);
         //scene()->removeItem(this);
         this->deleteLater();
    }
}
}
