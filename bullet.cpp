#include "bullet.h"
#include "enemy.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"


Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)  //With Qobject you say this Bullet is a object, Qgraphics gives the bullet a size.
{
    setPixmap(QPixmap(":/gfx/gfx/laser.png")); //give bullet graphics
    QGraphicsPixmapItem::setOffset(2, 50);

    QMediaPlayer * music = new QMediaPlayer(); //adding bullet sound
    QAudioOutput * audioOutput = new QAudioOutput();
    music->setAudioOutput(audioOutput);
    connect(music, SIGNAL(positionChanged(background)), this, SLOT(positionChanged(0)));
    music->setSource(QUrl("qrc:/sounds/sounds/shoot1.wav"));
    //audioOutput->setVolume(100);
    music->audioOutput()->setVolume(0.5);
    music->play();
    // connects
    QTimer * timer = new QTimer(this);
    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

Bullet::Bullet(int xas, int yas, Score* scoore)
{
    setPixmap(QPixmap(":/gfx/gfx/laser.png")); //give bullet graphics
    score = scoore;

    QGraphicsPixmapItem::setOffset(xas, yas);

    QMediaPlayer * music = new QMediaPlayer(); //adding bullet sound
    QAudioOutput * audioOutput = new QAudioOutput();
    music->setAudioOutput(audioOutput);
    connect(music, SIGNAL(positionChanged(background)), this, SLOT(positionChanged(0)));
    music->setSource(QUrl("qrc:/sounds/sounds/shoot1.wav"));
    //audioOutput->setVolume(100);
    music->audioOutput()->setVolume(0.5);
    music->play();

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
        //checks if the bullet hit a enemy./*
        if ((typeid(*(colliding_items[i])) == typeid(Enemy1) || typeid(*(colliding_items[i])) == typeid(Enemy2)) || typeid(*(colliding_items[i])) == typeid(Enemy3))
        {
            // increase the score

            Enemy* enemy = (Enemy*) colliding_items[i];
            enemy->hit(1);



                //dit is een test lijn


            // play hit sound
            QMediaPlayer * music = new QMediaPlayer();
            QAudioOutput * audioOutput = new QAudioOutput();
            music->setAudioOutput(audioOutput);
            connect(music, SIGNAL(positionChanged(background)), this, SLOT(positionChanged(0)));
            music->setSource(QUrl("qrc:/sounds/sounds/Explosion.wav"));
            //audioOutput->setVolume(100);
            music->audioOutput()->setVolume(1);
            music->play();

            // remove them both
            //scene()->removeItem(colliding_items[i]);
            if(enemy->destroy()){
               scene()->removeItem(colliding_items[i]);
               enemy->deleteLater();
               score->increase();
             }

            scene()->removeItem(this);


            // free memory
            this->deleteLater();
           // music->deleteLater();
           // audioOutput->deleteLater();
        }
    }

    // move bullet up by pixels
    setPos(x(),y()-10);

     //when bullet is out of screen, free memory and remove bullet
    if(pos().y() < -50)
    {
        scene()->removeItem(this);
        this->deleteLater();

    }
}
