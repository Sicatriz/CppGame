#ifndef METEOR1_H
#define METEOR1_H

#include "meteor.h"

class Meteor1: public Meteor{

     Q_OBJECT
public:
    Meteor1(QGraphicsItem * parent=0);
public slots:
    void move(int speed = 5);

};

#endif // METEOR1_H
