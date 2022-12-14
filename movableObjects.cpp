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

int MovableObjects::setSpeed(int arg)
{
    speed = arg;
    return speed;
}
