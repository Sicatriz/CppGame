#ifndef ENEMY3_H
#define ENEMY3_H

#include <enemy1.h>


class Enemy3: public Enemy{
    Q_OBJECT
public:
    Enemy3(QGraphicsItem * parent=0, Health* h=0);
public slots:
    void move();
    void hit(int dmg);

private:

};

#endif // ENEMY3_H
