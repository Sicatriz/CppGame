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
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event) override;

    //void mousePressEvent(QMouseEvent *event) override;
    void motion(QMouseEvent *event);

public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;

};
#endif // PLAYER_H
