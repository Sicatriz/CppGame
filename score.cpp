#include "score.h"

using namespace std;

namespace insemi
{
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score gets set to 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",24));
   // setPos(10,10);
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score gets increased by 1
}

int Score::getScore(){
    return score;
}
}
