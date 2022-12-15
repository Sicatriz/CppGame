#include "enemy.h"
#include "bullet.h"

Enemy::Enemy(QGraphicsItem *parent): MovableObjects(parent) //With Qobject you say this Enemy is a object, Qgraphics gives the enemy a size.
{
  //  health = h;
    // set random start position
    int random_number = rand() % 1600;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/WingShip_Spider.png"));

}

void Enemy::move()
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

