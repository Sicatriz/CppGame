#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject, public QGraphicsRectItem
{
   Q_OBJECT    // enemy needs to be an Qobject for movement
public:
    Enemy(QGraphicsItem * parent=0);
public slots:
    void move();

};
#endif // ENEMY_H
