#ifndef ENEMY3_H
#define ENEMY3_H

#include <enemy1.h>

class Enemy3: public Enemy1{
    Q_OBJECT
public:
    Enemy3(QGraphicsItem * parent=0);
public slots:
    void move(int speed = 5);
    void hit(int dmg);
    virtual void destroy();
private:
   int hp = 1;
};

#endif // ENEMY3_H
