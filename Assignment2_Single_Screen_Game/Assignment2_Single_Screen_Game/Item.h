#pragma once
#include "sprite.h"

ref class Item :
public Sprite
{
public:
	Item(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRgen, Point startPos, 
			   Viewport^ startViewPort);
};
