#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT    // bullet needs to be an Qobject for movement and this makes it a object.
public:
    Bullet(QGraphicsItem * parent=0);  /*** argumented constructor ****/
public slots:  //slots let's you connect signals to your function.
    void move();

};

#endif // BULLET_H
