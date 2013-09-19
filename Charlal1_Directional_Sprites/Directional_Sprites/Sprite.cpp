#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(TileMap^ startTileMap, EBoundsAction startAction, Graphics^ startCanvas, 
			   array<String^>^ filenames, int nFrames, 
			   Random^ startRGen,Point startPos, Rectangle startBounds)
	{
		tileMap = startTileMap;
		action = startAction;
		canvas = startCanvas;
		frames = nFrames;
		rGen = startRGen;
		boundsRect = startBounds;
		walking = true;
		alive = true;

		//=================================================
		// Create spritesheets from file names
		//=================================================
		spriteSheets = gcnew array<Bitmap^>(filenames->Length);
		
		for(int i = 0; i < filenames->Length; i++)
		{
			spriteSheets[i] = gcnew Bitmap(filenames[i]);
			spriteSheets[i]->MakeTransparent(spriteSheets[i]->GetPixel(0,0));			
		}

		//=================================================
		// Init directional point array
		//=================================================
		spriteDirection = gcnew array<Point>(MAX_DIRECTIONS);

		spriteDirection[NORTH] = Point(0,-1);
		spriteDirection[EAST] = Point(1,0);
		spriteDirection[SOUTH] = Point(0,1);
		spriteDirection[WEST] = Point(-1,0);

		
		//=================================================
		// Get random bearing
		//=================================================
		bearing = getRandomBearing();


		//=================================================
		// Set mag speed
		//=================================================
		xMag = SPEED;
		yMag = SPEED;


		//=================================================
		// Get frame to be drawn
		//=================================================
		currentFrame = rGen->Next(frames-1);// minus 1 to keep in bounds

		frameWidth = spriteSheets[bearing]->Width / frames;
		frameHeight = spriteSheets[bearing]->Height;


		//=================================================
		// Set initial position
		//=================================================
		xPos = startPos.X;
		yPos = startPos.Y;
	}

EBearing Sprite::getRandomBearing()
	{
		//=================================================
		// Return a random EBearing
		//=================================================
		int pick = rGen->Next(MAX_DIRECTIONS);

		switch(pick)
		{
			case 0:
				return NORTH;
			case 1:
				return EAST;
			case 2:
				return SOUTH;
			case 3:
				return WEST;
		}
	}

void Sprite::update()
	{	
		updateFrame();
	}

void Sprite::draw()
	{
		//=================================================
		// Draw sprites frame to the screen
		//=================================================
		canvas->DrawImage
		(
			spriteSheets[bearing], 
			xPos, 
			yPos, 
			srcRectangle, 
			GraphicsUnit::Pixel
		);		
	}

void Sprite::draw(int newXPos, int newYPos)
	{
		//=================================================
		// Draw sprites frame to the screen
		//=================================================
		canvas->DrawImage
		(
			spriteSheets[bearing], 
			newXPos, 
			newYPos, 
			srcRectangle, 
			GraphicsUnit::Pixel
		);		
	}

void Sprite::erase(Color eraseColor)
	{
		//=================================================
		// Draw coloured rectangle over sprite
		//=================================================
		Brush^ brush = gcnew SolidBrush(eraseColor);
		Rectangle rect = Rectangle(xPos, yPos, srcRectangle.Width, srcRectangle.Height);
		canvas->FillRectangle(brush, rect);
	}

void Sprite::move(int viewportWorldX, int viewportWorldY)
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

void Sprite::canSpriteMove(int viewportWorldX, int viewportWorldY)
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
		}
		
		viewportKnightX += knightXPos;
		viewportKnightY += knightYPos;
		//
		//**************************************************
		
		int newTilePosX = (newKnightXPos + knightXPos) / T_SIZE;
		int newTilePosY = (newKnightYPos + knightYPos) / T_SIZE;

		if(tileMap->getMapValue(newTilePosX, newTilePosY) == 0);

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

bool Sprite::isBoundsCollision()// should return info
	{
		//=======================================================================
		// checks the top, right, bottom and left side of the sprite
		// if outside of the specified area an action is triggered
		//======================================================================= 
		
		bool hitLeft = xPos < boundsRect.Left;						// Check left

		bool hitRight = xPos + frameWidth > boundsRect.Right;		// Check right

		bool hitTop = yPos < boundsRect.Top;						// Check top

		bool hitBottom = yPos + frameHeight > boundsRect.Bottom;	// Check bottom

		/*int col = xPos / T_SIZE;
		int row = yPos / T_SIZE;

		ETileType tile = tilemap->getTileType(row, col);

		bool solidTile =  tile == SOLID;*/

		return ( hitLeft || hitRight || hitTop || hitBottom );	


	}

void Sprite::executeBoundsAction()
	{
	    //=======================================================================
	    // Depending on the selected action of a sprite, a function will be
		// called that will force the sprite to do a specific action 
		// e.g. wrap around the screen or bounce off an object
		//=======================================================================
	    switch(action)
	    {
		    case BOUNCE:
			    reverse();	// Reverse sprites direction
			    break;
		    case WRAP:
			    wrap();		// Allows sprite wrap the screen e.g. right side to the left
			    break;
		    case DIE:
			    die();		// Sprite dies
			    break;
		    case STOP:
			    stop();		//Stop the sprite from moving
			    break;
	    }
	}

void Sprite::wrap()
	{
		switch(bearing)
		{
			case NORTH:
				yPos = 480;
			break;

			case EAST:
				xPos = 0;
			break;

			case SOUTH:
				yPos = 0;
			break;

			case WEST:
				xPos = 640;
			break;
		}
	}

void Sprite::reverse()
	{
		// Reverse direction for bounce, modulo required for wrap around
		// Current bearings + half total directions mod max number directions)
		// This is to reverse the direction of our sprite, 
		// todo this we must add to our current bearing enumeration
		// Then after we have added we must use modulo to wrap around 
		// and the correct oposite direction is chosen
		int newBearing = (bearing + (MAX_DIRECTIONS / HALF)) % MAX_DIRECTIONS; 

		// If new bearing is in acceptable range
		bool inRange = newBearing < MAX_DIRECTIONS && newBearing >= 0;
		
		if(inRange) bearing = static_cast<EBearing>(newBearing);

		// if illegal direction bearing unchanged 
		// throwing exception is more appropriate	
	}

void Sprite::die()
	{
		alive = false;
	}

void Sprite::stop()
	{
		//walking = false;
	}

void Sprite::updateFrame()
	{
		//=================================================
		// Update sprites frame is not standing
		//=================================================
		
		currentFrame %= frames; // does this work?  c = c%f;

		srcRectangle = Rectangle(currentFrame * frameWidth, 0, frameWidth, frameHeight);

		bool changeFrame = frameTime > 2;

		if(changeFrame && walking) 
		{
			frameTime = 0;

			currentFrame++;
		}

		frameTime++;
	}

void Sprite::setSpriteSheet() // multiple sheets?
	{				
	}

void Sprite::wander()
	{
		//=================================================
		// Randomly change sprites bearing
		//=================================================
		if(rGen->Next(WANDER_PROB) == 0) bearing = getRandomBearing();
	}
