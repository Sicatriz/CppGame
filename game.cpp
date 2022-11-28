#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QImage>
#include <QBrush>
//#include <QAmbientSound>

Game::Game(QWidget *parent)
{
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/gfx/gfx/zee.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);  //set the size of the window

    // create the player
    player = new Player();
    player->setPixmap(QPixmap(":/gfx/gfx/playerJet.png"));
    //setPixmap(QPixmap(":/gfx/gfx/bullet.png"));
    //player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(scene->width()/2, scene->height()- 150);
    //player->setPos(scene->width()/2 - (player->rect().width()/2),scene->height() - (player->rect().height()*1.2)); // Startposition middle bottom
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

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

    // play background music
    QMediaPlayer * music = new QMediaPlayer();

    QAudioOutput * audioOutput = new QAudioOutput();

    music->setAudioOutput(audioOutput);
    connect(music, SIGNAL(positionChanged(background)), this, SLOT(positionChanged(0)));
    //music->setSource(QUrl("qrc:/sounds/gameOver.wav"));
    music->setSource(QUrl("qrc:/sounds/1.MainTheme-320bit.mp3"));
    audioOutput->setVolume(100);
    music->audioOutput()->setVolume(100);
    music->play();



    show();
}
