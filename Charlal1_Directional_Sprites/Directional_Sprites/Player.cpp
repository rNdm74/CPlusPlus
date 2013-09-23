#include "StdAfx.h"
#include "Player.h"

Player::Player(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRgen, Point startPos, 
			   Viewport^ startViewPort)
	   : Sprite(startTileMap, startAction, startCanvas, filenames, 
			   nFrames, startRgen, startPos, startViewPort)
{
}

void Player::move(int viewportWorldX, int viewportWorldY)
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

bool Player::collision(Rectangle r)
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

void Player::canSpriteMove(int viewportWorldX, int viewportWorldY)
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
		int spriteXPos;
		int spriteYPos;
		
		// depending on the sprites bearing values are created 
		// to position the hitbox on the sprite
		// these values will create the box around the sprites feet
		// hard coded at this stage will modifiy at a later date to be more generic
		switch(bearing)
		{
			case NORTH:
				spriteXPos = frameWidth / 2; 
				spriteYPos = 60;				
				break;
			case EAST:
				spriteXPos = frameWidth - 40;
				spriteYPos = frameHeight - 30;
				break;
			case SOUTH:
				spriteXPos = 40;
				spriteYPos = frameHeight - 15;
				break;
			case WEST:
				spriteXPos = 40;
				spriteYPos = frameHeight - 30;
				break;
		}
		
		// for drawing hit box to the canvas
		viewportSpriteX += spriteXPos;
		viewportSpriteY += spriteYPos;		
		boundsX = viewportSpriteX;
		boundsY = viewportSpriteY;		
		//**************************************************
		
		// Current pixel plus half framewidth puts pixel in 
		// center of knight then devides to get tile position 
		int newTilePosY = (newSpriteYPos + spriteYPos) / T_SIZE;
		int newTilePosX = (newSpriteXPos + spriteXPos) / T_SIZE;

		// Gets the new tile value from the map (look ahead)
		int tileValue = tileMap->getMapValue(newTilePosX, newTilePosY);
		
		if(tileMap->isGrass(newTilePosY, newTilePosX)) // If the tile is grass change movement speed to 1
		{
			xMag = 1;
			yMag = 1;
		}
		
		if(tileMap->isCobblestone(newTilePosY, newTilePosX)) // If the tile is cobblestone change movement speed to 2
		{
			xMag = 3;
			yMag = 3;
		}		
		
		if(!tileMap->isSolid(newTilePosY, newTilePosX)) // If the tile is not flowers apply new move position
		{			
			xPos = newSpriteXPos;
			yPos = newSpriteYPos;
		}
}
