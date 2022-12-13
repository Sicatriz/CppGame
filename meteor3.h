#ifndef METEOR3_H
#define METEOR3_H

#include "meteor.h"

class meteor3: public meteor{

     Q_OBJECT
public:
    meteor3(QGraphicsItem * parent=0);
public slots:
    void move(int speed = 5);
   private:
    int i = 0;
    int ranused = 0;
    int selectused = 0;
};

#endif // METEOR3_H
