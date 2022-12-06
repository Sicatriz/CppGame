#include "player.h"
#include "bullet.h"

#include "enemy.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"

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
