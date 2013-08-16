#pragma once
#include "gameobject.h"
#include "ctime"

ref class Alien :
public GameObject
{
private:
	DateTime datetime;
	long time;
	Font^ font;

	int direction;
	int movement;

public:
	Alien(RectangleF startRect, PointF startVel, Graphics^ startGraphics);
	virtual void update() override;
	virtual void render() override;
};
