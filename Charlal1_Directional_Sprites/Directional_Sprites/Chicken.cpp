#include "StdAfx.h"
#include "Chicken.h"

Chicken::Chicken(TileMap^ startTileMap, EBoundsAction startAction, 
				 Graphics^ startCanvas, array<String^>^ filenames, 
				 int nFrames, Random^ startRgen, Point startPos, 
				 Viewport^ startViewPort)
		: Sprite(startTileMap, startAction, startCanvas, filenames, 
				 nFrames, startRgen, startPos, startViewPort)
{
	
}

void Chicken::move(int viewportWorldX, int viewportWorldY)
{
	//=======================================================================
		// If sprite can walk the xPosition and yPosition is incremented
		// the a set magnitude, a direction is then applied to the magnitude 1, -1
		// this will allow the sprite to move up, down, left and right
		//=======================================================================
		if(isBoundsCollision())
			executeBoundsAction();				

		if(walking)
		{
			canSpriteMove(viewportWorldX, viewportWorldY);
		}
}

void Chicken::canSpriteMove(int viewportWorldX, int viewportWorldY)
{	
		// Copies current position to new variable
		int newKnightXPos = xPos;
		int newKnightYPos = yPos;

		// Adds to the new variable this will see where the knight wants to move
		newKnightXPos += xMag * spriteDirection[bearing].X;
		newKnightYPos += yMag * spriteDirection[bearing].Y;

		// Brings new positon into the viewport area
		int viewportKnightX = newKnightXPos - viewportWorldX;
		int viewportKnightY = newKnightYPos - viewportWorldY;

		//**************************************************
		// Sets the detection point for the knight to tell what tile he is on
		int knightXPos = frameWidth / 2;
		int knightYPos = frameHeight / 2;

		/*switch(bearing)
		{
			case NORTH:
				knightXPos = frameWidth / 2; 
				knightYPos = 50;
				break;
			case EAST:
				knightXPos = frameWidth - 20;
				knightYPos = frameHeight / 2;
				break;
			case SOUTH:
				knightXPos = frameWidth / 2;
				knightYPos = frameHeight - 10;
				break;
			case WEST:
				knightXPos = 20;
				knightYPos = frameHeight / 2;
				break;
		}*/
		
		// for drawing hit box to the canvas
		viewportKnightX += knightXPos;
		viewportKnightY += knightYPos;
		boundsX = viewportKnightX;
		boundsY = viewportKnightY;		
		//**************************************************
		
		// current pixel plus half framewidth puts pixel in center of knight then devides to get tile position 
		int newTilePosX = (newKnightXPos + knightXPos) / T_SIZE; 
		int newTilePosY = (newKnightYPos + knightYPos) / T_SIZE;

		if(tileMap->getMapValue(newTilePosX, newTilePosY) == 0)
			executeBoundsAction();

		// If the tile is grass change movement speed to 1
		if(tileMap->getMapValue(newTilePosX, newTilePosY) == 1)
		{
			xMag = 1;
			yMag = 1;
		}

		// If the tile is cobblestone change movement speed to 2
		if(tileMap->getMapValue(newTilePosX, newTilePosY) == 2)
		{
			xMag = 2;
			yMag = 2;
		}

		// If the tile is not flowers apply new move position
		if(tileMap->getMapValue(newTilePosX, newTilePosY) != 0)
		{
			xPos = newKnightXPos;
			yPos = newKnightYPos;
		}
}


