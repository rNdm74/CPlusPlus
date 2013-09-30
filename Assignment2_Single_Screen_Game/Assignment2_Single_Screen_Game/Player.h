#pragma once
#include "sprite.h"

ref class Player :
public Sprite
	{		
	public:
		Player(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRgen, Point startPos, 
			   Viewport^ startViewPort, ESprite startSprite,
			   array<int,3>^ startMap);		
	};
