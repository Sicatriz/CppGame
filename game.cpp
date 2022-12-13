#include "game.h"
#include <QMouseEvent>
#include "audio.h"
#include "player.h"
#include "audio.h"
//#include "bullet.h"

Game::Game(QWidget *)
{
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1800,1000); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/gfx/gfx/bg52.png"))); //set background image

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1800,1000);  //set the size of the window

    // create the player
    player = new Player(0,scene);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    // play background sound
    Audio* backgroundMusic = new Audio();
    backgroundMusic->playBackgroundMusic();

    // connects player move signal
    QTimer * timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),player,SLOT(motion()));
    timer2->start(15);
    setMouseTracking(true);

    show();
}

void Game::mouseMoveEvent(QMouseEvent *mouse)
{
    player->setWannaBeX(mouse->pos().x()-50);
    player->setWannaBeY(mouse->pos().y()-25);
}





