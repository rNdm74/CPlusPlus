#pragma once
#include "gameobject.h"

ref class Bullet :
public GameObject
{
public:
	Bullet(RectangleF startRect, PointF startVel, Graphics^ startGraphics);
	virtual void update() override;
};
