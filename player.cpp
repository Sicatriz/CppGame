#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){
    bulletsound = new QMediaPlayer ();
    bulletsound->setSource(QUrl("qrc:/sounds/bulletSmall.wav"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left
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
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

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
    if((rand()%2)%2)
    {
        Enemy * enemy2 = new Enemy2();
        scene()->addItem(enemy2);
    }
    // create an enemy
    else
    {
        Enemy * enemy = new Enemy();
        scene()->addItem(enemy);
    }

}
