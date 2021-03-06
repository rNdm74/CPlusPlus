#pragma once
#include "sprite.h"

ref class Player :
public Sprite
{
public:
	Player(EBoundsAction startAction, 
		   Graphics^ startCanvas, array<String^>^ filenames, 
		   int nFrames, Random^ startRgen, Point startPos);

	virtual void move(int viewportWorldX, int viewportWorldY) override;
	virtual void canSpriteMove(int viewportWorldX, int viewportWorldY) override;
};
