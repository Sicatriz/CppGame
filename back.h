#ifndef BACK_H
#define BACK_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>

class Back: public QGraphicsView, public QGraphicsPixmapItem
{Q_OBJECT
public:
    Back(QGraphicsItem* parent=0);
    ~Back();
    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    void clicked();
};

#endif // BACK_H
