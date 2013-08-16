#pragma once
#include "gameobject.h"

ref class Alien :
public GameObject
{
public:
	Alien(RectangleF startRect, PointF startVel, Graphics^ startGraphics);
};
