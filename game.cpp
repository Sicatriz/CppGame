#include "game.h"
#include <QMouseEvent>
#include "player.h"
#include "bgdecks.h"
#include "bgdeckscontainer.h"
#include "bgdeckscruise.h"

//#include "bullet.h"



Game::Game(QWidget *parent)
{
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1920,1080); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/gfx/gfx/sea.jpg"))); //set background image

    // HIER EEN GEHEUGEN ISSUE
    // spawn boats
//    QTimer * timerBoat = new QTimer();
//    QObject::connect(timerBoat,SIGNAL(timeout()),player,SLOT(spawnBoat()));
//    timerBoat->start(30000);

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1920,1080);  //set the size of the window

    // create the player
    player = new Player(0,scene);


    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);



//    // boats on start screen
//    BgDecks * container = new BgdecksContainer();
//    container->setPos(400,600);
//    scene->addItem(container);

//    BgDecks * cruise = new BgdecksCruise();
//    container->setPos(500,400);
//    scene->addItem(cruise);


    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * audioOutput = new QAudioOutput();

    music->setAudioOutput(audioOutput);
    connect(music, SIGNAL(positionChanged(background)), this, SLOT(positionChanged(0)));
    music->setSource(QUrl("qrc:/sounds/sounds/1.MainTheme-320bit.mp3"));
    audioOutput->setVolume(70);
    music->play();

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





