#include "player.h"
#include <QMouseEvent>
#include <qvideowidget.h>
#include <QMediaPlayer>


#include "meteor.h"
#include "meteor1.h"
#include "meteor2.h"
#include "meteor3.h"


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
//hier start meteor
}

void Player::collision()
{
    // get a list of all the items currently colliding with the player
    QList<QGraphicsItem * > colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the player and the enemy
    for (int i = 0, n= colliding_items.size(); i < n; ++i)
    {
        if ((typeid(*(colliding_items[i])) == typeid(meteor1)))
        {
            // increase the score
            //score->increase();

            // play hit sound
            QMediaPlayer * music = new QMediaPlayer();
            QAudioOutput * audioOutput = new QAudioOutput();
            music->setAudioOutput(audioOutput);
            connect(music, SIGNAL(positionChanged(background)), this, SLOT(positionChanged(0)));
            if(typeid(*(colliding_items[i])) == typeid(meteor1))
            {
                music->setSource(QUrl("qrc:/sounds/sounds/adios.wav"));
                music->audioOutput()->setVolume(1);
                music->play();
            }

            // remove them both
            scene->removeItem(colliding_items[i]);
            scene->removeItem(this);

            // free memory
            delete colliding_items[i];
            this->deleteLater();
        }
        //checks if the player hit a enemy./*
        if ((typeid(*(colliding_items[i])) == typeid(Enemy1) || typeid(*(colliding_items[i])) == typeid(Enemy2)) || typeid(*(colliding_items[i])) == typeid(Enemy3))
        {
            // increase the score
            //score->increase();

            // play hit sound
            QMediaPlayer * music = new QMediaPlayer();
            QAudioOutput * audioOutput = new QAudioOutput();
            music->setAudioOutput(audioOutput);
            connect(music, SIGNAL(positionChanged(background)), this, SLOT(positionChanged(0)));
            if(typeid(*(colliding_items[i])) == typeid(Enemy1))
            {
                music->setSource(QUrl("qrc:/sounds/sounds/adios.wav"));
                music->audioOutput()->setVolume(1);
                music->play();
            }
            else if (typeid(*(colliding_items[i])) == typeid(Enemy2))
            {
                music->setSource(QUrl("qrc:/sounds/sounds/gameOver_karen.wav"));
                music->audioOutput()->setVolume(1);
                music->play();
            }
            else
            {
                music->setSource(QUrl("qrc:/sounds/sounds/cry_karen.wav"));
                music->audioOutput()->setVolume(1);
                music->play();
            }

            // remove them both
            scene->removeItem(colliding_items[i]);
            scene->removeItem(this);

            // free memory
            delete colliding_items[i];
            this->deleteLater();
        }
        if ((typeid(*(colliding_items[i])) == typeid(meteor1) || (typeid(*(colliding_items[i])) == typeid(meteor3)))){
            scene->removeItem(colliding_items[i]);
             delete colliding_items[i];
        }
    }

}

void Player::spawn(){

    int ran = rand()%5;

    if(ran%5 == 0)
    {
        Enemy * enemy2 = new Enemy2(0, health);
        meteor * Meteor3 = new meteor3(0);
        scene->addItem(enemy2);
        scene->addItem(Meteor3);
    }
    // create an enemy
    else if(ran%2 == 0)
    {
        Enemy * enemy1 = new Enemy1(0, health);
        meteor * Meteor1 = new meteor1(0);
        scene->addItem(enemy1);
         scene->addItem(Meteor1);
    }
    else
    {
        Enemy * enemy3 = new Enemy3(0, health);
        //meteor * Meteor2 = new meteor2(0);
        scene->addItem(enemy3);
         //scene->addItem(Meteor2);
    }



}
// hier eindigt meteor
}




