#ifndef METEOR1_H
#define METEOR1_H

#include "meteor.h"

/*******************************************/
/*******************************************/
/*************  METEOR TYPE 1  *************/
/*******************************************/
/*******************************************/
namespace insemi
{
class Meteor1: public Meteor{

     Q_OBJECT
public:
    Meteor1(QGraphicsItem * parent=0);
public slots:
    void move();


};
}
#endif // METEOR1_H
