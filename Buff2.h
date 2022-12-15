#ifndef BUFF2_H
#define BUFF2_H

#include <stdlib.h>
#include "Buff.h"

class Buff2: public Buff /***8 abstract base class***/
{
   Q_OBJECT    // enemy needs to be an Qobject for movement

public:

   Buff2(QGraphicsItem * parent=0);

};

#endif // BUFF2_H
