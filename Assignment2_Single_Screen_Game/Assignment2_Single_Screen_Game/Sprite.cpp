#include "StdAfx.h"
#include "Sprite.h"

#pragma region Constructor

	Sprite::Sprite
		(
			Graphics^ startCanvas, 
			Viewport^ startViewPort, 
			FileReader^ startReader, 
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
			state = STAND;	
			alive = true;
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
			spriteDirection[HURT] = Point(0,0);
			//
			// Collision offsets
			//
			collisionOffsets = gcnew array<Point>(MAX_DIRECTIONS);
			collisionOffsets[NORTH] = Point(NORTH_X, NORTH_Y);						
			collisionOffsets[EAST] =  Point(EAST_X, EAST_Y);						
			collisionOffsets[SOUTH] = Point(SOUTH_X, SOUTH_Y);						
			collisionOffsets[WEST] =  Point(WEST_X, WEST_Y);						
			collisionOffsets[STAND] = Point(CENTER_X, CENTER_Y);					
			collisionOffsets[HURT] =  Point(CENTER_X, CENTER_Y);					
			//
			// Picks a random frame to be drawn this creates a random
			// look of all the sprites used in the game and that all 
			// will not start with the same frame animation
			//
			currentFrame = rGen->Next(spriteSheetData->GetLength(1));		// 1 is the array dimension			
			//
			// Sprites Width and Height based on state 
			//
			frameWidth = spriteSheetData[state, currentFrame, WIDTH];
			frameHeight = spriteSheetData[state, currentFrame, HEIGHT];
			//
			// Creates sprites frame to be drawn
			//
			spriteFrame = Rectangle
			(
				spriteSheetData[state, currentFrame, X],					// XPOS
				spriteSheetData[state, currentFrame, Y],					// YPOS
				spriteSheetData[state, currentFrame, WIDTH],				// WIDTH
				spriteSheetData[state, currentFrame, HEIGHT]				// HEIGHT
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
		if(state == WEST) spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
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
		if(state == WEST) spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
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
		if((tileType == LADDER_COIN || tileType == LADDER) && (state == NORTH || state == SOUTH))
		{
			xPos = col * T_SIZE; // Converts col back to pixels
		}
		//
		// Clamps to tile yPos
		//
		if((tileType == COIN ||tileType == WALKABLE) && (state == WEST || state == EAST))
		{
			yPos = (row * T_SIZE) - (frameHeight - T_SIZE); // Converts row back to pixels
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
		int col = (xPos + collisionOffsets[state].X) / T_SIZE;
		int row = (yPos + (frameHeight + collisionOffsets[state].Y)) / T_SIZE;			
		//
		// Set sprite walking 
		//
		walking = (tileMap->isWalkable(row, col)  || 
				   tileMap->isCoin(row, col)	  || 
				   tileMap->isClimbable(row, col) ||
				   tileMap->getTileType(row, col) == EXIT);		
		//
		// If sprite is walking move then clamp to column  || row
		//
		if(walking)
		{
			// Move sprite
			yPos += yMag * spriteDirection[state].Y;
			xPos += xMag * spriteDirection[state].X; 

			// Clamp sprite to col and row
			clamp(col, row);
		}
		//
		//	Executes the set action for a sprite on a bounds collsion
		//	the bounds collision is primarily the form window rectangle
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
		// Sets frame width and height based on spritesheet state
		//
		frameWidth = spriteSheetData[state, currentFrame, WIDTH];		
		frameHeight = spriteSheetData[state, currentFrame, HEIGHT];	
		//
		// Sets spriteframe to based on state, current frame to be drawn
		// The state is the sprite STATE e.g. NORTH, SOUTH, HURT etc
		//
		spriteFrame = Rectangle
		(
			spriteSheetData[state, currentFrame, X],						
			spriteSheetData[state, currentFrame, Y],					
			spriteSheetData[state, currentFrame, WIDTH],				
			spriteSheetData[state, currentFrame, HEIGHT]			
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
	void Sprite::hurt(SoundManager^ sManager)
	{
		if(!alive && !hurtSound)
		{			
			sManager->playerHurt->Play();			// play hurt sound here

			hurtSound = true;
		}
		//
		// Gives time for the player to not be hurt 
		// for a period of time
		//
		if(hurtTime > HURT_DELAY) 
		{
			hurtSound = !hurtSound;
			alive = !alive;
			state = STAND;
			hurtTime = 0;			
		}
		
		hurtTime++;
	}
	//
	// If the sprite crosses the exit tile it will return true
	//
	bool Sprite::isLevelWin()
	{
		// Gets the current tiles col and row
		int col = (xPos + collisionOffsets[STAND].X) / T_SIZE;
		int row = (yPos + (frameHeight + collisionOffsets[STAND].Y)) / T_SIZE;

		// return if tile is equal to the EXIT tile
		return tileMap->getTileType(row, col) == EXIT;
	}
	//
	// Checks if another sprite has collided with this sprite
	//
	bool Sprite::collided(Sprite^ otherSprite)
	{
		bool collided = true;
		
		if(alive)
		{
			// Offsets X Y rectangle
			int offsetX = frameWidth / PERCENTAGE;
			int offsetY = frameHeight / PERCENTAGE;

			// Creates 2 rectangles based from offsets
			Rectangle s1 = Rectangle
			(
				xPos + offsetX, 
				yPos + offsetY, 
				frameWidth - offsetX, 
				frameHeight - offsetY
			);

			Rectangle s2 = Rectangle
			(
				otherSprite->getXPos() + offsetX, 
				otherSprite->getYPos() + offsetY, 
				otherSprite->getWidth() - offsetX, 
				otherSprite->getHeight() - offsetY
			);

			// Runs checks
			if(s1.Bottom  < s2.Top)	 collided = false;
			if(s1.Top > s2.Bottom)	 collided = false;
			if(s1.Right < s2.Left)	 collided = false;
			if(s1.Left > s2.Right)	 collided = false;			
		}			

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
		// Depending on what state the sprite is when called 
		// the players position is changed to wrap around the screen
		switch(state)
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
		// Current states + half total directions mod max number directions)
		// This is to reverse the direction of our sprite, 
		// todo this we must add to our current state enumeration
		// Then after we have added we must use modulo to wrap around 
		// and the correct oposite direction is chosen
		int newState = (state + (N_DIRECTIONS / HALF)) % N_DIRECTIONS; 

		// If new state is in acceptable range
		bool inRange = newState < N_DIRECTIONS && newState >= 0;
		
		if(inRange) state = static_cast<EState>(newState);		
		// if illegal direction state unchanged 
		// throwing exception is more appropriate			
	}

	void Sprite::die()
	{
		//
		// 
		//
		if(alive) lives--;		// Takes away life need as to many lives will be taken away 

		alive = false;			// Sprite is not alive
		
		coins = 0;				// Player looses all collected coins

		state = HURT;			// For effect that the sprite is hurt

		action = STOP;			// Set back to default action
	}

	void Sprite::coin()
	{		
		coins++;				// Picks up a coin

		score += COIN_PICKUP;	// Appends to score

		action = STOP;			// Set back to default action
	}

	void Sprite::stop()
	{
		if(state == WEST)
			xPos = tileMapBounds.Left;										// clamps sprite 

		if(state == EAST)
			xPos = (tileMapBounds.Right - frameWidth) - (T_SIZE / HALF);	// clamps sprite
	}

#pragma endregion


#pragma region Tile Methods	
	//
	//	Stops the sprite from trying to move when is it not wanted to
	//
	void Sprite::setState(EState newState)
	{
		if(alive)
		{
			int col = (xPos + collisionOffsets[newState].X) / T_SIZE;
			int row = (yPos + (frameHeight + collisionOffsets[newState].Y)) / T_SIZE;

			// Sets flag conditions
			bool climbable = tileMap->isClimbable(row, col);
			bool walkable  = tileMap->isWalkable(row, col);
			bool solid	   = tileMap->isSolid(row, col);

			bool moveNorth = newState == NORTH && climbable || walkable;
			bool moveSouth = newState == SOUTH && climbable;
			bool moveWest  = newState == WEST  && !solid;
			bool moveEast  = newState == EAST  && !solid;
			bool stand	   = newState == STAND;	

			// Only update state (move) if these conditions are true
			if(moveNorth || moveSouth || moveWest || moveEast || stand) 
			{
				state = newState;
			}
		}						
	}
	//
	// Queries the tilemap to get type of tile
	// sprite is currently on based on offsets
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
	// Changes a coin tile to its default tile, 
	// the return is required for the score to be updated 
	//
	bool Sprite::collectCoin()
	{
		// Gets the current col and row
		int col = (xPos + collisionOffsets[STAND].X) / T_SIZE;
		int row = (yPos + (frameHeight + collisionOffsets[STAND].Y)) / T_SIZE;

		bool coin = tileMap->isCoin(row, col);
		bool laddercoin = tileMap->isLadderCoin(row, col);

		// Reset COIN tile
		if(coin)
		{
			tileMap->setMapValue(col, row, DEFAULT_TILE);

			return true;
		}

		// Reset LADDER_COIN tile
		if(laddercoin)
		{
			tileMap->setMapValue(col, row, LADDER_TILE);

			return true;
		}

		// No coin has been collected
		return false;
	}

	void Sprite::wander()
	{
		// Depending on a specified probability 
		// a random state is picked for the sprite
		if(rGen->Next(WANDER_PROB) == 0) 
			setState(getRandomState());

		// If the sprite reaches
		// the top or bottom of a ladder 
		// sets a new direction
		if(!walking) 
			setState(getRandomState());
	}
	//
	//
	//
	EState Sprite::getRandomState()
	{
		//
		// Return a random EState
		//
		int pick = rGen->Next(N_DIRECTIONS);

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