#ifndef PLAY_H
#define PLAY_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

class Play: public QGraphicsView, public QGraphicsPixmapItem
{Q_OBJECT
public:
    Play(QGraphicsItem* parent=nullptr, QGraphicsScene* sceene=0);
    ~Play();

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);

    QGraphicsScene* scene;
    signal:
    void clicked();
};

#endif // PLAY_H
