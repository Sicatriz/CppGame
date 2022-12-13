#ifndef METEOR1_H
#define METEOR1_H

#include "meteor.h"

class meteor1: public meteor{

     Q_OBJECT
public:
    meteor1(QGraphicsItem * parent=0);
public slots:
    void move(int speed = 5);

};

#endif // METEOR1_H
