#ifndef BGDECKSCONTAINER_H
#define BGDECKSCONTAINER_H

#include "game.h"
#include "bgdecks.h"

class BgdecksContainer: public BgDecks
{   Q_OBJECT
public:
    BgdecksContainer(QGraphicsItem * parent=0);

public slots:
    void move(int speed = 1);
};

#endif // BGDECKSCONTAINER_H
