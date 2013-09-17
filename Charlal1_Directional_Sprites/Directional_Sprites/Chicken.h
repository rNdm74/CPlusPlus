#pragma once
#include "sprite.h"
#include "TileMap.h"

ref class Chicken :
public Sprite
{
private:
	TileMap^ tileMap;

public:
	Chicken(TileMap^ map, EBoundsAction startAction, Graphics^ startCanvas, array<String^>^ filenames, int nFrames, Random^ startRgen, Point startPos, Rectangle bounds);

	virtual void move() override;
};
