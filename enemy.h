#ifndef ENEMY_H
#define ENEMY_H

//#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"
#include <QTimer>

class Enemy: public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT    // enemy needs to be an Qobject for movement

public:

   Enemy(QGraphicsItem * parent=0);
public slots:
    virtual void move(int speed)=0;

};

#endif // ENEMY_H
