#include "StdAfx.h"
#include "Item.h"

Item::Item(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort, ESprite startSprite, array<int,3>^ startMap)
	   : Sprite(startTileMap, startAction, startCanvas, filename, 
				 nFrames, startRGen, startPos, startViewPort, startSprite, startMap)
{	
	frameWidth = sheetData[bearing, currentFrame, 2];
	frameHeight = sheetData[bearing, currentFrame, 3];

	frameDelay = 4;
}
