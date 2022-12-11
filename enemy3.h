#ifndef ENEMY3_H
#define ENEMY3_H

#include <enemy1.h>


class Enemy3: public Enemy{
    Q_OBJECT
public:
    Enemy3(QGraphicsItem * parent=0);
public slots:
    void move(int speed = 5/*, Game* game*/);
    void hit(int dmg);

private:
   //int hp = 1;
};

#endif // ENEMY3_H
