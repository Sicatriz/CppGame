#ifndef BUFF1_H
#define BUFF1_H

//#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Buff.h"
#include <QTimer>

class Buff1: public Buff /***8 abstract base class***/
{
   Q_OBJECT    // enemy needs to be an Qobject for movement

public:

   Buff1(QGraphicsItem * parent=0);

};

#endif // BUFF1_H
