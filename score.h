#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

/*******************************************/
/*******************************************/
/**************  SCORE CLASS  **************/
/*******************************************/
/*******************************************/
namespace insemi
{
class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
private:
    int score;
    friend class Game;
    friend class Enemy;
};
}
#endif // SCORE_H
