#ifndef METEOR3_H
#define METEOR3_H

#include "meteor.h"

/*******************************************/
/*******************************************/
/*************  METEOR TYPE 2  *************/
/*******************************************/
/*******************************************/
namespace insemi
{
class Meteor3: public Meteor{

     Q_OBJECT
public:
    Meteor3(QGraphicsItem * parent=0);
public slots:
    void move();
   private:
    int i = 0;
    int ranused = 0;
    int selectused = 0;
};
}
#endif // METEOR3_H
