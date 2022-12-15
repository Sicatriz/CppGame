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

//Bullet::Bullet(QGraphicsItem *parent): MovableObjects(parent)  //With Qobject you say this Bullet is a object, Qgraphics gives the bullet a size.
//{
  //  setPixmap(QPixmap(":/gfx/gfx/laser.png")); //give bullet graphics
    //QGraphicsPixmapItem::setOffset(2, 50);

    // connects
    //QTimer * timer = new QTimer(this);
    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //timer->start(50);

//}

Bullet::Bullet(QGraphicsItem* parent, int xas, int yas, Score* scoore): MovableObjects(parent)
{
    setPixmap(QPixmap(":/gfx/gfx/laser.png")); //give bullet graphics
    score = scoore;

    // Offset ship to mousecursor
    QGraphicsPixmapItem::setOffset(xas, yas);

    Audio* bulletSound = new Audio();
    bulletSound->playBullet();

    // connects
    QTimer * timer = new QTimer(this);

//  Connects timer to public slot move .
//  timer is there for bullet movement, this changes the speed of the bullet.
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
        //checks if the bullet hit a enemy./*
        if ((typeid(*(colliding_items[i])) == typeid(Enemy1) || typeid(*(colliding_items[i])) == typeid(Enemy2)) || typeid(*(colliding_items[i])) == typeid(Enemy3))
        {
            Enemy* enemy = (Enemy*) colliding_items[i];
            enemy->hit(1);

            Audio* bulletHitSound = new Audio();
            bulletHitSound->playBulletHit();

            // remove them both
            if(enemy->destroy()){
               scene()->removeItem(colliding_items[i]);
               enemy->deleteLater();
               score->increase();
             }
            //remove bullet
            scene()->removeItem(this);

            // free memory
            this->deleteLater();
        }
//      else if ((typeid(*(colliding_items[i])) == typeid(Meteor1) || (typeid(*(colliding_items[i])) == typeid(Meteor3)))){
//            scene()->removeItem(this);
//            this->deleteLater();
//        }
    }

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
