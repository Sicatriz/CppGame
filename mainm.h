#ifndef MAINM_H
#define MAINM_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFont>
#include <QImage>
#include <QBrush>
#include "game.h"
#include "play.h"


class MainM: public QGraphicsView
{ Q_OBJECT
public:
    MainM(QWidget *parent);

    //Play* button;
    Game* gaame;

    QGraphicsScene * scene;

    void start();
    void options();
    void exit();
};

#endif // MAINM_H
