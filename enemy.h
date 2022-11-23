#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsRectItem
{
   Q_OBJECT    // bullet needs to be an Qobject for movement
public:
    Enemy();
public slots:
    void move();

};
#endif // ENEMY_H
