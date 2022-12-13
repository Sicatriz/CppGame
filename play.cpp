#include "play.h"
#include "game.h"

Play::Play(QGraphicsItem* parent, QGraphicsScene* sceene): QGraphicsPixmapItem(parent)
{
    scene = sceene;
    setPos(sceene->width()/2 - 200, sceene->height()/2 - 50);
    setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
}

Play::~Play()
{

}

void Play::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    this->clicked();
}
void Play::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    this->setPixmap(QPixmap(":/gfx/gfx/StartPlayHov.png"));
}
void Play::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{

    this->setPixmap(QPixmap(":/gfx/gfx/StartPlay.png"));
}

void Play::clicked()
{
    Game* game = new Game(0);
    game->show();
}

