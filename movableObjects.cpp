#include "movableObjects.h"
#include <QTimer>
#include <QMouseEvent>
#include <QWidget>
#include <QObject>
#include <QGraphicsTextItem>
#include <QImage>
#include "bullet.h"

MovableObjects::MovableObjects(QGraphicsItem * )
{

}

double MovableObjects::getSpeed()
{
   // speed = arg;

    if(Score().getScore() < 15 )
    {
        speed = 1;
    }
    else if(Score().getScore() >14 && Score().getScore() < 100)
    {
        speed = 15;
    }
    else if(Score().getScore() >99 && Score().getScore() < 150)
    {
        speed = 5;
    }
    else if(Score().getScore() >100)
    {
        speed = 8;
    }
    return speed;
}
