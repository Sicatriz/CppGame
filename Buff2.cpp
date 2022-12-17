#include "Buff2.h"

using namespace std;

namespace insemi
{
//extern game * game;
Buff2::Buff2(QGraphicsItem *): Buff() //With Qobject you say this Enemy is a object, Qgraphics gives the enemy a size.
{

    // set random start position
    int random_number = rand() % 1600;
    setPos(random_number, 0);

    //gfx enemy type 1
    setPixmap(QPixmap(":/gfx/gfx/Health.png"));

}


}

