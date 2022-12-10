#ifndef BGDECKSCRUISE_H
#define BGDECKSCRUISE_H

#include "game.h"
#include "bgdecks.h"

class BgdecksCruise: public BgDecks
{   Q_OBJECT
public:
    BgdecksCruise(QGraphicsItem * parent=0);

public slots:
    void move(int speed = 1);
};

#endif // BGDECKSCRUISE_H
