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

    if(Score().getScore() < 50 )
    {
        speed = 0.5;
    }
    else if(Score().getScore() >49 && Score().getScore() < 100)
    {
        speed = 2;
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
