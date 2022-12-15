#ifndef BUFF3_H
#define BUFF3_H

#include <stdlib.h>
#include "Buff.h"

class Buff3: public Buff /***8 abstract base class***/
{
   Q_OBJECT    // enemy needs to be an Qobject for movement

public:

   Buff3(QGraphicsItem * parent=0);
   bool shield();

};

#endif // BUFF3_H
