#include "StdAfx.h"
#include "NPC.h"

NPC::NPC(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort, int startEnemyType)
    : Sprite(startTileMap, startAction, startCanvas, filenames, 
				 nFrames, startRGen, startPos, startViewPort)
	{
		xMag = 3;
		yMag = 3;

		switch(startEnemyType)
		{
			case 1:
				setEnemyOne();
				break;
			case 2:
				setEnemyTwo();
				break;
		}

		frameWidth = sheetData[bearing, currentFrame, 2];
		frameHeight = sheetData[bearing, currentFrame, 3];
	}

void NPC::setEnemyOne()
{
	int y = rGen->Next(1, 12);
	
	if(y % 2 == 0)
	{
		y = y * T_SIZE;
		yPos = y - 97;
	}

	xPos = rGen->Next(100, 1024);
	

	sheetData = gcnew array<int, 3>
		{
			{
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97},
				{438,92,67,97}
			},
			{
				{0, 0, 72, 97},
				{73, 0, 72, 97},
				{146, 0, 72, 97},
				{0, 98, 72, 97},
				{73, 98, 72, 97},
				{146, 98, 72, 97},
				{219, 0, 72, 97},
				{292, 0, 72, 97},
				{219, 98, 72, 97},
				{365, 0, 72, 97},
				{292, 98, 72, 97}
			},
			{
				{438,93,67,94},
				{438,93,67,94},
				{438,93,67,94},
				{438,93,67,94},
				{438,93,67,94},
				{438,93,67,94},
				{438,93,67,94},
				{438,93,67,94},
				{438,93,67,94},
				{438,93,67,94},
				{438,93,67,94}
			},
			{
				{0, 0, 72, 97},
				{73, 0, 72, 97},
				{146, 0, 72, 97},
				{0, 98, 72, 97},
				{73, 98, 72, 97},
				{146, 98, 72, 97},
				{219, 0, 72, 97},
				{292, 0, 72, 97},
				{219, 98, 72, 97},
				{365, 0, 72, 97},
				{292, 98, 72, 97}
			}
		};

	enemy = true;
}

void NPC::setEnemyTwo()
{
	int y = rGen->Next(1, 12);
	
	if(y % 2 == 0)
	{
		y = y * T_SIZE;
		yPos = y - 94;
	}

	xPos = rGen->Next(100, 1024);

	sheetData = gcnew array<int, 3>
	{
		{
			{0,0,70,94},
			{71,0,70,94},
			{142,0,70,94},
			{0,95,70,94},
			{71,95,70,94},
			{142,95,70,94},
			{213,0,70,94},
			{284,0,70,94},
			{213,95,70,94},
			{355,0,70,94},
			{284,95,70,94}
		},
		{
			{0,0,70,94},
			{71,0,70,94},
			{142,0,70,94},
			{0,95,70,94},
			{71,95,70,94},
			{142,95,70,94},
			{213,0,70,94},
			{284,0,70,94},
			{213,95,70,94},
			{355,0,70,94},
			{284,95,70,94}
		},
		{
			{0,0,70,94},
			{71,0,70,94},
			{142,0,70,94},
			{0,95,70,94},
			{71,95,70,94},
			{142,95,70,94},
			{213,0,70,94},
			{284,0,70,94},
			{213,95,70,94},
			{355,0,70,94},
			{284,95,70,94}
		},
		{
			{0,0,70,94},
			{71,0,70,94},
			{142,0,70,94},
			{0,95,70,94},
			{71,95,70,94},
			{142,95,70,94},
			{213,0,70,94},
			{284,0,70,94},
			{213,95,70,94},
			{355,0,70,94},
			{284,95,70,94}
		}
	};

	enemy = true;
}


void NPC::move(int viewportWorldX, int viewportWorldY)
{
		//=======================================================================
		// If sprite can walk the xPosition and yPosition is incremented
		// the a set magnitude, a direction is then applied to the magnitude 1, -1
		// this will allow the sprite to move up, down, left and right
		//=======================================================================
		if(isBoundsCollision())
			executeBoundsAction();				

		if(walking)
			canSpriteMove(viewportWorldX, viewportWorldY);		
}

bool NPC::collision(Rectangle r)
{
	for(int x = r.X; x < r.X + r.Width; x++)
	{
		for(int y = r.Y; y < r.X + r.Height; y++)
		{
			int newTilePosY = y / T_SIZE;
			int newTilePosX = x / T_SIZE;

			if(tileMap->isSolid(newTilePosY, newTilePosX))
				return true;
		}
	}

	return false;
}

void NPC::canSpriteMove(int viewportWorldX, int viewportWorldY)
{
	int col = xPos / T_SIZE;
	int row = yPos / T_SIZE;

	ETileType tileType = tileMap->getTileType(row, col);

	if(checkCanMove(bearing, viewportWorldX, viewportWorldY))
	{		
		yPos += yMag * spriteDirection[bearing].Y;
		xPos += xMag * spriteDirection[bearing].X;
	}	
}

bool NPC::checkCanMove(EBearing spriteBearing, int viewportWorldX, int viewportWorldY)
{
	// Copies current position to new variable
	int newSpriteXPos = xPos;
	int newSpriteYPos = yPos;

	// Adds to the new variable this will see where the knight wants to move
	newSpriteXPos += xMag * spriteDirection[spriteBearing].X;
	newSpriteYPos += yMag * spriteDirection[spriteBearing].Y;

	// Brings new positon into the viewport area
	int viewportSpriteX = newSpriteXPos - viewportWorldX;
	int viewportSpriteY = newSpriteYPos - viewportWorldY;

	//**************************************************
	// Sets the detection point for the knight to tell what tile he is on
	
	bounds[0].X = viewportSpriteX + frameWidth / 5;
	bounds[0].Y = (viewportSpriteY + frameHeight) - 1;
	bounds[1].X = viewportSpriteX + frameWidth / 5;
	bounds[1].Y = (viewportSpriteY + frameHeight) - 68;
	bounds[2].X = (viewportSpriteX + frameWidth) - frameWidth / 5;
	bounds[2].Y = (viewportSpriteY + frameHeight)- 68;
	bounds[3].X = (viewportSpriteX + frameWidth) - frameWidth / 5;
	bounds[3].Y = (viewportSpriteY + frameHeight) - 1;
	

	//**************************************************
	boundPoints[0].X = (newSpriteXPos + frameWidth / 5) / T_SIZE;
	boundPoints[0].Y = ((newSpriteYPos + frameHeight) - 1) / T_SIZE;
	boundPoints[1].X = (newSpriteXPos + frameWidth / 5) / T_SIZE;
	boundPoints[1].Y = ((newSpriteYPos + frameHeight) - 68) / T_SIZE;
	boundPoints[2].X = ((newSpriteXPos + frameWidth) - frameWidth / 5) / T_SIZE;
	boundPoints[2].Y = ((newSpriteYPos + frameHeight) - 68) / T_SIZE;
	boundPoints[3].X = ((newSpriteXPos + frameWidth) - frameWidth / 5) / T_SIZE;;
	boundPoints[3].Y = ((newSpriteYPos + frameHeight) - 1) / T_SIZE;

	// Current pixel plus half framewidth puts pixel in 
	// center of knight then devides to get tile position 
	bool p1 = tileMap->isSolid(boundPoints[0].Y, boundPoints[0].X);
	bool p2 = tileMap->isSolid(boundPoints[1].Y, boundPoints[1].X);
	bool p3 = tileMap->isSolid(boundPoints[2].Y, boundPoints[2].X);
	bool p4 = tileMap->isSolid(boundPoints[3].Y, boundPoints[3].X);

	if(!p1 && !p2 && !p3 && !p4) // If the tile is not flowers apply new move position
	{			
		return true;
	}

	return false;
}