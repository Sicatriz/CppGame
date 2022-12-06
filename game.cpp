#include "game.h"
#include <QMouseEvent>
#include "player.h"

//#include "bullet.h"



Game::Game(QWidget *parent)
{
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1920,1080); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/gfx/gfx/sea.jpg"))); //set background image

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1920,1080);  //set the size of the window

    // create the player
    player = new Player();
    player->setPixmap(QPixmap(":/gfx/gfx/playerJet.png")); //playerskin
    //startposition
    player->setPos(scene->width()/2, scene->height()- 150);
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
    music->setSource(QUrl("qrc:/sounds/sounds/1.MainTheme-320bit.mp3"));
    audioOutput->setVolume(70);
    music->audioOutput()->setVolume(70);
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
    //player->motion(mouse);
    //player->motion(mouse);
   // player->setPos(mouse->pos());

}

//void Game::motion:QMouseEvent(QMouseEvent *mouse)
//{
//    player->setPos(mouse->pos());
//}




