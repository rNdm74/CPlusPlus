#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, array<String^>^ filenames, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort)
	{
		tileMap = startTileMap;
		action = startAction;
		canvas = startCanvas;
		frames = nFrames;
		rGen = startRGen;
		viewPort = startViewPort;
		boundsRect = tileMap->getMapBounds();
		walking = true;
		alive = true;

		bounds = gcnew array<Point>(20);

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
		// Init directional point array with values 
		// that will move the sprite in specific directions
		//=================================================
		spriteDirection = gcnew array<Point>(MAX_DIRECTIONS);

		spriteDirection[NORTH] = Point(0,-1);
		spriteDirection[EAST] = Point(1,0);
		spriteDirection[SOUTH] = Point(0,1);
		spriteDirection[WEST] = Point(-1,0);

		
		//=================================================
		// Initialize bearing with a random one
		//=================================================
		bearing = EAST;


		//=================================================
		// Set mag speed for the sprite
		//=================================================
		xMag = SPEED;
		yMag = SPEED;


		//=================================================
		// Picks a random frame to be drawn this creates a random
		// look of all the sprites used in the game and that all 
		// will not start with the same frame animation
		//=================================================
		currentFrame = rGen->Next(frames-1);// minus 1 to keep in bounds

		//=================================================
		// Gets the frame width and hight the sprites 
		// frame being drawn to the screen
		//=================================================
		//frameWidth = spriteSheets[bearing]->Width / frames;
		//frameHeight = spriteSheets[bearing]->Height;


		//=================================================
		// Set initial position
		//=================================================
		xPos = startPos.X;
		yPos = startPos.Y;
		
		bounds = gcnew array<Point>(4);
		boundPoints = gcnew array<Point>(4);
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
		// REDUNDANT
	}

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

void Sprite::draw()
	{
		//=================================================
		// Draw sprites frame to the screen
		// Its position is based on its worldX and worldY
		//=================================================
		canvas->DrawImage
		(
			spriteSheets[bearing], 
			xPos, 
			yPos, 
			frameRectangle, 
			GraphicsUnit::Pixel
		);		
	}

void Sprite::draw(int newXPos, int newYPos)
	{
		//=================================================
		// Draw sprites frame to the screen
		//=================================================
		if(alive)
		{
			Bitmap^ cloneBitmap;			

			System::Drawing::Imaging::PixelFormat format = spriteSheets[bearing]->PixelFormat;
			cloneBitmap = spriteSheets[bearing]->Clone(frameRectangle, format);

			if(bearing == WEST)
			{
				cloneBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);				
			}

			canvas->DrawImage
			(
				cloneBitmap,
				newXPos,
				newYPos
			);



			/*canvas->DrawImage
			(
				spriteSheets[bearing], 
				newXPos, 
				newYPos, 
				frameRectangle, 
				GraphicsUnit::Pixel
			);*/
		}

		// Draws the hit box on top of the sprite  (for debugging)
		/*int s1XPos = (xPos - viewPort->getViewportWorldX()) + (frameWidth / 3);
		int s1YPos = (yPos - viewPort->getViewportWorldY())  + (frameHeight / 3);*/

		canvas->DrawRectangle
		(
			gcnew Pen(Color::Fuchsia), 
			Rectangle
			(
				bounds[0].X, 
				bounds[0].Y, 
				1, 
				1
			)
		);
		canvas->DrawRectangle
		(
			gcnew Pen(Color::Fuchsia), 
			Rectangle
			(
				bounds[1].X, 
				bounds[1].Y, 
				1, 
				1
			)
		);
		canvas->DrawRectangle
		(
			gcnew Pen(Color::Fuchsia), 
			Rectangle
			(
				bounds[2].X, 
				bounds[2].Y, 
				1, 
				1
			)
		);
		canvas->DrawRectangle
		(
			gcnew Pen(Color::Fuchsia), 
			Rectangle
			(
				bounds[3].X, 
				bounds[3].Y, 
				1, 
				1
			)
		);
		//canvas->DrawRectangle(gcnew Pen(Color::Fuchsia), hitbox);
	}

void Sprite::erase(Color eraseColor)
	{
		//=================================================
		// Draw coloured rectangle over sprite
		//=================================================
		Brush^ brush = gcnew SolidBrush(eraseColor);
		Rectangle rect = Rectangle(xPos, yPos, frameRectangle.Width, frameRectangle.Height);
		canvas->FillRectangle(brush, rect);
	}

void Sprite::move(int viewportWorldX, int viewportWorldY)
	{
		// OVERRIDDEN FUNCTION		
	}

void Sprite::canSpriteMove(int viewportWorldX, int viewportWorldY)
	{
		// OVERRIDDEN FUNCTION
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
		int newBearing = (bearing + (MAX_DIRECTIONS / HALF)) % MAX_DIRECTIONS; 

		// If new bearing is in acceptable range
		bool inRange = newBearing < MAX_DIRECTIONS && newBearing >= 0;
		
		if(inRange) bearing = static_cast<EBearing>(newBearing);

		// if illegal direction bearing unchanged 
		// throwing exception is more appropriate	
	}

void Sprite::die()
	{
		// NOT IMPLIMENTED YET
		alive = false;
		xMag = 0;
		yMag = 0;
	}

void Sprite::stop()
	{
		// NOT IMPLIMENTED YET
	}

void Sprite::updateFrame()
	{
		//=================================================
		// Update sprites frame is not standing
		//=================================================
				
		currentFrame %= frames; // c = c%f;

		//frameRectangle = Rectangle(currentFrame * frameWidth, 0, frameWidth, frameHeight);

		frameWidth = sheetData[bearing, currentFrame, 2];
		frameHeight = sheetData[bearing, currentFrame, 3];
		
		frameRectangle = Rectangle
		(
			sheetData[bearing, currentFrame, 0],
			sheetData[bearing, currentFrame, 1],
			sheetData[bearing, currentFrame, 2],
			sheetData[bearing, currentFrame, 3]
		);
		
		// this is to slow down the frame animation so that the sprites have a more realistic movement
		bool changeFrame = frameTime > 2;

		if(changeFrame && walking) 
		{
			frameTime = 0; // resets frame time

			currentFrame++; // move to sprites next frame
		}

		frameTime++; // increase frame time

		
	}

void Sprite::setSpriteSheet() 
	{		
		// NOT IMPLIMENTED this will handle multiple spritesheets
	}

void Sprite::wander()
	{
		//=================================================
		// Depending on a specified probability 
		// a random bearing is picked for the sprite
		//=================================================
		if(rGen->Next(WANDER_PROB) == 0) bearing = getRandomBearing();
	}
