#include "player.h"
#include <QMouseEvent>
#include <qvideowidget.h>
#include <QMediaPlayer>
#include "enemy.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"
#include "game.h"
#include "score.h"
#include "audio.h"
#include "bullet.h"


Player::Player(QGraphicsItem *parent): MovableObjects(parent)
{

    this->QGraphicsPixmapItem::setPixmap(QPixmap(":/gfx/gfx/Starship_C.png")); //playerskin

//    //startposition
//    this->QGraphicsPixmapItem::setScale(1);
//   // this->scale();
//    this->setPos(scene->width()/2, scene->height()- 150);
//    // make the player focusable and set it to be the current focus
//    this->setFlag(QGraphicsItem::ItemIsFocusable);
//    this->setFocus();
//    // add the player to the scene
//    scene->addItem(this);

//    // create the score/health
//    score = new Score();
//    scene->addItem(score);
//    health = new Health();
//    health->setPos(health->x(),health->y()+25);
//    scene->addItem(health);
}

//void Player::keyPressEvent(QKeyEvent *event)
//{
//    // move the player left and right
//    if (event->key() == Qt::Key_Left){
//        if (pos().x() > 0)
//        setPos(x()-10,y());
//    }
//    else if (event->key() == Qt::Key_Right){
//        if (pos().x() + 100 < 1920)
//        setPos(x()+10,y());
//    }
//    // move the player up and down
//    if (event->key() == Qt::Key_Up){
//        if (pos().y() > 0)
//        setPos(x(),y()-10);
//    }
//    else if (event->key() == Qt::Key_Down){
//        if (pos().y() + 100 < 900)
//        setPos(x(),y()+10);
//    }
//    // shoot with the spacebar
//    else if (event->key() == Qt::Key_Space)
//    {

//        // create a bullet

//        Bullet * bullet1 = new Bullet(20, 30, score);
//        Bullet * bullet2 = new Bullet(70, 30, score);

//        bullet1->setPos(x(),y());
//        bullet2->setPos(x(),y());
//        scene->addItem(bullet1);
//        scene->addItem(bullet2);
//    }
//}

void Player::setWannaBeX(int x)
{
    wannaBeX = x;
}

void Player::setWannaBeY(int y)
{
    wannaBeY = y;
}

//void Player::mousePressEvent(QMouseEvent *event)
//{
//    Bullet * bullet = new Bullet();
//    bullet->setPos(x(),y());
//    scene()->addItem(bullet);
//}

void Player::move()
{
    int coef = 19;
    setPos((wannaBeX*(20-coef)+pos().x()*coef)/20, (wannaBeY*(20-coef)+pos().y()*coef)/20 );
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
//                health->setHP();
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
//        scene->addItem(enemy1);
//    }
//    else
//    {
//        Enemy * enemy3 = new Enemy3(0, health);
//        scene->addItem(enemy3);
//    }



//}


