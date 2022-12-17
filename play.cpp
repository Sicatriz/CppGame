#include "play.h"
#include "game.h"

using namespace insemi;

// play button sprite and position
Play::Play(QGraphicsItem* parent): QGraphicsPixmapItem(parent)
{
    setPos(800,450);
    //setPos(scene()->width()/2 - 200, scene()->height()/2 - 50);
    setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
    setAcceptHoverEvents(true);
}

// button constructor
Play::~Play()
{

}

// click event
void Play::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    clicked();
}

// hover sprite
void Play::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlayHov.png"));
}

// leave sprite
void Play::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
}

// click action
void Play::clicked()
{
    Game* game = new Game(0);
    game->show();
}

