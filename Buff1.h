#ifndef BUFF1_H
#define BUFF1_H

#include <stdlib.h>
#include "Buff.h"

using namespace std;

namespace insemi
{


class Buff1: public Buff /***8 abstract base class***/
{
   Q_OBJECT    // enemy needs to be an Qobject for movement

public:

   Buff1(QGraphicsItem * parent=0);

};

}

#endif // BUFF1_H
