#include "player.h"
#include "bullet.h"

#include "enemy.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"
#include <QMouseEvent>
#include "game.h"

//extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer ();
    bulletsound->setSource(QUrl("qrc:/sounds/sounds/bulletSmall.wav"));


}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // move the player up and down
    if (event->key() == Qt::Key_Up){
        if (pos().y() > 0)
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 < 600)
        setPos(x(),y()+10);
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet1 = new Bullet(2, 50);
        Bullet * bullet2 = new Bullet(90, 50);

        bullet1->setPos(x(),y());
        bullet2->setPos(x(),y());
        scene()->addItem(bullet1);
        scene()->addItem(bullet2);
        // play bulletsound
        if (bulletsound->playbackState() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->playbackState() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }
    }
}

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

void Player::motion()
{

//    double coef = sqrt(pow(wannaBeX-pos().x(), 2)+pow(wannaBeY-pos().y(), 2));
//    if( coef > 19 )
//        coef = 19;
//    else
//        coef = 9;
    int coef = 19;
    setPos((wannaBeX*(20-coef)+pos().x()*coef)/20, (wannaBeY*(20-coef)+pos().y()*coef)/20 );
    collision();

}

void Player::collision()
{
    // get a list of all the items currently colliding with the player
    QList<QGraphicsItem * > colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the player and the enemy
    for (int i = 0, n= colliding_items.size(); i < n; ++i)
    {
        //checks if the player hit a enemy./*
        if ((typeid(*(colliding_items[i])) == typeid(Enemy1) || typeid(*(colliding_items[i])) == typeid(Enemy2)) || typeid(*(colliding_items[i])) == typeid(Enemy3))
        {
            // increase the score
          //  game->score->increase();

            // play hit sound
            QMediaPlayer * music = new QMediaPlayer();
            QAudioOutput * audioOutput = new QAudioOutput();
            music->setAudioOutput(audioOutput);
            connect(music, SIGNAL(positionChanged(background)), this, SLOT(positionChanged(0)));
            music->setSource(QUrl("qrc:/sounds/sounds/gameOver.wav"));
            audioOutput->setVolume(100);
            music->audioOutput()->setVolume(100);
            music->play();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // free memory
            delete colliding_items[i];
            delete this;
        }
    }
}

void Player::spawn(){
    srand(time(NULL));
    int ran = rand()%5;

    if(ran%5 == 0)
    {
        Enemy * enemy2 = new Enemy2();
        scene()->addItem(enemy2);
    }
    // create an enemy
    else if(ran%2 == 0)
    {
        Enemy * enemy1 = new Enemy1();
        scene()->addItem(enemy1);
    }
    else
    {
        Enemy * enemy3 = new Enemy3();
        scene()->addItem(enemy3);
    }

}
