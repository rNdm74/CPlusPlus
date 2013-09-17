#include "StdAfx.h"
#include "Chicken.h"

Chicken::Chicken(TileMap^ map, EBoundsAction startAction, Graphics^ startCanvas, array<String^>^ filenames, int nFrames, Random^ startRgen, Point startPos, Rectangle bounds)
				 : Sprite(startAction, startCanvas, filenames, nFrames, startRgen, startPos, bounds)
{
	tileMap = map;
}

void Chicken::move()
{
	if(isBoundsCollision())
			executeBoundsAction();		// pull thus out



	xPos += 1 * spriteDirection[bearing].X;
	yPos += 1 * spriteDirection[bearing].Y;
}
