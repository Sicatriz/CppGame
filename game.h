#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFont>
#include <QImage>
#include <QBrush>
#include "player.h"
#include "score.h"
#include "health.h"
#include "bullet.h"
#include <QMouseEvent>
//#include "enemy.h"

class Game: public QGraphicsView
{ Q_OBJECT
public:
    Game(QWidget *parent);

    void mouseMoveEvent(QMouseEvent * mouse) override;

    void motion();

    Health* health;
    Score* score;

    QGraphicsScene * scene;
    Player * player;        /***2 abstraction ***/
    //Bullet * bullet;
//gathers all information to make sure that the game runs
};

#endif // GAME_H
