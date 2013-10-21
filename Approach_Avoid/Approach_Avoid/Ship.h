#pragma once
#include "sprite.h"

ref class Ship :
public Sprite
{
public:
	Ship(EBoundsAction startAction, Graphics^ startCanvas, array<String^>^ filenames, int nFrames, Random^ startRgen, Point startPos, int startBehavior);

	

	virtual void move(int viewportWorldX, int viewportWorldY) override;
	virtual void canSpriteMove(int viewportWorldX, int viewportWorldY) override;
};
