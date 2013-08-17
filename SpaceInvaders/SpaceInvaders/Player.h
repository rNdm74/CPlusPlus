#pragma once
#include "GameObjectList.h"
#include "Bullet.h"
#include "gameobject.h"

ref class Player :
public GameObject
{
private:
	GameObjectList^ bullets;
	bool hit;

public:
	Player(RectangleF startRect, PointF startVel, Graphics^ startGraphics, GameObjectList^ gameBullets);
	void keyUp(KeyEventArgs^  e);
	void keyDown(KeyEventArgs^  e);

	virtual void update() override;
	virtual void render() override;

	bool isHit()		{ return hit; }
	void setHit(bool h) { hit = h; }
};
