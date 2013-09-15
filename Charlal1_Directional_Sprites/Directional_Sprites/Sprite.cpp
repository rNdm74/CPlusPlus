#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(EBoundsAction startAction, Graphics^ startCanvas, 
			   array<String^>^ filenames, int nFrames, 
			   Random^ startRGen,Point startPos, Rectangle startBounds)
	{
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
		move();	
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

void Sprite::erase(Color eraseColor)
	{
		//=================================================
		// Draw coloured rectangle over sprite
		//=================================================
		Brush^ brush = gcnew SolidBrush(eraseColor);
		Rectangle rect = Rectangle(xPos, yPos, srcRectangle.Width, srcRectangle.Height);
		canvas->FillRectangle(brush, rect);
	}

void Sprite::move()
	{
		//=======================================================================
		// If sprite can walk the xPosition and yPosition is incremented
		// the a set magnitude, a direction is then applied to the magnitude 1, -1
		// this will allow the sprite to move up, down, left and right
		//=======================================================================
		if(isBoundsCollision())
			executeBoundsAction();		// pull thus out

		if(walking)
		{
			xPos += xMag * spriteDirection[bearing].X;
			yPos += yMag * spriteDirection[bearing].Y;
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
		walking = false;
	}

void Sprite::updateFrame()
	{
		//=================================================
		// Update sprites frame is not standing
		//=================================================
		currentFrame %= frames; // does this work?  c = c%f;

		srcRectangle = Rectangle(currentFrame * frameWidth, 0, frameWidth, frameHeight);

		if(walking) currentFrame++;
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
