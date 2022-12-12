#ifndef BGDECKS_H
#define BGDECKS_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include <QTimer>

class BgDecks: public QObject, public QGraphicsPixmapItem
{
         Q_OBJECT
public:
    BgDecks(QGraphicsItem * parent=0);

public slots:
//    virtual void move(int speed)=0;
};

#endif // BGDECKS_H
