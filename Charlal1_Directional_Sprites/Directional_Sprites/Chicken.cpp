#include "StdAfx.h"
#include "Chicken.h"

Chicken::Chicken(TileMap^ startTileMap, EBoundsAction startAction, Graphics^ startCanvas, array<String^>^ filenames, int nFrames, Random^ startRgen, Point startPos, Rectangle bounds)
				 : Sprite(startTileMap, startAction, startCanvas, filenames, nFrames, startRgen, startPos, bounds)
{
	
}

void Chicken::move()
{
	if(isBoundsCollision())
			executeBoundsAction();		// pull thus out



	xPos += 1 * spriteDirection[bearing].X;
	yPos += 1 * spriteDirection[bearing].Y;
}
