#include "movableObjects.h"
#include <QTimer>
#include <QMouseEvent>
#include <QWidget>
#include <QObject>
#include <QGraphicsTextItem>
#include <QImage>


MovableObjects::MovableObjects(QGraphicsItem * parent)
{

}

int MovableObjects::setSpeed()
{
    speed = 5;
    return speed;
}
