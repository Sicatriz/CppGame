#include "player.h"
#include "game.h"

#include <QMouseEvent>
#include <qvideowidget.h>
#include <QMediaPlayer>

using namespace std;

namespace insemi
{

Player::Player(QGraphicsItem *parent): MovableObjects(parent)

{

    this->setPixmap(QPixmap(":/gfx/gfx/Starship_C.png")); //playerskin
}

void Player::setWannaBeX(int x)
{
    wannaBeX = x;
}

void Player::setWannaBeY(int y)
{
    wannaBeY = y;
}

void Player::move()
{
    int coef = 19;
    setPos((wannaBeX*(20-coef)+pos().x()*coef)/20, (wannaBeY*(20-coef)+pos().y()*coef)/20 );
}

}






