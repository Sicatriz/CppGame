#ifndef PLAY_H
#define PLAY_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>

class Play: public QGraphicsView, public QGraphicsPixmapItem
{Q_OBJECT
public:
    Play(QGraphicsItem* parent=0);
    ~Play();
    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    void clicked();
};

#endif // PLAY_H
