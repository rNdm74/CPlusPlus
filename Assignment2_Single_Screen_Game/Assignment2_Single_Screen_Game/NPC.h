#pragma once
#include "sprite.h"

ref class NPC :
public Sprite
	{
	public:
		NPC(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort);
	};
