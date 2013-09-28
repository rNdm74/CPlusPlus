#pragma once
#include "sprite.h"

ref class Item :
public Sprite
{
public:
	Item(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRgen, Point startPos, 
			   Viewport^ startViewPort);
};
