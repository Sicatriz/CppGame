#ifndef METEOR_H
#define METEOR_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include <QTimer>

class Meteor: public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    Meteor(QGraphicsItem * parent=0);
public slots:
    virtual void move(int speed)=0;
    void hit();

};

#endif // METEOR_H
