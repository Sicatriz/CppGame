#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"

class Bullet: public QObject, public QGraphicsPixmapItem  /****1 usefull and correct class ****/
{
   Q_OBJECT    // bullet needs to be an Qobject for movement and this makes it a object.
public:
    Bullet(QGraphicsItem * parent=0);  /*** argumented constructor ****/  /****1 usefull and correct class ****/
public slots:  //slots let's you connect signals to your function.
    void move();

};

#endif // BULLET_H
