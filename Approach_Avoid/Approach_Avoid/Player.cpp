#include "StdAfx.h"
#include "Player.h"

Player::Player(EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRgen, Point startPos)
	   : Sprite(startAction, startCanvas, filenames, 
			   nFrames, startRgen, startPos)
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

void Player::canSpriteMove(int viewportWorldX, int viewportWorldY)
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
		int knightXPos;
		int knightYPos;

		switch(bearing)
		{
			case NORTH:
				knightXPos = frameWidth / 2; 
				knightYPos = 60;
				break;
			case EAST:
				knightXPos = frameWidth - 40;
				knightYPos = frameHeight - 15;
				break;
			case SOUTH:
				knightXPos = frameWidth / 2;
				knightYPos = frameHeight - 15;
				break;
			case WEST:
				knightXPos = 40;
				knightYPos = frameHeight - 15;
				break;
		}
		
		// for drawing hit box to the canvas
		viewportKnightX += knightXPos;
		viewportKnightY += knightYPos;
		boundsX = viewportKnightX;
		boundsY = viewportKnightY;		
		//**************************************************
		
		// current pixel plus half framewidth puts pixel in center of knight then devides to get tile position 
		//int newTilePosX = (newKnightXPos + knightXPos) / T_SIZE; 
		//int newTilePosY = (newKnightYPos + knightYPos) / T_SIZE;

		//int tile = tileMap->getMapValue(newTilePosX, newTilePosY);

		//if(tile == 0){};
		//	//executeBoundsAction();

		//// If the tile is grass change movement speed to 1
		//if(tile == 1)
		//{
		//	xMag = 1;
		//	yMag = 1;
		//}

		//// If the tile is cobblestone change movement speed to 2
		//if(tile == 2)
		//{
		//	xMag = 3;
		//	yMag = 3;
		//}

		//// If the tile is not flowers apply new move position
		//if(tile != 0)
		//{			
		//	xPos = newKnightXPos;
		//	yPos = newKnightYPos;
		//}
}
