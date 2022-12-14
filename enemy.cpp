#include "enemy.h"
#include "bullet.h"

Enemy::Enemy(QGraphicsItem *parent): MovableObjects(parent) //With Qobject you say this Enemy is a object, Qgraphics gives the enemy a size.
{
  //  health = h;
    // set random start position
    int random_number = rand() % 1750;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/WingShip_Spider.png"));

}

//double Enemy::setSpeed()
//{
//    if(Score().getScore() < 50 )
//    {
//        speed = 0.1;
//    }
//    else if(Score().getScore() >49 && Score().getScore() < 100)
//    {
//        speed = 0.3;
//    }
//    else if(Score().getScore() >99 && Score().getScore() < 150)
//    {
//        speed = 0.5;
//    }
//    else if(Score().getScore() >100)
//    {
//        speed = 0.3;
//    }
//    return speed;
//}

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

