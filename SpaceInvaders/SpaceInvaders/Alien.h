#pragma once
#include "bullet.h"
#include "gameobject.h"
#include "gameobjectlist.h"
#define SPEED 10

ref class Alien :
public GameObject
{
private:	
	long time;
	Font^ font;

	int tag;
	
	int moveTime;
	int direction;
	int movement;

	Brush^ tagColor;

	bool canAttack;

	Random^ rGen;

	GameObjectList^ bullets;

public:
	Alien(RectangleF startRect, PointF startVel, Graphics^ startGraphics, int newTag, Random^ startRGen, GameObjectList^ gameBullets);
	virtual void update() override;
	virtual void render() override;
	virtual void shoot() override;
};
