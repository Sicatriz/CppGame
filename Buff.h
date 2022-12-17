#ifndef BUFF_H
#define BUFF_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "movableObjects.h"
#include <QTimer>

/*******************************************/
/*******************************************/
/*********  BUFF ABSTRACT CLASS  ***********/
/*******************************************/
/*******************************************/

class Buff: public MovableObjects /***8 abstract base class***/
{
   Q_OBJECT    // enemy needs to be an Qobject for movement

public:

   Buff(QGraphicsItem * parent=0);

public slots:
    void move();
};

#endif // BUFF_H
