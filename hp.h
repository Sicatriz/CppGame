#ifndef HP_H
#define HP_H

#include <QGraphicsTextItem>
#include <QFont>
//#include "health.h"

using namespace std;

namespace insemi
{

class HP: public QGraphicsTextItem{

    // 1 Health = 4 HP

public:
    HP(QGraphicsItem * parent=0);
    virtual void decreaseHP();
    virtual void increaseHP();
    int getHP() const;    /***3 encapsulation ***/
    void setHP(int i);
    void printhp();

private:
   short int hp;
};
}


#endif // HP_H
