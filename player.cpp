#include "player.h"
#include "game.h"

#include <QMouseEvent>
#include <qvideowidget.h>
#include <QMediaPlayer>



Player::Player(QGraphicsItem *parent): MovableObjects(parent)

{

    this->QGraphicsPixmapItem::setPixmap(QPixmap(":/gfx/gfx/Starship_C.png")); //playerskin
}

void Player::setWannaBeX(int x)
{
    wannaBeX = x;
}

void Player::setWannaBeY(int y)
{
    wannaBeY = y;
}

void Player::move()
{
    int coef = 19;
    setPos((wannaBeX*(20-coef)+pos().x()*coef)/20, (wannaBeY*(20-coef)+pos().y()*coef)/20 );

   Game collision();
}

//void Player::collision()
//{
//    // get a list of all the items currently colliding with the player
//    QList<QGraphicsItem * > colliding_items = collidingItems();

//    // if one of the colliding items is an Enemy, destroy both the player and the enemy
//    for (int i = 0, n= colliding_items.size(); i < n; ++i)
//    {
//        //checks if the player hit a enemy./*
//        if ((typeid(*(colliding_items[i])) == typeid(Enemy1) || typeid(*(colliding_items[i])) == typeid(Enemy2)) || typeid(*(colliding_items[i])) == typeid(Enemy3))
//        {
//            health->decreaseHP();
//            if((health->getHP() != 0 && health->getHealth() != 0) || (health->getHP() == 0 && health->getHealth() != 0) || (health->getHP() != 0 && health->getHealth() == 0))
//            {
//                // play shipcollision sound
//                Audio* shipCollision = new Audio();
//                shipCollision->playShipCollisionSound();
//            }

//            if(health->getHP() == 0 && health->getHealth() != 0)
//            {
//                //
//                health->decrease();
//                health->setHP(4);
//            }
//            else if(health->getHealth() == 0 && health->getHP() == 0)
//            {
//                // play background sound
//                Audio* gameOverSound = new Audio();
//                gameOverSound->playGameOver();

//                // remove them both
//                scene->removeItem(colliding_items[i]);
//                scene->removeItem(this);

//                // free memory
//                //   delete colliding_items[i];
//                this->deleteLater();
//                this->score->deleteLater();
//                this->health->deleteLater();
//                //  delete this;

//            }


//            // remove them both
//            scene->removeItem(colliding_items[i]);
//            delete(colliding_items[i]);
//        }
//        if ((typeid(*(colliding_items[i])) == typeid(Buff1))){

//            if(health->getHP()== 4)
//            {

//            }else{
//                health->increaseHP();

//            }

//            scene->removeItem(colliding_items[i]);
//            delete(colliding_items[i]);

//        }
//    }
//}

//void Player::spawn(){
//    srand(time(NULL));
//    int ran = rand()%5;

//    if(ran%5 == 0)
//    {
//        Enemy * enemy2 = new Enemy2(0, health);
//        scene->addItem(enemy2);
//    }
//    // create an enemy
//    else if(ran%2 == 0)
//    {
//        Enemy * enemy1 = new Enemy1(0, health);
//        Buff * buff1 = new Buff1(0);
//        scene->addItem(enemy1);
//        scene->addItem(buff1);
//    }
//    else
//    {
//        Enemy * enemy3 = new Enemy3(0, health);
//        scene->addItem(enemy3);
//    }








