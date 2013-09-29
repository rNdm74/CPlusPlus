#pragma once
#include "sprite.h"



ref class NPC :
public Sprite
	{
	public:
		NPC(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort, int startEnemyType);

		void setEnemyOne();
		void setEnemyTwo();

		void wander();

		EBearing getRandomBearing();
		
	};
