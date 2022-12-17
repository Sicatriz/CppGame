#include "play.h"
#include "game.h"

Play::Play(QGraphicsItem* parent): QGraphicsPixmapItem(parent)
{
    setPos(800,450);
    //setPos(scene()->width()/2 - 200, scene()->height()/2 - 50);
    setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
    setAcceptHoverEvents(true);
}

Play::~Play()
{

}

void Play::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    clicked();
}
void Play::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlayHov.png"));
}
void Play::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
}

void Play::clicked()
{
    Game* game = new Game(0);
    game->show();
}

