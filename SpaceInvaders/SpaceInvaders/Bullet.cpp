#include "StdAfx.h"
#include "Bullet.h"

Bullet::Bullet(RectangleF startRect, PointF startVel, Graphics^ startGraphics, int startDirection)
	   : GameObject(startRect, startVel, startGraphics)
{
	direction = startDirection;
}

void Bullet::update()
{
	rect.Y += vel.Y * SPEED * direction;
}
