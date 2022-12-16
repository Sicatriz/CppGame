#include "back.h"
#include "mainm.h"

Back::Back(QGraphicsItem* parent): QGraphicsPixmapItem(parent)
{
    setPos(600,1000);
    //setPos(scene()->width()/2 - 200, scene()->height()/2 - 50);
    setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
    setAcceptHoverEvents(true);
}

Back::~Back()
{

}

void Back::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlayClick.png"));
    clicked();
}
void Back::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlayHov.png"));
}
void Back::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
}

void Back::clicked()
{
    //Game* game = new Game(0);
    MainM(0).startup();
}

