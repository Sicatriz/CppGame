#ifndef OPTIONS_H
#define OPTIONS_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>

class Options: public QGraphicsView, public QGraphicsPixmapItem
{Q_OBJECT
public:
    Options(QGraphicsItem* parent=nullptr, QGraphicsScene* sceene=0);
    ~Options();

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);

    QGraphicsScene* scene;

    void clicked();
};

#endif // OPTIONS_H
