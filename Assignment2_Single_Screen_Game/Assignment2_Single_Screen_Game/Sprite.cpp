#include "StdAfx.h"
#include "Sprite.h"

#pragma region Constructor

	Sprite::Sprite(TileMap^ startTileMap, Viewport^ startViewPort, 
				   EBoundsAction startAction, ESprite startSprite,
				   Graphics^ startCanvas, String^ filename,
				   Random^ startRGen, array<int,3>^ startMap, 
				   int startXMag, int startYMag, int startFrameDelay)
		{
			tileMap = startTileMap;
			action = startAction;
			canvas = startCanvas;
			rGen = startRGen;
			viewPort = startViewPort;
			boundsRect = tileMap->getMapBounds();
			sheetData = startMap;		
			walking = true;
			alive = true;
			//
			//
			//
			switch(startSprite)
			{
				case PLAYER:
					player = true;
					break;
				case ENEMY:
					enemy = true;
					break;
				case FLAG:
					flag = true;
					break;
				case COIN:
					coin = true;
					break;
			}
			//
			// Create spritesheets from file names
			//
			spriteSheet = gcnew Bitmap(filename);
			spriteSheet->MakeTransparent(spriteSheet->GetPixel(0,0));
			format = spriteSheet->PixelFormat;
			//
			// Init directional point array with values 
			// that will move the sprite in specific directions
			//
			spriteDirection = gcnew array<Point>(MAX_DIRECTIONS);
			spriteDirection[NORTH] = Point(0,-1);
			spriteDirection[EAST] = Point(1,0);
			spriteDirection[SOUTH] = Point(0,1);
			spriteDirection[WEST] = Point(-1,0);
			spriteDirection[STAND] = Point(0,0);
			//
			//
			//
			offsets = gcnew array<Point>(MAX_DIRECTIONS);
			offsets[NORTH] = Point(35, -75);
			offsets[EAST] = Point(75, -35);
			offsets[SOUTH] = Point(35, 2);
			offsets[WEST] = Point(-2, -35);
			offsets[STAND] = Point(35,-35);			
			//
			// Initialize bearing with a random one
			//
			bearing = STAND;
			//
			// Set mag speed for the sprite
			//
			xMag = startXMag;
			yMag = startYMag;
			//
			// Picks a random frame to be drawn this creates a random
			// look of all the sprites used in the game and that all 
			// will not start with the same frame animation
			//
			currentFrame = rGen->Next(sheetData->GetLength(1));// minus 1 to keep in bounds
			//
			// Gets the frame width and hight the sprites 
			// frame being drawn to the screen
			//
			frameDelay = startFrameDelay;
			//
			//
			//
			frameWidth = sheetData[bearing, currentFrame, WIDTH];
			frameHeight = sheetData[bearing, currentFrame, HEIGHT];
		}

#pragma endregion


#pragma region Draw, Erase, Move
	//
	//
	//
	void Sprite::draw(int newXPos, int newYPos)
	{
		//=================================================
		// Draw sprites frame to the screen
		//=================================================

		if(alive)
		{	
			spriteBitmap = spriteSheet->Clone(frameRectangle, format);

			if(bearing == WEST)	
				spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	

			canvas->DrawImage
			(
				spriteBitmap,
				newXPos,
				newYPos
			);
		}				
	}
	//
	//
	//
	void Sprite::erase(Color eraseColor)
	{
		//=================================================
		// Draw coloured rectangle over sprite
		//=================================================
		Brush^ brush = gcnew SolidBrush(eraseColor);
		Rectangle rect = Rectangle(xPos, yPos, frameRectangle.Width, frameRectangle.Height);
		canvas->FillRectangle(brush, rect);
	}
	//
	//
	//
	void Sprite::move(int viewportWorldX, int viewportWorldY)
	{
		//=======================================================================
		// If sprite can walk the xPosition and yPosition is incremented
		// the a set magnitude, a direction is then applied to the magnitude 1, -1
		// this will allow the sprite to move up, down, left and right
		//=======================================================================	
		

		canSpriteMove(viewportWorldX, viewportWorldY);

		if(isBoundsCollision())
			executeBoundsAction();
	}
	//
	//
	//
	void Sprite::updateFrame()
	{
		//=================================================
		// Update sprites frame is not standing
		//=================================================
				
		currentFrame %= sheetData->GetLength(1);					// c = c%f;
		
		frameWidth = sheetData[bearing, currentFrame, WIDTH];		//
		frameHeight = sheetData[bearing, currentFrame, HEIGHT];		//
		
		frameRectangle = Rectangle
		(
			sheetData[bearing, currentFrame, X],					// XPOS
			sheetData[bearing, currentFrame, Y],					// YPOS
			sheetData[bearing, currentFrame, WIDTH],				// WIDTH
			sheetData[bearing, currentFrame, HEIGHT]				// HEIGHT
		);
		//
		// This is to slow down the frame animation 
		// so that the sprites have a more realistic animation
		//		
		if(walking && frameTime > frameDelay) 
		{
			frameTime = 0;											// resets frame time

			currentFrame++;											// move to sprites next frame
		}

		frameTime++;												// increase frame time		
	}
	//
	//
	//
#pragma endregion

#pragma region Check Collisions
	//
	//
	//
	bool Sprite::collided(Sprite^ sprite)
	{
		bool collided = true;

		int s1XPos = (xPos - viewPort->getViewportWorldX()) + (frameWidth / 3);
		int s1YPos = (yPos - viewPort->getViewportWorldY())  + (frameHeight / 3);

		int s2XPos = (sprite->getXPos() - viewPort->getViewportWorldX())+(sprite->getWidth() / 3);
		int s2YPos = (sprite->getYPos() - viewPort->getViewportWorldY())+(sprite->getHeight() / 3);

		Rectangle s1 = Rectangle(s1XPos, s1YPos, frameWidth / 3, frameHeight / 3);
		Rectangle s2 = Rectangle(s2XPos, s2YPos, sprite->getWidth() / 3 , sprite->getHeight() / 3);

		if(s1.Bottom  < s2.Top)	 collided = false;
		if(s1.Top > s2.Bottom)	 collided = false;
		if(s1.Right < s2.Left)	 collided = false;
		if(s1.Left > s2.Right)	 collided = false;

		return collided;	
	}
	//
	//
	//
	void Sprite::canSpriteMove(int viewportWorldX, int viewportWorldY)
	{
		walking = isTileWalkable(getTileType(offsets[bearing]));
						
		if(walking)
		{
			yPos += yMag * spriteDirection[bearing].Y;
			xPos += xMag * spriteDirection[bearing].X;	
		}

		ETileType tileType = getTileType(offsets[STAND]);

		levelwin = (tileType == EXIT);			
	}	
	//
	//
	//	
	bool Sprite::isBoundsCollision()// should return info
	{
		//=======================================================================
		// checks the top, right, bottom and left side of the sprite
		// if outside of the specified area an action is triggered
		//======================================================================= 
		
		bool hitLeft = xPos < boundsRect.Left;										// Check left

		bool hitRight = xPos + frameWidth > boundsRect.Right - (T_SIZE / HALF);		// Check right

		bool hitTop = yPos < boundsRect.Top;										// Check top

		bool hitBottom = yPos + frameHeight > boundsRect.Bottom;					// Check bottom

		return ( hitLeft || hitRight || hitTop || hitBottom );	
	}
	//
	//
	//
#pragma endregion


#pragma region Sprite Actions
	//
	//
	//
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
	//
	//
	//
	void Sprite::wrap()
	{
		// Depending on what bearing the sprite is when called 
		// the players position is changed to wrap around the screen
		switch(bearing)
		{
			case NORTH:
				// puts sprite on the south side on the screen
				yPos = tileMap->getMapBounds().Height - frameWidth; 				
			break;

			case EAST:
				// puts sprite on the west side of the screen
				xPos = 0;  
			break;

			case SOUTH:
				// puts sprite on the north side of the screen
				yPos = 0;
			break;

			case WEST:
				// puts sprite on the east side of the screen
				xPos = tileMap->getMapBounds().Width - frameWidth;
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
		int newBearing = (bearing + (4 / HALF)) % 4; 

		// If new bearing is in acceptable range
		bool inRange = newBearing < 4 && newBearing >= 0;
		
		if(inRange) bearing = static_cast<EBearing>(newBearing);		
		// if illegal direction bearing unchanged 
		// throwing exception is more appropriate	
	}

	void Sprite::die()
	{
		// NOT IMPLIMENTED YET
		/*alive = false;
		xMag = 0;
		yMag = 0;*/
	}

	void Sprite::stop()
	{
		if(bearing == WEST)
			xPos = boundsRect.Left; // clamps sprite 

		if(bearing == EAST)
			xPos = (boundsRect.Right - frameWidth) - (T_SIZE / 2); // clamps sprite
	}

#pragma endregion


#pragma region Tile Methods
	//
	//
	//
	bool Sprite::isTileWalkable(ETileType tileType)
	{
		switch(tileType)
		{
			case LADDER:
				return true;
			case WALKABLE:
				return true;
			case EXIT:
				return true;
			case LADDER_COIN:
				return true;
			case COIN:
				return true;
			case SOLID:
				return false;
		}	
	}	
	//
	//
	//
	void Sprite::setSpriteSheet() 
	{		
		// NOT IMPLIMENTED this will handle multiple spritesheets
	}
	//
	//
	//
	void Sprite::setBearing(EBearing newBearing)
	{
		ETileType tileType = getTileType(offsets[newBearing]);

		switch(newBearing)
		{
			case NORTH:
				if(tileType == LADDER || tileType == LADDER_COIN || tileType == WALKABLE)
				{
					bearing = newBearing;	
				}
				break;

			case SOUTH:
				if(tileType == LADDER || tileType == LADDER_COIN)
				{
					bearing = newBearing;	
				}
				break;

			case EAST:
				if(tileType != SOLID)
				{
					bearing = newBearing;	
				}
				break;

			case WEST:
				if(tileType != SOLID)
				{
					bearing = newBearing;	
				}
				break;

			case STAND:
				bearing = newBearing;
				break;
		}		
	}
	//
	//
	//
	ETileType Sprite::getTileType(Point offset)
	{
		int col = (xPos + offset.X) / T_SIZE;
		int row = (yPos + (frameHeight + offset.Y)) / T_SIZE;

		ETileType tileType = tileMap->getTileType(row, col);
		//
		// Clamps sprite to tile xPos
		//
		if((tileType == LADDER_COIN || tileType == LADDER) && (bearing == NORTH || bearing == SOUTH))
		{
			xPos = col * T_SIZE;
		}
		//
		// Clamps sprite to tile yPos
		//
		if((tileType == COIN ||tileType == WALKABLE) && (bearing == WEST || bearing == EAST))
		{
			yPos = (row * T_SIZE) - (frameHeight - T_SIZE);
		}
				
		return tileType;
	}
	//
	//
	//
#pragma endregion


#pragma region Additional
	//
	//
	//
	bool Sprite::collectCoin()
	{
		ETileType tileType = getTileType(offsets[STAND]);

		int col = (xPos + offsets[STAND].X) / T_SIZE;
		int row = (yPos + (frameHeight + offsets[STAND].Y)) / T_SIZE;

		if(tileType == COIN)
		{
			tileMap->setMapValue(col, row, 0);

			return true;
		}

		if(tileType == LADDER_COIN)
		{
			tileMap->setMapValue(col, row, 5);

			return true;
		}

		return false;
	}

	void Sprite::wander()
	{
		//=================================================
		// Depending on a specified probability 
		// a random bearing is picked for the sprite
		//=================================================
		if(rGen->Next(WANDER_PROB) == 0) 
			setBearing(getRandomBearing());

		if(!walking);
			//setBearing(getRandomBearing());
	}
	//
	//
	//
	EBearing Sprite::getRandomBearing()
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

#pragma endregion