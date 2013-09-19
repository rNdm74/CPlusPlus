#pragma once
#include "sprite.h"
#include "TileMap.h"

ref class Chicken :
public Sprite
{
public:
	Chicken(TileMap^ startTileMap, EBoundsAction startAction, 
			Graphics^ startCanvas, array<String^>^ filenames, 
			int nFrames, Random^ startRgen, Point startPos, 
			Viewport^ startViewPort);

	virtual void move(int viewportWorldX, int viewportWorldY) override;
	virtual void canSpriteMove(int viewportWorldX, int viewportWorldY) override;
};
