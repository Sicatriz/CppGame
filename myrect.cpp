#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>

#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
        setPos(x()+30,y());
    }
    else if (event->key() == Qt::Key_Up){
        if(pos().y() > 0)
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        if(pos().y() + 100 < 600)
        setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Space){
        // create bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }


}

void MyRect::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}
