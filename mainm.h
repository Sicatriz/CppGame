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
#include "play.h"

/*******************************************/
/*******************************************/
/***************  MAIN: START  *************/
/*******************************************/
/*******************************************/
namespace insemi
{
class MainM: public QGraphicsView
{ Q_OBJECT
public:
    MainM(QWidget *parent);
    ~MainM();
    QGraphicsScene * scene;
    Play* button;
    void start();
    void options();
    void exit();
    void startup();
};
}
#endif // MAINM_H
