#ifndef MOVABLEOBJECTS_H
#define MOVABLEOBJECTS_H

#include <QObject>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsItem>

/*******************************************/
/*******************************************/
/*****  MOVABLE OBJECTS ABSTRACT CLASS *****/
/*******************************************/
/*******************************************/

class MovableObjects: public QObject, public QGraphicsPixmapItem
{ Q_OBJECT
public:
    MovableObjects(QGraphicsItem * parent);
    double getSpeed();
    double speed;

public slots:
    virtual void move()=0;
};

#endif // MOVABLEOBJECTS_H
