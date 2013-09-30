#pragma once
#include "sprite.h"

/// <summary>
/// Summary for NPC
///
///	   Note: The NPC decends from the sprite class  
///          the NPC wanders and has a start type
///			 that a sprite does not have.
///
/// </summary>


ref class NPC :
public Sprite
	{
	public:
		NPC(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort, ESprite startSprite, int startEnemyType);

		void setEnemyOne();
		void setEnemyTwo();

		void wander();

		EBearing getRandomBearing();
		
	};
