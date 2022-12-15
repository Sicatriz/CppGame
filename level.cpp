#include "level.h"

Level::Level(int score)
{
    if(score < 50)
    {
        level = 1;
    }
    else if(score >49 && score < 100)
    {
        level = 2;
    }
    else if(score >99 && score < 150)
    {
        level = 3;
    }
    else
    {
        level = 4;
    }
}
