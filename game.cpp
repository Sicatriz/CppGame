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
    scene->addItem(player);






    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);



    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    timer->start(2000);

    // play background sound
    Audio* backgroundMusic = new Audio();
    backgroundMusic->playBackgroundMusic();

//    // connects player move signal
//    QTimer * timer2 = new QTimer();
//    connect(timer2,SIGNAL(timeout()),move,SLOT(motion()));
//    timer2->start(15);
//    setMouseTracking(true);

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
        if ((typeid(*(colliding_items[i])) == typeid(Enemy1) || typeid(*(colliding_items[i])) == typeid(Enemy2)) || typeid(*(colliding_items[i])) == typeid(Enemy3))
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
                //
                health->decrease();
                health->setHP();
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

void Game::keyPressEvent(QKeyEvent *event)
{
    // move the player left and right
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
//    else
    if (event->key() == Qt::Key_Space)
    {
        // create a bullet



        Bullet * bullet1 = new Bullet(20, 30, score);
        Bullet * bullet2 = new Bullet(70, 30, score);

        bullet1->setPos(player->x(),player->y());
        bullet2->setPos(player->x(),player->y());
        scene->addItem(bullet1);
        scene->addItem(bullet2);
    }
}

void Game::spawnEnemy(){

    int ran = rand()%5;

    if(ran%5 == 0)
    {
        Enemy * enemy2 = new Enemy2(0, health);
        scene->addItem(enemy2);
    }
    // create an enemy
    else if(ran%2 == 0)
    {
        Enemy * enemy1 = new Enemy1(0, health);
        scene->addItem(enemy1);
    }
    else
    {
        Enemy * enemy3 = new Enemy3(0, health);
        scene->addItem(enemy3);
    }



}

