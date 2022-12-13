#include "mainm.h"

MainM::MainM(QWidget *parent)
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

    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * audioOutput = new QAudioOutput();

    music->setAudioOutput(audioOutput);
    //connect(music, SIGNAL(positionChanged(background)), this, SLOT(positionChanged(0)));
    music->setSource(QUrl("qrc:/sounds/sounds/slow-travel.wav"));
    audioOutput->setVolume(0.2);
    music->play();
    show();

    button = new Play(0, scene);
    scene->addItem(button);

/*
    button = new Play(0, scene);
    scene->addItem(button);


    button = new Play(0, scene);
    scene->addItem(button);*/


}

void MainM::options()
{

}

void MainM::exit()
{

}
