#include "StdAfx.h"
#include "Sprite.h"

#pragma region Constructor

	Sprite::Sprite
		(
			Graphics^ startCanvas, 
			Viewport^ startViewPort, 
			CSVReader^ startReader, 
			TileMap^ startTileMap,
			EAction startAction,
			Random^ startRGen, 
			int startObjectNumber, 
			int startXMag, 
			int startYMag, 
			int startFrameDelay,
			String^ startFilename,
			Rectangle startTileMapBounds
		)
		{
			canvas = startCanvas;
			viewPort = startViewPort;
			tileMap = startTileMap;
			action = startAction;			
			rGen = startRGen;
			objectNumber = startObjectNumber;
			xMag = startXMag;
			yMag = startYMag;
			frameDelay = startFrameDelay;
			spriteSheetData = startReader->getSpriteSheetData(startObjectNumber);
			filename = startFilename;
			tileMapBounds = startTileMapBounds;
			bearing = STAND;
			lives = N_LIVES;					
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
			// Collision offsets
			//
			collisionOffsets = gcnew array<Point>(MAX_DIRECTIONS);
			collisionOffsets[NORTH] = Point(35, -75);
			collisionOffsets[EAST] = Point(75, -35);
			collisionOffsets[SOUTH] = Point(35, 2);
			collisionOffsets[WEST] = Point(-2, -35);
			collisionOffsets[STAND] = Point(35,-35);	
			//
			// Picks a random frame to be drawn this creates a random
			// look of all the sprites used in the game and that all 
			// will not start with the same frame animation
			//
			currentFrame = rGen->Next(spriteSheetData->GetLength(1));// minus 1 to keep in bounds			
			//
			// Sprites Width and Height based on bearing 
			//
			frameWidth = spriteSheetData[bearing, currentFrame, WIDTH];
			frameHeight = spriteSheetData[bearing, currentFrame, HEIGHT];
			//
			// Creates sprites frame to be drawn
			//
			spriteFrame = Rectangle
			(
				spriteSheetData[bearing, currentFrame, X],					// XPOS
				spriteSheetData[bearing, currentFrame, Y],					// YPOS
				spriteSheetData[bearing, currentFrame, WIDTH],				// WIDTH
				spriteSheetData[bearing, currentFrame, HEIGHT]				// HEIGHT
			);
		}

#pragma endregion


#pragma region Draw_Move_Update
	//
	//
	//
	void Sprite::draw(int newXPos, int newYPos)
	{
		//
		// Draw sprites frame to the screen
		//
		Bitmap^ spriteBitmap = spriteSheet->Clone(spriteFrame, format);
		//
		// Flips image on the X axis based on direction
		//
		if(bearing == WEST)	spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
		//
		// Draws bitmap to the screen
		//
		canvas->DrawImage
		(
			spriteBitmap,
			newXPos,
			newYPos
		);	

		delete spriteBitmap;
	}
	//
	//
	//
	void Sprite::draw()
	{
		//
		// Draw sprites frame to the screen
		//
		Bitmap^ spriteBitmap = spriteSheet->Clone(spriteFrame, format);
		//
		// Flips image on the X axis based on direction
		//
		if(bearing == WEST)	spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
		//
		// Draws bitmap to the screen
		//
		canvas->DrawImage(spriteBitmap,	xPos, yPos);	
		//
		// Clean up bitmap
		//
		delete spriteBitmap;
	}
	//
	//
	//
	void Sprite::clamp(int col, int row)
	{
		ETileType tileType = tileMap->getTileType(row, col);
		//
		// Clamps to tile xPos
		//
		if((tileType == LADDER_COIN || tileType == LADDER) && (bearing == NORTH || bearing == SOUTH))
		{
			xPos = col * T_SIZE;
		}
		//
		// Clamps to tile yPos
		//
		if((tileType == COIN ||tileType == WALKABLE) && (bearing == WEST || bearing == EAST))
		{
			yPos = (row * T_SIZE) - (frameHeight - T_SIZE);
		}
	}
	//
	//
	//
	void Sprite::move(int viewportWorldX, int viewportWorldY)
	{
		//
		// If sprite can walk the xPosition and yPosition is incremented
		// the a set magnitude, a direction is then applied to the magnitude 1, -1
		// this will allow the sprite to move up, down, left and right
		//	
		int col = (xPos + collisionOffsets[bearing].X) / T_SIZE;
		int row = (yPos + (frameHeight + collisionOffsets[bearing].Y)) / T_SIZE;			
		//
		// Set sprite walking 
		//
		walking = (tileMap->isWalkable(row, col) || tileMap->isCoin(row, col));		
		//
		// If sprite is walking move then clamp to column  || row
		//
		if(walking)
		{
			yPos += yMag * spriteDirection[bearing].Y;
			xPos += xMag * spriteDirection[bearing].X;

			clamp(col, row);
		}
		//
		//
		//
		if(isBoundsCollision())
			executeBoundsAction();
	}
	//
	//
	//
	void Sprite::updateFrame()
	{
		//
		// Update sprites frame is not standing
		//				
		currentFrame %= spriteSheetData->GetLength(1);			
		//
		// Sets frame width and height based on spritesheet bearing
		//
		frameWidth = spriteSheetData[bearing, currentFrame, WIDTH];		
		frameHeight = spriteSheetData[bearing, currentFrame, HEIGHT];	
		//
		// Sets spriteframe to based on bearing, current frame to be drawn
		//
		spriteFrame = Rectangle
		(
			spriteSheetData[bearing, currentFrame, X],					
			spriteSheetData[bearing, currentFrame, Y],					
			spriteSheetData[bearing, currentFrame, WIDTH],				
			spriteSheetData[bearing, currentFrame, HEIGHT]			
		);
		//
		// This is to slow down the frame animation 
		// so that the sprites have a more realistic animation
		//		
		if(walking && frameTime > frameDelay) 
		{
			frameTime = 0;												// resets frame time

			currentFrame++;												// move to sprites next frame
		}

		frameTime++;													// increase frame time		
	}
	//
	//
	//
#pragma endregion


#pragma region Sprite checks
	//
	//
	//
	bool Sprite::isLevelWin()
	{
		int col = (xPos + collisionOffsets[STAND].X) / T_SIZE;
		int row = (yPos + (frameHeight + collisionOffsets[STAND].Y)) / T_SIZE;

		ETileType tileType = tileMap->getTileType(row, col);

		return tileType == EXIT;
	}
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
	bool Sprite::isBoundsCollision()// should return info
	{
		//
		// checks the top, right, bottom and left side of the sprite
		// if outside of the specified area an action is triggered
		//		
		bool hitLeft = xPos < tileMapBounds.Left;										// Check left

		bool hitRight = xPos + frameWidth > tileMapBounds.Right - T_SIZE / HALF;		// Check right

		bool hitTop = yPos < tileMapBounds.Top;											// Check top

		bool hitBottom = yPos + frameHeight > tileMapBounds.Bottom;						// Check bottom

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
		//
		// Depending on the selected action of a sprite, a function will be
		// called that will force the sprite to do a specific action 
		// e.g. wrap around the screen or bounce off an object
		//
		switch(action)
		{
			case BOUNCE:
				bounce();			// Reverse sprites direction
				break;
			case WRAP:
				wrap();				// Allows sprite wrap the screen e.g. right side to the left
				break;
			case DIE:
				die();				// Sprite dies
				break;
			case COLLECT_COIN:
				coin();				// Sprite collects coin
				break;
			case STOP:
				stop();				// Stop the sprite from moving
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
				yPos = tileMap->getBounds().Height - frameWidth; 				
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
				xPos = tileMap->getBounds().Width - frameWidth;
			break;
		}
	}

	void Sprite::bounce()
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
		resetPosition(); // set hurt image

		coins = 0;

		lives--;

		action = STOP;
	}

	void Sprite::coin()
	{		
		coins++;

		score += 50;

		action = STOP;
	}

	void Sprite::stop()
	{
		if(bearing == WEST)
			xPos = tileMapBounds.Left; // clamps sprite 

		if(bearing == EAST)
			xPos = (tileMapBounds.Right - frameWidth) - (T_SIZE / 2); // clamps sprite
	}

#pragma endregion


#pragma region Tile Methods	
	//
	//
	//
	void Sprite::setBearing(EBearing newBearing)
	{
		ETileType tileType = getTileType(collisionOffsets[newBearing]);

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
						
		return tileMap->getTileType(row, col);
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
		ETileType tileType = getTileType(collisionOffsets[STAND]);

		int col = (xPos + collisionOffsets[STAND].X) / T_SIZE;
		int row = (yPos + (frameHeight + collisionOffsets[STAND].Y)) / T_SIZE;

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
		//
		// Depending on a specified probability 
		// a random bearing is picked for the sprite
		//
		if(rGen->Next(WANDER_PROB) == 0) 
			setBearing(getRandomBearing());

		if(!walking) setBearing(getRandomBearing());
	}
	//
	//
	//
	EBearing Sprite::getRandomBearing()
	{
		//
		// Return a random EBearing
		//
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
		}
	}

#pragma endregion