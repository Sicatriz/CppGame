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
    void delItem(MovableObjects *);
    void getLevel();

    Health* health;
    Score* score;
    int level;

    QTimer * moveTimer;
    QGraphicsScene * scene;
    Player * player;        /***2 abstraction ***/
    MovableObjects * moveObjects;

public slots:
        void collision();
       void spawnEnemy();
       void spawnMeteor();
       void spawnBuff();
       friend class MovableObjects;
};

#endif // GAME_H
