#include "options.h"
#include "mainm.h"

Options::Options(QGraphicsItem* parent, QGraphicsScene* sceene): QGraphicsPixmapItem(parent)
{

    scene = sceene;
    setPos(sceene->width()/2 - 200, sceene->height()/2 - 50);
    setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
    setAcceptHoverEvents(true);
}

Options::~Options()
{

}

void Options::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlayClick.png"));
    clicked();
}
void Options::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlayHov.png"));
}
void Options::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
}

void Options::clicked()
{

}

