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


class MainM: public QGraphicsView
{ Q_OBJECT
public:
    MainM(QWidget *parent);

    QGraphicsScene * scene;

    void start();
    void options();
    void exit();
};

#endif // MAINM_H
