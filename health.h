#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>
#include "hp.h"

class Health: public HP
{

    // 1 Health = 4 HP

public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    int getHealth();    /***3 encapsulation ***/

private:
    int health;
};

#endif // HEALTH_H
