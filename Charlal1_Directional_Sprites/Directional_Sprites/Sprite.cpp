#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ filenames, int nFrames, Random^ startRGen, Rectangle startBounds)
	{
		canvas = startCanvas;
		frames = nFrames;
		rGen = startRGen;
		boundsRect = startBounds;
		walking = true;
		

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
		spriteDirection[SOUTH] = Point(0,1);
		spriteDirection[EAST] = Point(1,0);
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
		currentFrame = rGen->Next(frames-1);

		frameWidth = spriteSheets[bearing]->Width / frames;
		frameHeight = spriteSheets[bearing]->Height;


		//=================================================
		// Set initial position
		//=================================================
		xPos = rGen->Next(boundsRect.Width - frameWidth);
		yPos = rGen->Next(boundsRect.Height - frameHeight);
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
				return SOUTH;
			case 2:
				return EAST;
			case 3:
				return WEST;
		}
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
		//=================================================
		// Move if sprite is walking
		//=================================================
		if(walking)
		{
			xPos += xMag * spriteDirection[bearing].X;
			yPos += yMag * spriteDirection[bearing].Y;
		}
	}

void Sprite::checkBounds()
	{
		//=================================================
		// If sprite goes out of bounds change direction
		//=================================================
		if(xPos + frameWidth > boundsRect.Width) bearing = WEST;
		if(yPos + frameWidth > boundsRect.Height) bearing = NORTH;

		if(xPos < 0) bearing = EAST;
		if(yPos < 0) bearing = SOUTH;
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
