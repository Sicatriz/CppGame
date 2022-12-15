#ifndef LEVEL_H
#define LEVEL_H
#include "score.h"


class Level: public Score
{
public:
    Level(int score);
private:
    int level;
    friend class Game;
};

#endif // LEVEL_H
