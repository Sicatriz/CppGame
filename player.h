#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0, QGraphicsScene *scene=0);
    void keyPressEvent(QKeyEvent * event) override;

    void setWannaBeX(int x);
    void setWannaBeY(int y);

 //   void mousePressEvent(QMouseEvent *event);


public slots:
    void spawn();
    void spawnBoat();
    void motion();
    void collision();
private:
    QMediaPlayer * bulletsound;
    int wannaBeX = 0;
    int wannaBeY = 0;

};
#endif // PLAYER_H
