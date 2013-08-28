#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, Random^ startRGen, Rectangle startBounds)
	{
		canvas = startCanvas;
		spriteSheet = startSpriteSheet;
		rGen = startRGen;
		boundsRect = startBounds;

		xPos = boundsRect.Width / 2;
		yPos = boundsRect.Height - spriteSheet->Height - 5;

		xVel = 0.1;
		yVel = 0;

		init();
	}

Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, Random^ startRGen, int startXPos, int startYPos, int startXVel, int startYVel)
	{
		canvas = startCanvas;
		spriteSheet = startSpriteSheet;
		rGen = startRGen;
		xPos = startXPos;
		yPos = startYPos;
		xVel = startXVel;
		yVel = startYVel;

		init();
	}

void Sprite::init()
	{
		scale = 128;

		nFrames = spriteSheet->Width / spriteSheet->Height;
		
		currentFrame = rGen->Next(nFrames-1);

		frameWidth = spriteSheet->Width / nFrames;
		frameHeight = spriteSheet->Height;

		spriteSheet->MakeTransparent(spriteSheet->GetPixel(0,0));
	}

void Sprite::draw()
	{
		if(!dead)
			spriteSheet->SetResolution(scale, scale);
			canvas->DrawImage
			(
				spriteSheet, 
				(float)xPos, 
				(float)yPos, 
				srcRectangle, 
				GraphicsUnit::Pixel
			);
	}

void Sprite::drawDead()
	{
		if(dead)
			canvas->DrawImage
			(
				spriteSheet, 
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
		if(!dead)
		{
			xPos += SPEED * xVel;
			yPos += SPEED * yVel;
		}
	}

void Sprite::checkBounds()
	{
		if(xPos + frameWidth > boundsRect.Width) xVel *= DIRECTION;
		if(xPos < 0) xVel *= DIRECTION;
	}

void Sprite::updateFrame()
	{
		currentFrame %= nFrames;

		srcRectangle = Rectangle(currentFrame * frameWidth, 0, frameWidth-1, frameHeight);

		currentFrame++;

		age++;

		if(!adult && !dead)
		{
			scale--;

			yPos -= frameHeight / scale;
		}

		if(scale < 90)
		{
			adult = true;
			scale = 90;
		}
	}

void Sprite::setSpriteSheet(Bitmap^ newSpriteSheet, int newNframes)
	{
		spriteSheet = newSpriteSheet;

		//nFrames = newNframes;

		init();		
	}

void Sprite::wander()
	{
		float currXPos = xPos;

		if(rGen->Next(WANDER_PROB) == 0)
		{
			xVel *= DIRECTION;			
		}

		//(currXPos > xPos) ? setSpriteSheet(gcnew Bitmap("blobboLeft.bmp"), 1) : setSpriteSheet(gcnew Bitmap("blobboRight.bmp"), 1); 

		if(age > rGen->Next(LIFE_EXPECTANCY) && !dead && adult)
		{
			yPos+=20;
			setSpriteSheet(gcnew Bitmap("tombstone.bmp"), 1);
			dead = true;
			//scale = 90;
		}
	}