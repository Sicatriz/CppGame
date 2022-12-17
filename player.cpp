#include "player.h"
#include "game.h"

#include <QMouseEvent>
#include <qvideowidget.h>
#include <QMediaPlayer>

// Ship sprite
Player::Player(QGraphicsItem *parent): MovableObjects(parent)

{

    this->setPixmap(QPixmap(":/gfx/gfx/Starship_C.png")); //playerskin
}

// X goal position
void Player::setWannaBeX(int x)
{
    wannaBeX = x;
}

// Y goal position
void Player::setWannaBeY(int y)
{
    wannaBeY = y;
}

// player movement algorithm => makes it move with variable speed to cursor, depending on distance from cursor
void Player::move()
{
    int coef = 19;
    setPos((wannaBeX*(20-coef)+pos().x()*coef)/20, (wannaBeY*(20-coef)+pos().y()*coef)/20 );
}








