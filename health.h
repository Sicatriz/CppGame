#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>
#include "hp.h"

/*******************************************/
/*******************************************/
/************  HEALTH FUNCTION  ************/
/*******************************************/
/*******************************************/

class Health: public HP
{
    /*******************/
    // 1 Health = 4 HP //
    /*******************/

public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    void increase();
    int getHealth() const;    /***3 encapsulation ***/
    void increaseHP();
    void decreaseHP();
    void printhealth();

private:
   short int health;
};

#endif // HEALTH_H
