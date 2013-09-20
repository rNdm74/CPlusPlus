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
		int newSpriteXPos = xPos;
		int newSpriteYPos = yPos;

		// Adds to the new variable this will see where the knight wants to move
		newSpriteXPos += xMag * spriteDirection[bearing].X;
		newSpriteYPos += yMag * spriteDirection[bearing].Y;

		// Brings new positon into the viewport area
		int viewportSpriteX = newSpriteXPos - viewportWorldX;
		int viewportSpriteY = newSpriteYPos - viewportWorldY;

		//**************************************************
		// Sets the detection point for the knight to tell what tile he is on
		// Centeres the hitbox on the sprite
		int spriteXPos = frameWidth / 2;
		int spriteYPos = frameHeight / 2;
				
		// for drawing hit box to the canvas
		viewportSpriteX += spriteXPos;
		viewportSpriteY += spriteYPos;
		boundsX = viewportSpriteX;
		boundsY = viewportSpriteY;	
		//**************************************************
		
		// current pixel plus half framewidth puts pixel in center of knight then devides to get tile position 
		int newTilePosX = (newSpriteXPos + spriteXPos) / T_SIZE; 
		int newTilePosY = (newSpriteYPos + spriteYPos) / T_SIZE;


		// Gets the new tile value from the map (look ahead)
		int tileValue = tileMap->getMapValue(newTilePosX, newTilePosY);		
		
		if(tileValue == SOLID)
			executeBoundsAction();			

		if(tileValue == GRASS) // If the tile is grass change movement speed to 1
		{
			xMag = 1;
			yMag = 1;
		}
		
		if(tileValue == COBBLESTONE) // If the tile is cobblestone change movement speed to 2
		{
			xMag = 3;
			yMag = 3;
		}		
		
		if(tileValue != SOLID) // If the tile is not flowers apply new move position
		{			
			xPos = newSpriteXPos;
			yPos = newSpriteYPos;
		}

}


