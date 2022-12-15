#include "mainm.h"
#include "play.h"
#include "options.h"

MainM::MainM(QWidget *)
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
    show();

    Play* button = new Play(0, scene);
    scene->addItem(button);

    Options* button1 = new Options(0, scene);
    button1->setPixmap(QPixmap());
    scene->addItem(button);

    /*
    Play* button2 = new Play(0, scene);
    scene->addItem(button2);*/
}

void MainM::options()
{

}

void MainM::exit()
{
    deleteLater();
}
