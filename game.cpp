#include "game.h"
#include <QMouseEvent>
#include "audio.h"
#include "player.h"
#include "audio.h"
Game::Game(QWidget *)
{
    scene = new QGraphicsScene();
    this->showMaximized(); // make the scene 800x600 instead of infinity by infinity (default)
    scene->focusItem();
    this->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    //scene->setSceneRect(0,0, this->width(),this->height());
    //setFixedSize(this->width(), this->height());
    setBackgroundBrush(QBrush(QImage(":/gfx/gfx/bg52.png"))); //set background image

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    fitInView(scene->sceneRect());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->activePanel();
    //showMaximized();
    //set the size of the window

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
}

void Game::mouseMoveEvent(QMouseEvent *mouse)
{
    player->setWannaBeX(mouse->pos().x()-50);
    player->setWannaBeY(mouse->pos().y()-25);
}





