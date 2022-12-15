#include "game.h"
#include <QMouseEvent>
#include "audio.h"
#include "player.h"
#include "audio.h"
#include "movableObjects.h"
#include "bullet.h"
#include <QPixmap>
#include "enemy.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"
#include "meteor.h"
#include "meteor1.h"
//#include "meteor2.h"
#include "meteor3.h"
#include "Buff.h"
#include "Buff1.h"
#include "Buff2.h"
#include "score.h"
#include "hp.h"
#include "health.h"
Game::Game(QWidget *)
{
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1800,1000); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/gfx/gfx/bg52.png"))); //set background image

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1800,1000);  //set the size of the window

    // Game tick timer
    moveTimer = new QTimer();
    moveTimer->start(10);


    // check player collision
    QTimer * timerCollision = new QTimer();
    QObject::connect(timerCollision,SIGNAL(timeout()),this,SLOT(collision()));
    timerCollision->start(10);

    // create the player
    player = new Player();
    addItem(player);
    //startposition
    player->QGraphicsPixmapItem::setScale(1);
   // this->scale();
    player->setPos(scene->width()/2, scene->height()- 150);
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    // add the player to the scene
    //scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    scene->addItem(health);


    // spawn enemies
    QTimer * timerEnemy = new QTimer();
    QObject::connect(timerEnemy,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    timerEnemy->start(2000);

    // spawn meteors
    QTimer * timerMeteor = new QTimer();
    QObject::connect(timerMeteor,SIGNAL(timeout()),this,SLOT(spawnMeteor()));
    timerMeteor->start(8000);

    // spawn buff
    QTimer * timerBuff = new QTimer();
    QObject::connect(timerBuff,SIGNAL(timeout()),this,SLOT(spawnBuff()));
    timerBuff->start(12000);

    // play background sound
    Audio* backgroundMusic = new Audio();
    backgroundMusic->playBackgroundMusic();

    show();
}

void Game::collision()
{
    // get a list of all the items currently colliding with the player
    QList<QGraphicsItem * > colliding_items = player->collidingItems();

    // if one of the colliding items is an Enemy, destroy both the player and the enemy
    for (int i = 0, n= colliding_items.size(); i < n; ++i)
    {
        //checks if the player hit a enemy./*
        if ((typeid(*(colliding_items[i])) == typeid(Enemy1) || typeid(*(colliding_items[i])) == typeid(Enemy2)) || typeid(*(colliding_items[i])) == typeid(Enemy3) || typeid(*(colliding_items[i])) == typeid(Meteor1) || typeid(*(colliding_items[i])) == typeid(Meteor3) )
        {
            health->decreaseHP();
            if((health->getHP() != 0 && health->getHealth() != 0) || (health->getHP() == 0 && health->getHealth() != 0) || (health->getHP() != 0 && health->getHealth() == 0))
            {
                // play shipcollision sound
                Audio* shipCollision = new Audio();
                shipCollision->playShipCollisionSound();
            }

            if(health->getHP() == 0 && health->getHealth() != 0)
            {
                health->decrease();
                health->setHP(4);
            }
            else if(health->getHealth() == 0 && health->getHP() == 0)
            {
                // play background sound
                Audio* gameOverSound = new Audio();
                gameOverSound->playGameOver();

                // remove them both
                scene->removeItem(colliding_items[i]);
                scene->removeItem(player);

                // free memory
                //   delete colliding_items[i];
                this->deleteLater();
                this->score->deleteLater();
                this->health->deleteLater();
                //  delete this;
            }

            // remove them both
            scene->removeItem(colliding_items[i]);
            delete(colliding_items[i]);
        }
        else if ((typeid(*(colliding_items[i])) == typeid(Buff1) ) ){
            health->increaseHP();
            scene->removeItem(colliding_items[i]);
            delete(colliding_items[i]);
        }
        else if ((typeid(*(colliding_items[i])) == typeid(Buff2) ) ){
            health->increase();
            scene->removeItem(colliding_items[i]);
            delete(colliding_items[i]);
        }
    }
}

void Game::mouseMoveEvent(QMouseEvent *mouse)
{
    player->setWannaBeX(mouse->pos().x()-50);
    player->setWannaBeY(mouse->pos().y()-25);
}

void Game::addItem(MovableObjects * item)
{
    scene->addItem(item);
    QObject::connect(moveTimer,SIGNAL(timeout()),item,SLOT(move()));
}

void Game::delItem(MovableObjects * item)
{
    scene->removeItem(item);
    item->deleteLater();
}

void Game::getLevel()
{
        if( score->getScore() < 20)
        {
            level = 1;
        }
        else if(score->getScore() > 19 && score->getScore() < 40)
        {
            level = 2;
        }
        else if(score->getScore() >39 && score->getScore() < 60)
        {
            level = 3;
        }
        else if(score->getScore() >59 && score->getScore() < 80)
        {
            level = 4;
        }
        else if(score->getScore() >79 && score->getScore() < 100)
        {
            level = 5;
        }
        else if(score->getScore() >99 && score->getScore() < 120)
        {
            level = 6;
        }
        else if(score->getScore() >119 && score->getScore() < 140)
        {
            level = 7;
        }
        else if(score->getScore() >139 && score->getScore() < 160)
        {
            level = 8;
        }
        else if(score->getScore() >159 && score->getScore() < 180)
        {
            level = 9;
        }
        else
        {
            level = 10;
        }
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet * bullet1 = new Bullet(0, 20, 30, score);
        Bullet * bullet2 = new Bullet(0,70, 30, score);

        bullet1->setPos(player->x(),player->y());
        bullet2->setPos(player->x(),player->y());
        this->addItem(bullet1);
        this->addItem(bullet2);
    }
}

void Game::spawnEnemy(){

    int ran = rand()%5;

    getLevel();

    switch (level) {
    case 1:
        if(ran%8 == 0)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
        }
        // create an enemy
        else if(ran%5 == 1)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);

        }
        break;
    case 2:
        if(ran%8 == 0)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
        }
        // create an enemy
        else if(ran%5 == 1)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }

        break;
    case 3:
        if(ran%8 == 0 || ran%8 == 2)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
        }
        // create an enemy
        else if(ran%5 == 1)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }

        break;
    case 4:
        if(ran%8 == 0 || ran%8 == 2)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
        }
        // create an enemy
        else if(ran%5 == 1 || ran%5 == 3)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        break;
    case 5:
        if(ran%8 == 0 || ran%8 == 2)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        // create an enemy
        else if(ran%5 == 1 || ran%5 == 3)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        break;
    case 6:
        if(ran%8 == 0 || ran%8 == 2)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        // create an enemy
        else if(ran%5 == 1 || ran%5 == 3)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
        }
        break;
    case 7:
        if(ran%8 == 0 || ran%8 == 2 || ran%8 == 7)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        // create an enemy
        else if(ran%5 == 1 || ran%5 == 3)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
        }
        break;
    case 8:
        if(ran%8 == 0 || ran%8 == 2 || ran%8 == 7)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        // create an enemy
        else if(ran%5 == 1 || ran%5 == 3)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
        }
        break;
        break;
    case 9:
        if(ran%8 == 0 || ran%8 == 2 || ran%8 == 7)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        // create an enemy
        else if(ran%5 == 1 || ran%5 == 3 || ran%5 == 5)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
        }
        break;
    case 10:
        if(ran%8 == 0 || ran%8 == 2 || ran%8 == 7)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
        }
        // create an enemy
        else if(ran%5 == 1 || ran%5 == 3 || ran%5 == 5)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
        }
        break;
    default:
        if(ran%5 == 0)
        {
            Enemy * enemy2 = new Enemy2(0, health);
           // scene->addItem(enemy2);
            this->addItem(enemy2);
        }
        // create an enemy
        else if(ran%2 == 0)
        {
            Enemy * enemy1 = new Enemy1(0, health);
           // scene->addItem(enemy1);
            this->addItem(enemy1);
        }
        else
        {
            Enemy * enemy3 = new Enemy3(0, health);
           // scene->addItem(enemy3);
            this->addItem(enemy3);

        }
        break;
    }
}

void Game::spawnMeteor(){

    int ran = rand()%5;

    if(ran%5 == 0)
    {
        Meteor * meteor3 = new Meteor3(0);
        this->addItem(meteor3);
    }
    // create an Meteor
    else if(ran%2 == 0)
    {
        Meteor * meteor1 = new Meteor1(0);
        this->addItem(meteor1);
    }


}

void Game::spawnBuff(){

            int ran =  rand()%5;

            if(ran%5 == 0)
            {
                Buff * buff = new Buff1(0);
                this->addItem(buff);
         }
         else if(ran%2 == 0){
                Buff * buff2 = new Buff2(0);
                this->addItem(buff2);
            }

}
