#include "StdAfx.h"
#include "Bullet.h"

Bullet::Bullet(RectangleF startRect, PointF startVel, Graphics^ startGraphics)
	   : GameObject(startRect, startVel, startGraphics)
{
}

void Bullet::update()
{
	//rect.X += vel.X * SPEED;
	rect.Y -= vel.Y * SPEED;
}
