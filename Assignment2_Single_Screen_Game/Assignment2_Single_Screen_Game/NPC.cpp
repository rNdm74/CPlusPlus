#include "StdAfx.h"
#include "NPC.h"

NPC::NPC(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort, ESprite startSprite, int startEnemyType,
			   array<int,3>^ startMap)
    : Sprite(startTileMap, startAction, startCanvas, filename, 
				 nFrames, startRGen, startPos, startViewPort, startSprite, startMap)
	{
		xMag = 6;
		yMag = 6;
		
		frameWidth = sheetData[bearing, currentFrame, WIDTH];
		frameHeight = sheetData[bearing, currentFrame, HEIGHT];
	}

void NPC::setEnemyOne()
{
	
}

void NPC::setEnemyTwo()
{
	
}

void NPC::wander()
{
	//=================================================
	// Depending on a specified probability 
	// a random bearing is picked for the sprite
	//=================================================
	if(rGen->Next(WANDER_PROB) == 0) 
		setBearing(getRandomBearing());

	if(!walking)
		setBearing(getRandomBearing());
}
EBearing NPC::getRandomBearing()
{
	//=================================================
	// Return a random EBearing
	//=================================================
	int pick = rGen->Next(4);

	switch(pick)
	{	
		case 0:
			return WEST;
		case 1:
			return EAST;
		case 2:
			return NORTH;
		case 3:
			return SOUTH;
		/*case 4:
			return STAND;*/
	}
}