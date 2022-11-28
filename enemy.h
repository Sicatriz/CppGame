#ifndef ENEMY_H
#define ENEMY_H

//#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Enemy: public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT    // enemy needs to be an Qobject for movement

public:

   Enemy(QGraphicsItem * parent=0);
public slots:
    virtual void move(int speed = 5);


};

class Enemy2: public Enemy{
    Q_OBJECT
public:
    Enemy2(QGraphicsItem * parent=0);
public slots:
    void move(int speed = 10);

};
#endif // ENEMY_H
