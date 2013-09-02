#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ filenames, Random^ startRGen, Rectangle startBounds)
	{
		canvas = startCanvas;
		boundsRect = startBounds;
		rGen = startRGen;
		knight = nullptr;

		init(filenames);

		//=================================================
		// Set initial position
		//=================================================
		xPos = rGen->Next(boundsRect.Width);
		yPos = rGen->Next(boundsRect.Height);

		//xVel = 0.1;
		//yVel = 0;
	}

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ filenames, Random^ startRGen, Rectangle startBounds, Sprite^ startKnight)
	{
		canvas = startCanvas;
		boundsRect = startBounds;
		rGen = startRGen;
		knight = startKnight;

		init(filenames);

		//=================================================
		// Set initial position
		//=================================================
		xPos = rGen->Next(boundsRect.Width);
		yPos = rGen->Next(boundsRect.Height);

		//xVel = 0.1;
		//yVel = 0;
	}

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ filenames, Random^ startRGen, int startXPos, int startYPos, int startXVel, int startYVel)
	{
		canvas = startCanvas;
		rGen = startRGen;
		xPos = startXPos;
		yPos = startYPos;
		xMag = startXVel;
		yMag = startYVel;

		init(filenames);
	}

void Sprite::init(array<String^>^ filenames)
	{
		//=================================================
		// Init spritesheets from file names
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
		spriteDirection = gcnew array<Point>(filenames->Length);

		spriteDirection[NORTH] = Point(0,-1);
		spriteDirection[SOUTH] = Point(0,1);
		spriteDirection[EAST] = Point(1,0);
		spriteDirection[WEST] = Point(-1,0);
		
		bearing = getBearing();

		xMag = 0.25;
		yMag = 0.25;

		initFrame();
	}

EBearing Sprite::getBearing()
	{
		int pick = rGen->Next(4);

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

void Sprite::initFrame()
	{
		//=================================================
		// Init frame to be drawn
		//=================================================
		nFrames = spriteSheets[bearing]->Width / spriteSheets[bearing]->Height;
		
		currentFrame = rGen->Next(nFrames-1);

		frameWidth = spriteSheets[bearing]->Width / nFrames;
		frameHeight = spriteSheets[bearing]->Height;
	}

void Sprite::draw()
	{
		canvas->DrawImage
		(
			spriteSheets[bearing], 
			(float)xPos, 
			(float)yPos, 
			srcRectangle, 
			GraphicsUnit::Pixel
		);		
	}

void Sprite::erase(Color eraseColor)
	{
		canvas->FillRectangle(gcnew SolidBrush(eraseColor),srcRectangle);
	}

void Sprite::move()
	{
		checkBounds();

		xPos += xMag * spriteDirection[bearing].X;
		yPos += yMag * spriteDirection[bearing].Y;
	}

void Sprite::checkBounds()
	{
		if(knight != nullptr)
		{
			RectangleF r1 = RectangleF
			(
				xPos, 
				yPos, 
				srcRectangle.Width, 
				srcRectangle.Height
			);

			RectangleF r2 = RectangleF
			(
				knight->getXPos(), 
				knight->getYPos(), 
				knight->getSrcRectangle().Width, 
				knight->getSrcRectangle().Height
			);
			
			if(r1.IntersectsWith(r2))
			{
				if(bearing == NORTH) bearing = SOUTH;
				if(bearing == SOUTH) bearing = NORTH;
				if(bearing == EAST) bearing = WEST;
				if(bearing == WEST) bearing = EAST;
				
			}
		}

		if(xPos + frameWidth > boundsRect.Width) bearing = WEST;
		if(yPos + frameWidth > boundsRect.Height) bearing = NORTH;

		if(xPos < 0) bearing = EAST;
		if(yPos < 0) bearing = SOUTH;
	}

void Sprite::updateFrame()
	{
		currentFrame %= nFrames;

		srcRectangle = Rectangle(currentFrame * frameWidth, 0, frameWidth-1, frameHeight);

		currentFrame++;
	}

void Sprite::setSpriteSheet(EBearing b)
	{
		//spriteSheet = newSpriteSheet;

		//nFrames = newNframes;

		//initFrame(b);		
	}

void Sprite::wander()
	{
		if(rGen->Next(WANDER_PROB) == 0) bearing = getBearing();
	}