#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
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
#include <QMouseEvent>
#include "movableObjects.h"
//#include "enemy.h"

class Game: public QGraphicsView
{ Q_OBJECT
public:
    Game(QWidget * =0);

    void mouseMoveEvent(QMouseEvent * mouse) override;
    void keyPressEvent(QKeyEvent * event) override;
    void motion();
    void addItem(MovableObjects *);

    Health* health;
    Score* score;

    QTimer * moveTimer;
    QGraphicsScene * scene;
    Player * player;        /***2 abstraction ***/
    MovableObjects * moveObjects;

public slots:
        void collision();
       void spawnEnemy();

    //Bullet * bullet;
//gathers all information to make sure that the game runs
};

#endif // GAME_H
