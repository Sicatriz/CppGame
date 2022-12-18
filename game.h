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
#include "hp.h"
#include <QMouseEvent>
#include "movableObjects.h"

/*******************************************/
/*******************************************/
/***** GAME CLASS for game managment *******/
/*******************************************/
/*******************************************/

class Game: public QGraphicsView
{ Q_OBJECT
public:
    Game(QWidget * =0);

    // control functions for movement and shooting
    void mouseMoveEvent(QMouseEvent * mouse) override;
    void keyPressEvent(QKeyEvent * event) override;

    // motion control player
    void motion();
    // add and remove movable objects in scene
    void addItem(MovableObjects *);
    void delItem(MovableObjects *);
    // returns level
    void getLevel();

    void missedEnemy();

    Health* health;
    Score* score;
    HP* hp;
    int level;

    // pointers for clocks and objects
    QTimer * moveTimer;
    QGraphicsScene * scene;
    Player * player;        /***2 abstraction ***/
    MovableObjects * moveObjects;

    // signal/slot functions
public slots:
        //checks collisions between objects
        void collision();
        // spawn functions
       void spawnEnemy();
       void spawnMeteor();
       void spawnBuff();
       friend class MovableObjects;
};

#endif // GAME_H
