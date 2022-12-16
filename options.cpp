#include "options.h"
#include "mainm.h"

Options::Options(QGraphicsItem* parent): QGraphicsPixmapItem(parent)
{
    setPos(100,400);
    setPixmap(QPixmap(":/gfx/gfx/options.png"));

    setAcceptHoverEvents(true);
}

Options::~Options()
{

}

void Options::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/optionsclick.png"));
    clicked();
}
void Options::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/optionshov.png"));
}
void Options::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/options.png"));
}

void Options::clicked()
{
    MainM(0).options();
}

