#ifndef HP_H
#define HP_H

#include <QGraphicsTextItem>
#include <QFont>
//#include "health.h"

class HP: public QGraphicsTextItem{

    // 1 Health = 4 HP

public:
    HP(QGraphicsItem * parent=0);
    void decreaseHP();
    int getHP();    /***3 encapsulation ***/
    void setHP();

private:
    int hp;
};

#endif // HP_H
