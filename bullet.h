#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem
{
   Q_OBJECT    // bullet needs to be an Qobject for movement
public:
    Bullet();
public slots:
    void move();

};

#endif // BULLET_H
