#include "enemy.h"

Enemy::Enemy(QGraphicsItem *parent, Health* h): QObject(), QGraphicsPixmapItem(parent) //With Qobject you say this Enemy is a object, Qgraphics gives the enemy a size.
{
    health = h;
    // set random start position
    int random_number = rand() % 1750;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/WingShip_Spider.png"));


    /***\
    Connects timer to public slot move .
    timer is there for bullet movement, this changes the speed of the bullet.
    \***/
    QTimer * timer = new QTimer(this);
    timer->start(50);

}

void Enemy::move(int speed)
{
    // move enemy down
    setPos(x(),y()+speed);

    // when enemy is out of screen, free memory
    if(pos().y() > 1100){

        //decrease the health
        health->decrease();

        scene()->removeItem(this);
        this->deleteLater();
    }


}

void Enemy::hit(int dmg){
    hp = hp - dmg;
}

bool Enemy::destroy(){
    if(hp <= 0){
    this->deleteLater();
        return true;
    }
    return false;
}

