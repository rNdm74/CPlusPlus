#pragma once
#include "gameobject.h"

ref class Bullet :
public GameObject
{
private:
	int direction;

public:
	Bullet(RectangleF startRect, PointF startVel, Graphics^ startGraphics, int startDirection);
	virtual void update() override;
};
